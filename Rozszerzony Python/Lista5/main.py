from Formula import *

"""
    Dominik Budzki Lista 5 Zadanie 2

    Tutaj zakładam że przy uruchamianiu metody oblicz, podajemy słownik bez wcześniejszego deklarowania.
    Moim drugim pomyslem bylo dodanie statycznego slownika w klasie Variable ale wtedy argument "zmienne" w metodzie oblicz nie miałby bez sensu, a chcac
    trzymac sie tresci zadania zdecydowalem sie na taki system.
    Podobnie zaimplementował metode "tautologia" jest ona statyczna, podajemy jej formule oraz liste zmiennych znajdujacych sie w tej formule.

"""

if __name__ == "__main__":

    # Test podstawowy czy klasy dzialaja
    test1 = Or(Not(Variable("x")), And(Variable("y"), Const(True)))
    print(test1)
    print(test1.oblicz({"x":True, "y":False}))
    print(test1.oblicz({"x":False, "y":False}))
    print(test1.oblicz({"x":True, "y":True}))
    print(test1 + Variable("z"))
    print(test1 * Const(True))

    # Test tautologii
    print("-------------------")
    print(Formula.tautologia(test1, ["x","y"]))
    test2_tautology = Or(Variable("x"), Not(Variable("x")))
    print(test2_tautology)
    print(test2_tautology.oblicz({"x":True}))
    print(Formula.tautologia(test2_tautology,["x"]))

    # Test symplifikacji
    print("-------------------")
    test3_simplify = Or(Const(False), Variable("x"))
    print("test3 przed: " + str(test3_simplify))
    test3_simplify = simplify(test3_simplify)
    print("test3 po: " + str(test3_simplify))
    test4_simplify = And(Const(False), Variable("x"))
    print("test4 przed: " + str(test4_simplify))
    test4_simplify = simplify(test4_simplify)
    print("test4 po: " + str(test4_simplify))

    # Test wyjątków
    print("-------------------")
    try:
        test5_exception = Or(Variable("x"), Variable("y"))
        print(test5_exception.oblicz({"x":False}))
    except VariableNoValueError as v:
        print(v)
        print("Dziala :)")

