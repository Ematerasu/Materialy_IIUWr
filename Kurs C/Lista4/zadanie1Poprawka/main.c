#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
#include "wymierne.c"

int main()
{
    int Licznik;
    int Mianownik;
    Liczba_Wymierna x;
    Liczba_Wymierna y;
    Liczba_Wymierna Wynik_dodawania;
    Liczba_Wymierna Wynik_odejmowania;
    Liczba_Wymierna Wynik_mnozenia;
    Liczba_Wymierna Wynik_dzielenia;

    printf("Podaj dwie liczby wymierna w formacie n/m, gdzie n,m to liczby calkowite: \n");
    x=Wczytaj();
    y=Wczytaj();
    printf("\n");
    Licznik=KonwersjaLicznik(x);
    Mianownik=KonwersjaMianownik(x);
    czytajW(Licznik, Mianownik);

    printf("\n");

    Licznik=KonwersjaLicznik(y);
    Mianownik=KonwersjaMianownik(y);
    czytajW(Licznik, Mianownik);

    printf("\n");

    Wynik_dodawania=Dodawanie(x, y);
    Licznik=KonwersjaLicznik(Wynik_dodawania);
    Mianownik=KonwersjaMianownik(Wynik_dodawania);
    czytajW(Licznik, Mianownik);

    printf("\n");

    Wynik_odejmowania=Odejmowanie(x, y);
    Licznik=KonwersjaLicznik(Wynik_odejmowania);
    Mianownik=KonwersjaMianownik(Wynik_odejmowania);
    czytajW(Licznik, Mianownik);

    printf("\n");

    Wynik_mnozenia=Mnozenie(x, y);
    Licznik=KonwersjaLicznik(Wynik_mnozenia);
    Mianownik=KonwersjaMianownik(Wynik_mnozenia);
    czytajW(Licznik, Mianownik);

    printf("\n");

    Wynik_dzielenia=Dzielenie(x, y);
    Licznik=KonwersjaLicznik(Wynik_dzielenia);
    Mianownik=KonwersjaMianownik(Wynik_dzielenia);
    czytajW(Licznik, Mianownik);

    printf("\n");

    return 0;
}
