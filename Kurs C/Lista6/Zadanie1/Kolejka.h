#ifndef KOLEJKA_H_INCLUDED
#define KOLEJKA_H_INCLUDED
#include <stdbool.h>

//Dominik Budzki 314625 Lista6 Zadanie1

typedef double *Kolejka[4];

void Initialize_Kol(Kolejka kp, int n, double t[n]);
void Oproznianie_kol(Kolejka kp, int n, double t[n]);
bool Czy_Pusta(Kolejka kp);
bool Czy_Pelna(Kolejka kp);
void Dopisz_na_koniec(Kolejka kp, double Liczba);
double Poczatek(Kolejka kp);
double Koniec(Kolejka kp);
void Stan_kolejki(Kolejka kp, int n);
void Dopisz_na_poczatku(Kolejka kp, double Liczba);

#endif // KOLEJKA_H_INCLUDED
