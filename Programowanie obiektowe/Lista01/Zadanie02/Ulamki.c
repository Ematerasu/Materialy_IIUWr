#include <stdio.h>
#include <stdlib.h>
#include "Ulamki.h"
#include <math.h>

int NWD(int a, int b)
{
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

void skracanie(Ulamek *u)
{
    if(u->mianownik<0)
    {
        u->mianownik*=-1;
        u->licznik*=-1;

    }

    int nwd=NWD(fabs(u->licznik), u->mianownik);

    u->licznik/=nwd;
    u->mianownik/=nwd;
}

Ulamek *nowy_ulamek(int licznik, int mianownik)
{
    Ulamek *u;
    u=malloc(sizeof(Ulamek));

    if(mianownik==0)
    {
        printf("Mianownik rowny zero, blad!");
        return NULL;
    }

    u->licznik=licznik;
    u->mianownik=mianownik;

    skracanie(u);

    return u;
}
//Rozwiazanie na wskaznikach
Ulamek *dodaj_wsk(Ulamek *u1, Ulamek *u2)
{
    Ulamek *u=nowy_ulamek(u1->licznik*u2->mianownik + u2->licznik*u1->mianownik, u1->mianownik*u2->mianownik);
    return u;
}

Ulamek *odejmij_wsk(Ulamek *u1, Ulamek *u2)
{
    Ulamek *u=nowy_ulamek(u1->licznik*u2->mianownik - u2->licznik*u1->mianownik, u1->mianownik*u2->mianownik);
    return u;
}

Ulamek *mnozenie_wsk(Ulamek *u1, Ulamek *u2)
{
    Ulamek *u=nowy_ulamek(u1->licznik*u2->licznik, u1->mianownik*u2->mianownik);
    return u;
}

Ulamek *dzielenie_wsk(Ulamek *u1, Ulamek *u2)
{
    Ulamek *u=nowy_ulamek(u1->licznik*u2->mianownik, u1->mianownik*u2->licznik);
    return u;
}

//Rozwiazanie na modyfikacji drugiego argumentu


void dodaj_mod(Ulamek *u1, Ulamek *u2)
{
    u2->licznik=u1->licznik*u2->mianownik + u2->licznik*u1->mianownik;
    u2->mianownik=u1->mianownik*u2->mianownik;

    skracanie(u2);
}

void odejmij_mod(Ulamek *u1, Ulamek *u2)
{
    u2->licznik=u1->licznik*u2->mianownik - u2->licznik*u1->mianownik;
    u2->mianownik=u1->mianownik*u2->mianownik;

    skracanie(u2);
}

void mnozenie_mod(Ulamek *u1, Ulamek *u2)
{
    u2->licznik=u1->licznik*u2->licznik;
    u2->mianownik=u1->mianownik*u2->mianownik;

    skracanie(u2);
}

void dzielenie_mod(Ulamek *u1, Ulamek *u2)
{
    int temp;
    temp=u2->licznik;
    u2->licznik=u1->licznik*u2->mianownik;
    u2->mianownik=u1->mianownik*temp;
    skracanie(u2);
}
