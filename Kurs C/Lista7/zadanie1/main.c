#include <stdio.h>
#include <stdlib.h>
#include "zadanie1.h"
#include <string.h>

int main()
{
    char slowo[20];
    int x;
    int n=5;
    int dlugosc=0;
    char *p;
    Cykliczna_lista *Lista1;
    for(int i=0; i<n; i++)
    {
        printf("\n\n");
        printf("Co wykonac:\n1)Utworz nowa liste\n2)Dodaj wartosc na poczatek listy\n3)Dodaj wartosc na koniec listy\n4)Podaj wartosc z poczatku listy\n5)Usun i zwroc wartosc z poczatku lsity\n6)Sprawdz czy lista jest pusta\n7)Podaj dlugosc listy\n8)Zakoncz ");;
        scanf("%d", &x);

        switch(x)
        {
        case 1:
            Lista1=nowa();
            n++;
            break;
        case 2:
            scanf("%s", slowo);
            p=strdup(slowo);
            Dodaj_wartosc_poczatek(Lista1, p);
            n++;
            break;
        case 3:
            scanf("%s", slowo);
            p=strdup(slowo);
            Dodaj_wartosc_koniec(Lista1, p);
            n++;
            break;
        case 4:
            Podaj_wartosc_poczatek(Lista1);
            n++;
            break;
        case 5:
            Usun_z_poczatku(Lista1);
            n++;
            break;
        case 6:
            if(Czy_pusta(Lista1))
                printf("Pusta\n");
            else
                printf("Nie pusta\n");
            n++;
            break;
        case 7:
            dlugosc=Dlugosc_Listy(Lista1);
            printf("Dlugosc Listy: %d\n", dlugosc);
            n++;
            break;
        case 8:
            exit(1);
            break;
        }

    }



    return 0;
}
