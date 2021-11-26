import math
import timeit

def isPrime(n:int) -> bool:
    bound = math.floor(math.sqrt(n))
    for i in range(2,bound+1):
        if n % i == 0:
            return False
    return True

def pierwsze_imperatywna(n:int) -> list:
    res = []
    for i in range(2,n):
        if isPrime(i):
            res.append(i)
    return res

def pierwsze_skladana(n:int) -> list:
    return [i for i in range(2,n) if isPrime(i)]

def pierwsze_funkcyjna(n:int) -> list:
    return list(filter(isPrime, range(2,n)))

if __name__ == "__main__":
    start = timeit.default_timer()
    print(pierwsze_imperatywna(1000))
    end = timeit.default_timer()
    print(f"Imperatywna: {end-start}")

    start = timeit.default_timer()
    print(pierwsze_skladana(1000))
    end = timeit.default_timer()
    print(f"Skladana: {end-start}")

    start = timeit.default_timer()
    print(pierwsze_funkcyjna(1000))
    end = timeit.default_timer()
    print(f"Funkcyjna: {end-start}")

# Najgorzej wypada wersja skladana, imperatywna i funkcyjna w miare rowno




