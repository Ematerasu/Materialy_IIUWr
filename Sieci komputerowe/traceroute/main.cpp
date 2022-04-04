// Dominik Budzki 314625
#include <stdint.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <netinet/ip.h>
#include <cassert>
#include <strings.h>
#include <string.h>
#include <vector>

typedef struct packet {
    char* ip;
    int id;
    int seqnum;
    int answer;
    long response_time;
} Packet;

Packet receive_packet(int socketfd, struct timeval tv) {
    struct sockaddr_in sender;
    socklen_t sender_len = sizeof(sender);
    uint8_t buffer[IP_MAXPACKET];

    char ip[20];

    ssize_t packet_len = recvfrom (
        socketfd,
        buffer,
        IP_MAXPACKET,
        0,
        (struct sockaddr*)&sender,
        &sender_len
    );
    if (packet_len < 0) {
        std::cerr<<("packet_len error\n");
        exit(1);
    }

    inet_ntop(AF_INET, &(sender.sin_addr), ip, sizeof(ip));
    
    struct iphdr* ip_header = (struct iphdr*) buffer;
    uint8_t* icmp_packet = buffer + 4 * ip_header->ihl;
    struct icmphdr* icmp_header = (struct icmphdr*)icmp_packet;

    if (icmp_header->type == ICMP_ECHOREPLY) {
        Packet result = {ip, icmp_header->un.echo.id, icmp_header->un.echo.sequence, 0, (1000000-tv.tv_usec)/1000};
        return result;

    }
    else if (icmp_header->type == ICMP_TIME_EXCEEDED) {
        icmp_packet += 8;
        icmp_packet += 4 *((struct ip*) icmp_packet)->ip_hl;
        struct icmp* icmp = (struct icmp*) icmp_packet;
        Packet result =  {ip, icmp->icmp_hun.ih_idseq.icd_id, icmp->icmp_hun.ih_idseq.icd_seq, 1, (1000000-tv.tv_usec)/1000};
        return result;
    }

    Packet result = {ip, 0, 0, 2, 0};
    return result;
}

int compute_icmp_checksum(const void *buff, int length) {
    uint32_t sum;
	const uint16_t* ptr = (uint16_t*)buff;
	assert (length % 2 == 0);
	for (sum = 0; length > 0; length -= 2)
		sum += *ptr++;
	sum = (sum >> 16) + (sum & 0xffff);
	return (uint16_t)(~(sum + (sum >> 16)));
}

void send_packets(char* ip, int socketfd, int pid, int seqnum) {
    struct sockaddr_in recipient;
    bzero(&recipient, sizeof(recipient));
    recipient.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &recipient.sin_addr);
    
    struct icmphdr header;
    header.type = ICMP_ECHO;
    header.code = 0;
    header.un.echo.id = pid;
    header.un.echo.sequence = seqnum;
    header.checksum = 0;
    header.checksum = compute_icmp_checksum((uint16_t*) &header, sizeof(header));

    ssize_t bytes_sent = sendto(
        socketfd,
        &header,
        sizeof(header),
        0,
        (struct sockaddr*) &recipient,
        sizeof(recipient)
    );

    if (bytes_sent <= 0) {
        std::cerr<<("Couldnt sent a packet!\n");
        exit(1);
    }
}

void print_packets(int ttl, std::vector<Packet> packets) {
    std::string ip = "";
    long time = 0;
    long correct_packets = 0;
    std::string prev_ip = "";
    for(long unsigned int i = 0; i < packets.size(); i++) {
        if (packets[i].answer != 2) {
            correct_packets++;
            time += packets[i].response_time;
            const char * c = prev_ip.c_str();
            if (strcmp(c, packets[i].ip) != 0){
                ip.append(packets[i].ip);
                ip.append(" ");
            }
            prev_ip.assign(packets[i].ip, 20);
        }
    }

    if (correct_packets == 0) {
        std::cout<<ttl<<". *"<<"\n";
    }
    else if (correct_packets == 3) {
        time /= 3;
        std::cout<<ttl<<". "<<ip<<" "<<time<<"ms\n";
    }
    else {
        std::cout<<ttl<<". "<<ip<<" ???"<<"\n";
    }
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr<<("Wrong number of arguments! Usage: sudo traceroute [ipv4]\n");
        return 1;
    }

    char* adres_ip = argv[1];

    // Sprawdzanie poprawności adresu ip
    struct sockaddr_in temp;
    if (inet_pton(AF_INET, adres_ip, &(temp.sin_addr)) != 1) {
        std::cerr<<("Wrong argument! Usage: sudo traceroute [ipv4 adress]\n");
        return 1;
    }

    // Tworzenie socketu
    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        std::cerr<<("Socket creation error, check if you used sudo\n");
        return 1;
    }

    int pid = getpid();
    bool finished = false;
    int seqnum = 0;
    std::vector<Packet> packets;
    fd_set descriptors;
    int ready = 0;
    struct timeval tv;

    for(int ttl = 1; ttl <= 30; ttl++) {
        setsockopt(socket_fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
        seqnum = 3*ttl;

        for(int i = 2; i >=0; i--) {
            send_packets(adres_ip, socket_fd, pid, seqnum-i);
        }

        FD_ZERO (&descriptors);
        FD_SET (socket_fd, &descriptors);
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        for (int i = 2; i >= 0; i--) {
            if ((ready = select(socket_fd+1, &descriptors, NULL, NULL, &tv)) < 0) {
                std::cerr<<("select error\n");
                return EXIT_FAILURE;
            }

            if (ready == 0) {
                break;
            }

            Packet packet = receive_packet(socket_fd, tv);

            if ((packet.id != pid || packet.seqnum != seqnum-i) && packet.answer != 2) {
                i++;
                continue;
            }
            else {
                packets.push_back(packet);
            }

            if (strcmp(packet.ip, adres_ip) == 0){
                finished = true;
            }
        }

        print_packets(ttl, packets);
        packets.clear();

        if (finished) {
            break;
        }
        
    }

    return 0;
}