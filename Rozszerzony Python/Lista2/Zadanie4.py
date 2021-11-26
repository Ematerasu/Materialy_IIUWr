import random
import requests

def uprosc_zdanie(tekst: str, dl_slowa: int, liczba_slow: int):
    tekst = tekst.split(" ")
    tekst = [word for word in tekst if word != ""] #W przypadku tekstu z internetu, moga sie pojawiac dodatkowe spacje, takie np. sa w pliku Romeo i Julia, mozliwe ze mozna to zrobic sprytniej i szybciej
    nowy_tekst = []
    for slowo in tekst:
        if len(slowo) <= dl_slowa:
            nowy_tekst.append(slowo)
    
    while(liczba_slow < len(nowy_tekst)):
        nowy_tekst.pop(random.randint(0, len(nowy_tekst)-1))
    return " ".join(nowy_tekst)


tekst = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje sie sciana podziałowa inicjowana \
w płaszczyznie maksymalnej."

print(uprosc_zdanie(tekst, 10, 5))

'''

url = 'https://www.gutenberg.org/files/1112/1112.txt' #Romeo i Julia w txt
r = requests.get(url)
tekst = r.text
print(uprosc_zdanie(tekst, 5, 20)) #Zeby sprawdzic czy dobrze upraszcza
#print(uprosc_zdanie(tekst, 10, 1000)) #Sensowniejsze uzycie uproszczenia, przynajmniej mamy co czytac
'''