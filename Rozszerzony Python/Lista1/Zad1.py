#### Zad 1 ####
from decimal import *

def vat_faktura(lista):
    return (sum(lista)*Decimal(0.23) if type(lista[0]) is Decimal else sum(lista)*0.23)


def vat(num):
    return (num*Decimal(0.23) if type(num) is Decimal else num*0.23)

def vat_paragon(lista):
    lista = list(map(vat, lista))
    return sum(lista)

zakupy = [0.2, 0.5, 4.59, 6]
print(vat_faktura(zakupy))
print(vat_paragon(zakupy))
print(vat_faktura(zakupy) == vat_paragon(zakupy))

zakupy = [Decimal(0.2), Decimal(0.5), Decimal(4.59), Decimal(6)]

getcontext().prec = 26 # Dla precyzji wiekszej niz 26 otrzymujemy False, nierownosc zachodzi na ostatniej cyfrze. Przy takiej precyzji wyniki sa rowne

print(vat_faktura(zakupy))
print(vat_paragon(zakupy))
print(vat_faktura(zakupy) == vat_paragon(zakupy))

