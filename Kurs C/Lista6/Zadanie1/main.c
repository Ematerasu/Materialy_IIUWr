#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"
#include <stdbool.h>

//Dominik Budzki 314625 Lista6 Zadanie1

int main()
{
    Kolejka kp;
    int n;
    printf("Podaj dlugosc kolejki: ");
    scanf("%d", &n);
    double t[n+1];
    Initialize_Kol(kp, n+1, t);
    bool loop=true;
    double Liczba;
    int a;
    while(loop)
    {
        printf("Co zrobic?\n1)Oproznic kolejke\n2)Podac stan kolejki\n3)Dopisac wartosc na koniec kolejki\n4)Dopisac wartosc na poczatek kolejki\n5)Wziac wartosc z konca kolejki\n6)Wziac wartosci z poczatku kolejki\n7)Zakoncz program\n");
        scanf("%d", &a);
        printf("\n");
        switch(a)
        {
            case 1: {double t[n+1]; Oproznianie_kol(kp, n+1, t);}
            break;
            case 2: Stan_kolejki(kp, n);
            break;
            case 3:{printf("Podaj liczbe, ktora program ma dopisac na koniec kolejki: ");
            scanf("%lf", &Liczba);
            Dopisz_na_koniec(kp, Liczba);}
            break;
            case 4:{printf("Podaj liczbe, ktora program ma dopisac na poczatek kolejki: ");
            scanf("%lf", &Liczba);
            Dopisz_na_poczatku(kp, Liczba);}
            break;
            case 5:printf("%0.0lf\n", Koniec(kp));
            break;
            case 6:printf("%0.0lf\n", Poczatek(kp));
            break;
            case 7: loop=false;
            break;
        }
        printf("\n");
    }
    printf("Koniec.");
    return 0;
}
