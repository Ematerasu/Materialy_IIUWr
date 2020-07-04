#include <stdio.h>
#include <stdlib.h>
#include "zadanie1.h"
#include <stdbool.h>

Cykliczna_lista *nowa(void)
{
    Cykliczna_lista *p;

    if((p=(Cykliczna_lista *)malloc(sizeof(Cykliczna_lista)))==NULL)
        return NULL;
    else
    {
        p->poczatek=p->koniec=NULL;
        return p;
    }
}
Cykliczna_lista *Dodaj_wartosc_poczatek(Cykliczna_lista *Cykl_list, char* napis)
{
    struct lista *p;

    if ((p=(struct lista *)malloc(sizeof(struct lista))) == NULL)
    {
        printf("Nie udalo sie przypisac pamieci\n");
        exit(1);
    }
    else
    {
        p->napis=napis;
        p->nastepny=NULL;
        if(Cykl_list->poczatek==NULL)
            Cykl_list->poczatek=Cykl_list->koniec=p;
        else
            Cykl_list->koniec=Cykl_list->koniec->nastepny=p;

        return Cykl_list;
    }

}
Cykliczna_lista *Dodaj_wartosc_koniec(Cykliczna_lista *Cykl_list, char* napis)
{
    struct lista *p;

    if ((p=(struct lista *)malloc(sizeof(struct lista))) == NULL)
    {
        printf("Nie udalo sie przypisac pamieci\n");
        exit(1);
    }
    else
    {
        p->napis=napis;
        p->nastepny=NULL;
        if(Cykl_list->koniec==NULL)
            Cykl_list->koniec=Cykl_list->poczatek=p;
        else
            Cykl_list->poczatek=Cykl_list->poczatek->nastepny=p;

        return Cykl_list;
    }
}
Cykliczna_lista *Podaj_wartosc_poczatek(Cykliczna_lista *Cykl_list)
{
    printf("%s\n", Cykl_list->poczatek->napis);
    return 0;
}

bool Czy_pusta(Cykliczna_lista *Cykl_list)
{
    if(Cykl_list->poczatek==NULL && Cykl_list->koniec==NULL)
        return true;
    else
        return false;
}
Cykliczna_lista *Usun_z_poczatku(Cykliczna_lista *Cykl_list)
{
    Podaj_wartosc_poczatek(Cykl_list);
    Cykl_list->poczatek=NULL;
    free(Cykl_list->poczatek);
    return 0;
}
int Dlugosc_Listy(Cykliczna_lista *Cykl_list)
{
    int dlugosc=(Cykl_list->koniec)-(Cykl_list->poczatek);
    return dlugosc;
}
