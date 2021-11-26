from Zadanie1 import * #korzystam z funkcji na liczby pierwsze z zadania 1
import timeit


# Nie wykonywalem zadnych optymalizacji w wersji imperatywnej mimo ze jest na niq miejsce, dlatego ze w skladanej wersji i funkcyjnej ciezko o taka optymalizacje (przynajmniej ja nie wiem jak ja tam zmiescic)
# W takiej wersji sprawiedliwie mozna porownac czas wykonywania tych trzech funkcji


def foo(n:int, m:int) -> int: #pomocnicza funkcja podajaca ile razy mozna podzielic liczbe n przez m, nie umialem znalesc odpowiedniej nazwy ktora niebylaby za dluga wiec dalem foo
    i = 0
    while n % m == 0:
        i += 1
        n = n // m
    return i
        

def rozklad_imperatywna(n:int) -> list:
    res = []
    primes = pierwsze_skladana(n)
    for prime in primes:
        w = foo(n, prime)
        if w != 0:
            res.append((prime, w))
            n = n // prime**w
        
    return res

def rozklad_skladana(n:int) -> list:
    primes = pierwsze_funkcyjna(n)
    return [(prime, foo(n, prime)) for prime in primes if foo(n, prime) > 0]

def rozklad_funkcyjna(n:int) -> list:
    primes = pierwsze_imperatywna(n)
    return list(filter(lambda x: x is not None, 
                        map((lambda prime: (prime, foo(n,prime)) if foo(n,prime) else None), 
                            primes)))

if __name__ == "__main__":
    start = timeit.default_timer()
    print(rozklad_imperatywna(232352))
    end = timeit.default_timer()
    print(f"Imperatywna: {end-start}")

    start = timeit.default_timer()
    print(rozklad_skladana(232352))
    end = timeit.default_timer()
    print(f"Skladana: {end-start}")

    start = timeit.default_timer()
    print(rozklad_funkcyjna(232352))
    end = timeit.default_timer()
    print(f"Funkcyjna: {end-start}")

# Wyniki szczerze mowiac wahaja sie, kolejnosc zmienia sie co wywolanie, sa dosc bliskie sobie
