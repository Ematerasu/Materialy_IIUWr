#ifndef PROJEKT_H_INCLUDED
#define PROJEKT_H_INCLUDED
#include <gtk/gtk.h>
#include <stdbool.h>
#include "fifo.h"

GtkWidget *Okno, *grid, *box, *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *a1, *b1, *c1, *d1, *e1, *f1, *g1, *h1, *i1, *j1, *Gracz1, *Gracz2;
char *gracz1, *gracz2;
int ilosc_statkow;
GtkWidget *Przycisk, *obrot, *Wiadomosc, *StatusGry, *Punktacja, *Odswiez, *PunkA, *PunkB, *Punksrednik;
char *Tytul, *tekst, *tekst2, *pom1, *pom2;
int temp;
bool Gracz1_move, PlanszaA_ready, PlanszaB_ready;
PipesPtr Potoki;
int PunktacjaA, PunktacjaB;

int lever;

int Plansza[10][10];
int UstawieniePrzeciwnika[10][10];


typedef struct Statek{
    int Dlugosc;
    int Szerokosc;
    bool Czy_zniszczony;
    int WspolrzednaX;
    int WspolrzednaY;
    GtkWidget *button;
} Okret;

Okret *Statek[5];

typedef struct pole{
    GtkWidget *button;
    int PolozenieX;
    int PolozenieY;

}Pole;


Pole *A[10];
Pole *B[10];
Pole *C[10];
Pole *D[10];
Pole *E[10];
Pole *F[10];
Pole *G[10];
Pole *H[10];
Pole *I[10];
Pole *J[10];


void activate1(void);
void RozpoczecieUstawianiaStatku(GtkWidget *button, gpointer user_data);
void ObrocStatek(GtkWidget *button);
void UstawienieStatku(GtkWidget *button, gpointer user_data);
void ZmianaGrida(void);
void ZmianaGrida2(void);
void RozpocznijRozgrywke(void);
void activate2(void);
void Strzal(GtkWidget *button, gpointer user_data);
void zakoncz(GtkWidget *widget, gpointer data);

#endif // PROJEKT_H_INCLUDED
