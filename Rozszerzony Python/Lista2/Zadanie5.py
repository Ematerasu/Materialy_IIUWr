import requests

def kompresja(tekst: str) -> list:
    tekst = [char for char in tekst if char.isalnum() or ord(char) > 32]
    result = []
    licznik = 1
    n = len(tekst)
    for i in range(n):
        if i == n-1:
            result.append((licznik, tekst[i])) 
        elif tekst[i] == tekst[i+1]:
            licznik += 1
        else:
            result.append((licznik, tekst[i]))
            licznik = 1
    return result

def dekompresja(tekst: list) -> str:
    result = ""
    for pair in tekst:
        result += pair[0]*pair[1]
    return result

print(kompresja("aaaaa"))
print(dekompresja(kompresja("suuuuper")))

'''
url = 'https://www.gutenberg.org/files/1112/1112.txt' #Romeo i Julia w txt
r = requests.get(url)
tekst = r.text

print(kompresja(tekst))
print(dekompresja(kompresja(tekst)))
'''