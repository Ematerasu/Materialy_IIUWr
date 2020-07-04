#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
#include <math.h>

//Dominik Budzki 314625 Lista4 Zadanie2

//Modul z poprzedniego zadania do ktorego dodalem nowe funkcje lub przerobilem stare na potrzebê tego zadania

Liczba_Wymierna Wczytaj(void)
{
    int Licznik;
    int Mianownik;
    scanf("%d/%d", &Licznik, &Mianownik);
    Liczba_Wymierna x=Konstruuj(Licznik, Mianownik);
    printf("\n");

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
        printf("Blad, nie mozna dzielic przez zero!\n");
        exit(1);
    }

    if(Licznik!=0)
    {
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


    }


    Liczba_Wymierna x = Licznik;
    x=x<<32;
    x|=Mianownik;
    return x;
}
void czytajW(int Licznik, int Mianownik, int p)
{
    if(p>1)
    {
        printf("+(%d/%d)x^%d", Licznik, Mianownik, p);
    }
    else if(p==1)
    {
        printf("(%d/%d)x", Licznik, Mianownik);
    }
    else if(p==0)
    {
        printf("(%d/%d)+", Licznik, Mianownik);
    }
    else
    {
        printf("%d/%d\n", Licznik, Mianownik);

    }
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

    LicznikWynik=Licznik1*Mianownik2+Licznik2*Mianownik1;
    MianownikWynik=Mianownik2*Mianownik1;

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
    LicznikWynik=Licznik1*Mianownik2-Licznik2*Mianownik1;
    MianownikWynik=Mianownik2*Mianownik1;
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

void Dodawanie_Wielomianu(int n1, int n2, Liczba_Wymierna Wielomian1[n1], Liczba_Wymierna Wielomian2[n2])
{
    printf("\n");
    printf("Wynik dodawania: \n");

    int Licznik, Mianownik;
    if(n1>n2)
    {

        for(int i=0;i<=n2;i++)
        {
            Wielomian1[i]=Dodawanie(Wielomian1[i], Wielomian2[i]);
        }
        for(int i=0;i<=n1;i++)
        {
            Licznik=KonwersjaLicznik(Wielomian1[i]);
            Mianownik=KonwersjaMianownik(Wielomian1[i]);
            czytajW(Licznik, Mianownik, i);
        }
        Wartosc_wielomianu(n1, Wielomian1);
    }
    else if(n1<n2)
    {

        for(int i=0;i<=n1;i++)
        {
            Wielomian2[i]=Dodawanie(Wielomian1[i], Wielomian2[i]);
        }
        for(int i=0;i<=n2;i++)
        {
            Licznik=KonwersjaLicznik(Wielomian2[i]);
            Mianownik=KonwersjaMianownik(Wielomian2[i]);
            czytajW(Licznik, Mianownik, i);
        }
        Wartosc_wielomianu(n2, Wielomian2);

    }
    else
    {
        for(int i=0;i<=n1;i++)
        {
            Wielomian2[i]=Dodawanie(Wielomian1[i], Wielomian2[i]);
        }
        for(int i=0;i<=n2;i++)
        {
            Licznik=KonwersjaLicznik(Wielomian2[i]);
            Mianownik=KonwersjaMianownik(Wielomian2[i]);
            czytajW(Licznik, Mianownik, i);
        }
        Wartosc_wielomianu(n2, Wielomian2);
    }
}

void Odejmowanie_Wielomianu(int n1, int n2, Liczba_Wymierna Wielomian1[n1], Liczba_Wymierna Wielomian2[n2])
{
    int Licznik, Mianownik;
    printf("\n");
    printf("Wynik odejmowania: \n");


    if(n1>n2)
    {

        for(int i=0;i<=n2;i++)
        {
            Wielomian1[i]=Odejmowanie(Wielomian1[i], Wielomian2[i]);
        }
        for(int i=0;i<=n1;i++)
        {
            Licznik=KonwersjaLicznik(Wielomian1[i]);
            Mianownik=KonwersjaMianownik(Wielomian1[i]);
            czytajW(Licznik, Mianownik, i);
        }
        Wartosc_wielomianu(n1, Wielomian1);
    }
    else if(n1<n2)
    {
        int j;
        for(int i=0;i<=n1;i++)
        {
            Wielomian2[i]=Odejmowanie(Wielomian1[i], Wielomian2[i]);
            j=i;
        }
        for(int i=0;i<=n1;i++)
        {
            Licznik=KonwersjaLicznik(Wielomian2[i]);
            Mianownik=KonwersjaMianownik(Wielomian2[i]);
            czytajW(Licznik, Mianownik, i);
        }
        for(int i=j+1;i<=n2;i++)
        {
            Licznik=(-1)*KonwersjaLicznik(Wielomian2[i]);
            Mianownik=KonwersjaMianownik(Wielomian2[i]);
            czytajW(Licznik, Mianownik, i);
        }
        Wartosc_wielomianu(n2, Wielomian2);
    }
    else
    {
        for(int i=0;i<=n1;i++)
        {
            Wielomian1[i]=Odejmowanie(Wielomian1[i], Wielomian2[i]);
        }
        for(int i=0;i<=n2;i++)
        {
            Licznik=KonwersjaLicznik(Wielomian1[i]);
            Mianownik=KonwersjaMianownik(Wielomian1[i]);
            czytajW(Licznik, Mianownik, i);
        }
        Wartosc_wielomianu(n2, Wielomian1);
    }
}
void Mnozenie_Wielomianu(int n1, int n2, Liczba_Wymierna Wielomian1[n1], Liczba_Wymierna Wielomian2[n2], Liczba_Wymierna WielomianWynik[n1+n2])
{
    printf("\n");
    printf("Wynik mnozenia: \n");
    for(int i=0;i<=n1+n2;i++)
    {
            WielomianWynik[i]=Konstruuj(0, 1);
    }
    int Licznik, Mianownik;

    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i!=0 || j!=0)
            {
                WielomianWynik[i+j]=Dodawanie(WielomianWynik[i+j], Mnozenie(Wielomian1[i], Wielomian2[j]));
            }
            else
            {
                WielomianWynik[i]=Mnozenie(Wielomian1[i], Wielomian2[j]);
            }
        }
    }

    for(int k=0;k<=n1+n2;k++)
    {
        Licznik=KonwersjaLicznik(WielomianWynik[k]);
        Mianownik=KonwersjaMianownik(WielomianWynik[k]);
        czytajW(Licznik, Mianownik, k);
    }
    Wartosc_wielomianu(n1+n2, WielomianWynik);

}

Liczba_Wymierna Potegowanie(Liczba_Wymierna Liczba, int Wykladnik)
{
    int Licznik, Mianownik;
    Licznik=KonwersjaLicznik(Liczba);
    Mianownik=KonwersjaMianownik(Liczba);
    Licznik=pow(Licznik, Wykladnik);
    Mianownik=pow(Mianownik, Wykladnik);
    Liczba_Wymierna Wynik=Konstruuj(Licznik, Mianownik);

    return Wynik;
}

void Wartosc_wielomianu(int n, Liczba_Wymierna Wielomian[n])
{
    printf("\nObliczyc wartosc tego wielomianu w punkcie: ");
    Liczba_Wymierna punkt=Wczytaj();

    Liczba_Wymierna Suma=Konstruuj(0, 1);

    for(int i=0; i<=n;i++)
    {

        Suma=Dodawanie(Suma, (Mnozenie(Wielomian[i], Potegowanie(punkt, i))));
    }

    int Licznik=KonwersjaLicznik(Suma);
    int Mianownik=KonwersjaMianownik(Suma);
    czytajW(Licznik, Mianownik, -1);
}


