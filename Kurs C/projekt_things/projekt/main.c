#include <stdio.h>
#include <stdlib.h>
#include "Projekt.h"
#include <gtk/gtk.h>
#include <string.h>
#include "fifo.h"

int main(int argc, char *argv[])
{
    for(int i=0;i<5;i++)
    {
        Statek[i]=(Okret*)malloc(sizeof(Okret));
        Statek[i]->Czy_zniszczony=true;
        Statek[i]->Dlugosc=i+1;
        Statek[i]->Szerokosc=1;
    }

    if ((Potoki=initPipes(argc,argv)) == NULL)
        return 1;
    if (argc == 2 && strcmp(argv[1],"A") == 0) { gracz2="B"; gracz1="A"; Tytul="Okrety, gracz A"; }
    else { gracz1="B"; gracz2="A"; Tytul="Okrety, gracz B";  }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            Plansza[i][j]=0;
        }
    }
    ilosc_statkow=0;

    PlanszaA_ready=false;
    PlanszaB_ready=false;

    for(int i=0; i<10; i++)
    {
        A[i]=(Pole*)malloc(sizeof(Pole));
        B[i]=(Pole*)malloc(sizeof(Pole));
        C[i]=(Pole*)malloc(sizeof(Pole));
        D[i]=(Pole*)malloc(sizeof(Pole));
        E[i]=(Pole*)malloc(sizeof(Pole));
        F[i]=(Pole*)malloc(sizeof(Pole));
        G[i]=(Pole*)malloc(sizeof(Pole));
        H[i]=(Pole*)malloc(sizeof(Pole));
        I[i]=(Pole*)malloc(sizeof(Pole));
        J[i]=(Pole*)malloc(sizeof(Pole));


        A[i]->PolozenieX=0+1;
        A[i]->PolozenieY=i+1;
        B[i]->PolozenieX=1+1;
        B[i]->PolozenieY=i+1;
        C[i]->PolozenieX=2+1;
        C[i]->PolozenieY=i+1;
        D[i]->PolozenieX=3+1;
        D[i]->PolozenieY=i+1;
        E[i]->PolozenieX=4+1;
        E[i]->PolozenieY=i+1;
        F[i]->PolozenieX=5+1;
        F[i]->PolozenieY=i+1;
        G[i]->PolozenieX=6+1;
        G[i]->PolozenieY=i+1;
        H[i]->PolozenieX=7+1;
        H[i]->PolozenieY=i+1;
        I[i]->PolozenieX=8+1;
        I[i]->PolozenieY=i+1;
        J[i]->PolozenieX=9+1;
        J[i]->PolozenieY=i+1;
    }

    gtk_init(&argc, &argv);

    activate1();

    gtk_main();

    return 0;
}
