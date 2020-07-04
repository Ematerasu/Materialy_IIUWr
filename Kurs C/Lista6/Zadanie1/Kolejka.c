#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"
#include <stdbool.h>

//Dominik Budzki 314625 Lista6 Zadanie1

/*
    kp[0]-start
    kp[1]-poczatek
    kp[2]-koniec
    kp[3]-finish
*/

void Initialize_Kol(Kolejka kp, int n, double t[n])
{
    kp[0]=kp[1]=kp[2]=t;
    kp[3]=t+n;
}
void Oproznianie_kol(Kolejka kp, int n, double t[n])
{
    kp[1]=kp[2]=t;
}
bool Czy_Pusta(Kolejka kp)
{
    if(kp[1]==kp[2]) return true;
    else return false;
}
bool Czy_Pelna(Kolejka kp)
{
    if(kp[0]==kp[1] && kp[2]+1==kp[3]) return true;
    else return false;
}
void Dopisz_na_koniec(Kolejka kp, double Liczba)
{
    if(Czy_Pelna(kp)) printf("Kolejka przepelniona\n");
    else if(kp[2]==kp[3])
    {
        kp[2]=kp[0];
       *kp[2]=Liczba;
        kp[2]+=1;

    }
    else
    {
        *kp[2]=Liczba;
        kp[2]+=1;
    }
}
void Dopisz_na_poczatku(Kolejka kp, double Liczba)
{
    if(Czy_Pelna(kp)) printf("Kolejka przepelniona\n");
    else
    {
        if(kp[1]!=kp[0])
        {
            kp[1]+=1;
            kp[2]+=1;
            *kp[1]=Liczba;
        }
        else Dopisz_na_koniec(kp, Liczba);
    }


}
double Poczatek(Kolejka kp)
{
    double Liczba=*kp[1];
    kp[1]+=1;
    return Liczba;
}
double Koniec(Kolejka kp)
{
    double Liczba=*kp[2];
    kp[2]-=1;
    return Liczba;
}
void Stan_kolejki(Kolejka kp, int n)
{
    ptrdiff_t Dystans =((kp[2])-(kp[1]));
    printf("Liczb w kolejce: %I64d\n", Dystans);
    if(Czy_Pelna(kp)) printf("Kolejka przepelniona\n");

    for(int j=0;j<n;j++)
    {
        printf("%0.0f", *(kp[1]+j));
    }
    printf("\n");

}
