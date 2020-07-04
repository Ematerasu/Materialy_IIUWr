#include <iostream>
#include "Wyrazenie.cpp"

using namespace std;

int main()
{
       Wyrazenie *w = new Odejmij(
        new pi(),
        new Dodaj(
            new liczba(2),
            new Mnozenie(
                new Zmienna("x"),
                new liczba(7)
                )
            )
        );
       Wyrazenie* test1 = new Dzielenie(new Mnozenie(new Odejmij(new Zmienna("x"),new liczba(1)), new Zmienna("x")), new liczba(2));
       Wyrazenie* test2 = new Dzielenie(new Dodaj(new liczba(3), new liczba(5)), new Dodaj(new liczba(2), new Mnozenie(new Zmienna("x"), new liczba(7))));
       Wyrazenie *test3 = new Dzielenie(new Cos(new Mnozenie(new Dodaj(new Zmienna("x"), new liczba(1)), new Zmienna("x"))), new Potega(new e(), new Potega(new Zmienna("x"), new liczba(2))));

    cout << w->opis() << "\n";

    cout << test1->opis() << "\n";
    cout << test2->opis() << "\n";
    cout << test3->opis() << "\n";


    return 0;
}
