
def solve(bits, D):
    bits = [int(bit) for bit in bits]
    minimum = len(bits)

    example = [1 for _ in range(D)] + [0 for _ in range(len(bits) - D)]

    for i in range(len(bits) - D + 1):
        cnt = 0
        for j in range(len(bits)):
            if example[j] != bits[j]:
                cnt += 1
        minimum = min(cnt, minimum)
        example = [0] + example[:-1]
    return minimum

def test():
    print("Test 1: ", solve('0010001000', 5) == 3) # 0011111000
    print("Test 2: ", solve('0010001000', 4) == 4) # 0011110000
    print("Test 3: ", solve('0010001000', 3) == 3) # 0011100000
    print("Test 4: ", solve('0010001000', 2) == 2) # 0011000000
    print("Test 5: ", solve('0010001000', 1) == 1) # 0010000000
    print("Test 6: ", solve('0010001000', 0) == 2) # 0000000000
    print("Test 7: ", solve('0010000000', 3) == 2) # 1110000000
    print("Test 8: ", solve('0010101000', 4) == 3) # 0011110000
    print("Test 9: ", solve('0000000000', 10) == 10) # 1111111111

if __name__ == "__main__":
    #test()
    input = open("zad4_input.txt", "r").read().split("\n")
    out = open("zad4_output.txt", "w").close()

    for line in input[:-1]:
        line = line.split(" ")
        result = solve(line[0], int(line[1]))
        f = open("zad4_output.txt", "a")
        f.write(f"{result}\n")
        f.close()
