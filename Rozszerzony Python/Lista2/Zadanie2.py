
def pierwiastek(n: int) -> int:
    if n < 1:
        return 0

    #Sprawdzamy dla którego "k" ze wzoru suma po lewej stronie bedzie wieksza niz k^2, wtedy zwracamy "k" - 1
    suma = 0
    i = 1
    while True:
        suma += 2*i - 1
        if suma > n:
            break
        i+=1
    return i-1

for i in range(1,101):
    print(f"n={i}, floor(sqrt(n))={pierwiastek(i)}")