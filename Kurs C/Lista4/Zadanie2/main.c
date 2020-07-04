#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
#include "wielomian.c"
#include <math.h>

//Dominik Budzki 314625 Lista4 Zadanie2


int main()
{
    int n1, n2;

    printf("Podaj jakiego stopnia ma byc wielomian: ");
    scanf("%d", &n1);
    Liczba_Wymierna Wielomian1[n1+1];

    printf("Podaj wspolczynnik wymierny (w postaci ulamku zwyklego) przy zmiennej \n");

    for(int i=0;i<=n1;i++)
    {
        printf("%d-ego stopnia ", i);
        Wielomian1[i]=Wczytaj();
    }

    printf("Podaj jakiego stopnia ma byc drugi wielomian: ");
    scanf("%d", &n2);

    Liczba_Wymierna Wielomian2[n2+1];
    Liczba_Wymierna WielomianWynik[n1+n2];


    printf("Podaj wspolczynnik wymierny (w postaci ulamku zwyklego) przy zmiennej \n");
    for(int i=0;i<=n2;i++)
    {
        printf("%d-ego stopnia ", i);
        Wielomian2[i]=Wczytaj();
    }
    int X;
    printf("Wykonac:\n1)Dodawanie\n2)Odejmowanie\n3)Mnozenie\n");
    scanf("%d", &X);

    switch(X)
    {
        case 1: Dodawanie_Wielomianu(n1, n2, Wielomian1, Wielomian2);
        break;
        case 2: Odejmowanie_Wielomianu(n1, n2, Wielomian1, Wielomian2);
        break;
        case 3: Mnozenie_Wielomianu(n1, n2, Wielomian1, Wielomian2, WielomianWynik);
        break;


    }



    return 0;
}
