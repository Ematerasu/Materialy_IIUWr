#ifndef ZADANIE1_H_INCLUDED
#define ZADANIE1_H_INCLUDED
#include <stdlib.h>
#include <stdbool.h>

struct lista
{
    char* napis;
    struct lista *nastepny;
};

typedef struct Cykl_list
{
    struct lista *poczatek;
    struct lista *koniec;
}Cykliczna_lista;

Cykliczna_lista *nowa(void);
Cykliczna_lista *Dodaj_wartosc_poczatek(Cykliczna_lista *Cykl_list, char* napis);
Cykliczna_lista *Dodaj_wartosc_koniec(Cykliczna_lista *Cykl_list, char* napis);
Cykliczna_lista *Podaj_wartosc_poczatek(Cykliczna_lista *Cykl_list);
bool Czy_pusta(Cykliczna_lista *Cykl_list);
int Dlugosc_Listy(Cykliczna_lista *Cykl_list);
Cykliczna_lista *Usun_z_poczatku(Cykliczna_lista *Cykl_list);

#endif // ZADANIE1_H_INCLUDED
