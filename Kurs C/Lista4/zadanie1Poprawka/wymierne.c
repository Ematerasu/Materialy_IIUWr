#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"

Liczba_Wymierna Wczytaj(void)
{
    int Licznik;
    int Mianownik;
    scanf("%d/%d", &Licznik, &Mianownik);
    Liczba_Wymierna x=Konstruuj(Licznik, Mianownik);
    return x;
}

Liczba_Wymierna Konstruuj(int Licznik , int Mianownik)
{
    if(Mianownik<0)
    {
        Mianownik*=-1;
        Licznik*=-1;
    }
    if(Mianownik==0)
    {
        printf("Blad\n");
        Mianownik=1;
    }
    int NWD=Licznik;
    int pomoc=Mianownik;
    if(NWD<0) NWD*=-1;
    while(NWD!=pomoc)
    {
        if(NWD<pomoc) pomoc=pomoc-NWD;
        else NWD=NWD-pomoc;
    }
    Licznik/=NWD;
    Mianownik/=NWD;

    Liczba_Wymierna x = Licznik;
    x=x<<32;
    x|=Mianownik;
    return x;
}
void czytajW(int Licznik, int Mianownik)
{
    printf("%d/%d\n", Licznik, Mianownik);
}
int KonwersjaLicznik(Liczba_Wymierna x)
{
    int wynik=0;

    wynik=x>>32;
    return wynik;
}
int KonwersjaMianownik(Liczba_Wymierna x)
{
    Liczba_Wymierna wynik=0;

    wynik=x<<32;
    wynik=wynik>>32;
    return wynik;
}


Liczba_Wymierna Dodawanie(Liczba_Wymierna x, Liczba_Wymierna y)
{
    int Licznik1=KonwersjaLicznik(x);
    int Mianownik1=KonwersjaMianownik(x);
    int Licznik2=KonwersjaLicznik(y);
    int Mianownik2=KonwersjaMianownik(y);
    int LicznikWynik;
    int MianownikWynik;

    if(Mianownik1!=Mianownik2)
    {
        int l, l2;
        l=Mianownik1;
        l2=Mianownik2;

        Mianownik1*=l2;
        Mianownik2*=l;

        Licznik1*=l;
        Licznik2*=l2;
    }
    LicznikWynik=Licznik1+Licznik2;
    MianownikWynik=Mianownik2;
    return Konstruuj(LicznikWynik, MianownikWynik);
}
Liczba_Wymierna Odejmowanie(Liczba_Wymierna x, Liczba_Wymierna y)
{
    int Licznik1=KonwersjaLicznik(x);
    int Mianownik1=KonwersjaMianownik(x);
    int Licznik2=KonwersjaLicznik(y);
    int Mianownik2=KonwersjaMianownik(y);
    int LicznikWynik;
    int MianownikWynik;

    if(Mianownik1!=Mianownik2)
    {
        int l, l2;
        l=Mianownik1;
        l2=Mianownik2;

        Mianownik1*=l2;
        Mianownik2*=l;

        Licznik1*=l;
        Licznik2*=l2;
    }
    LicznikWynik=Licznik2-Licznik1;
    MianownikWynik=Mianownik2;
    return Konstruuj(LicznikWynik, MianownikWynik);
}
Liczba_Wymierna Mnozenie(Liczba_Wymierna x, Liczba_Wymierna y)
{
    int Licznik1=KonwersjaLicznik(x);
    int Mianownik1=KonwersjaMianownik(x);
    int Licznik2=KonwersjaLicznik(y);
    int Mianownik2=KonwersjaMianownik(y);
    int LicznikWynik;
    int MianownikWynik;

    LicznikWynik=Licznik2*Licznik1;
    MianownikWynik=Mianownik2*Mianownik1;
    return Konstruuj(LicznikWynik, MianownikWynik);
}

Liczba_Wymierna Dzielenie(Liczba_Wymierna x, Liczba_Wymierna y)
{
    int Licznik1=KonwersjaLicznik(x);
    int Mianownik1=KonwersjaMianownik(x);
    int Licznik2=KonwersjaLicznik(y);
    int Mianownik2=KonwersjaMianownik(y);
    int LicznikWynik;
    int MianownikWynik;
    int l;
    l=Licznik2;
    Licznik2=Mianownik2;
    Mianownik2=l;

    LicznikWynik=Licznik2*Licznik1;
    MianownikWynik=Mianownik2*Mianownik1;
    return Konstruuj(LicznikWynik, MianownikWynik);
}

