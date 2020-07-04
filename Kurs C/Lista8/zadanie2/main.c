#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    bool czy_spacja;
    bool czy_plus_lub_gwiazdka;
    bool otwierajacy_nawias;
    bool zamykajacy_nawias;
    char znak;
    struct node *lewy;
    struct node *prawy;
} Node;

Node *nowy_lisc(char znak)
{
    Node *lisc;
    if((lisc=(Node*)malloc(sizeof(Node)))== NULL)
    {
        printf("Brak pamieci");
        return NULL;
    }
    else
    {
        if(znak==32)
        {
            lisc->czy_spacja=true;
            lisc->czy_plus_lub_gwiazdka=false;
            lisc->otwierajacy_nawias=false;
            lisc->zamykajacy_nawias=false;
            lisc->znak=znak;
            lisc->lewy=lisc->prawy=NULL;
        }
        else if(znak==40)
        {
            lisc->czy_spacja=false;
            lisc->czy_plus_lub_gwiazdka=false;
            lisc->otwierajacy_nawias=true;
            lisc->zamykajacy_nawias=false;
            lisc->znak=znak;
            lisc->lewy=lisc->prawy=NULL;
        }
        else if(znak==41)
        {
            lisc->czy_spacja=false;
            lisc->czy_plus_lub_gwiazdka=false;
            lisc->otwierajacy_nawias=false;
            lisc->zamykajacy_nawias=true;
            lisc->znak=znak;
            lisc->lewy=lisc->prawy=NULL;
        }
        else if(znak==42)
        {
            lisc->czy_spacja=false;
            lisc->czy_plus_lub_gwiazdka=true;
            lisc->otwierajacy_nawias=false;
            lisc->zamykajacy_nawias=false;
            lisc->znak=znak;
            lisc->lewy=lisc->prawy=NULL;
        }
        else if(znak==43)
        {
            lisc->czy_spacja=false;
            lisc->czy_plus_lub_gwiazdka=true;
            lisc->otwierajacy_nawias=false;
            lisc->zamykajacy_nawias=false;
            lisc->znak=znak;
            lisc->lewy=lisc->prawy=NULL;
        }
        else
        {
            lisc->czy_spacja=false;
            lisc->czy_plus_lub_gwiazdka=false;
            lisc->otwierajacy_nawias=false;
            lisc->zamykajacy_nawias=false;
            lisc->znak=znak;
            lisc->lewy=lisc->prawy=NULL;
        }
    }
    return lisc;
}

Node *nowy_wezel(char znak, Node *lewy, Node *prawy)
{
    Node *drzewo;
    if((drzewo=(Node*)malloc(sizeof(Node)))== NULL)
    {
        printf("Brak pamieci");
        return NULL;
    }
    else
    {
        if(znak==32)
        {
            drzewo->czy_spacja=true;
            drzewo->czy_plus_lub_gwiazdka=false;
            drzewo->otwierajacy_nawias=false;
            drzewo->zamykajacy_nawias=false;
            drzewo->znak=znak;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
        }
        else if(znak==40)
        {
            drzewo->czy_spacja=false;
            drzewo->czy_plus_lub_gwiazdka=false;
            drzewo->otwierajacy_nawias=true;
            drzewo->zamykajacy_nawias=false;
            drzewo->znak=znak;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
        }
        else if(znak==41)
        {
            drzewo->czy_spacja=false;
            drzewo->czy_plus_lub_gwiazdka=false;
            drzewo->otwierajacy_nawias=false;
            drzewo->zamykajacy_nawias=true;
            drzewo->znak=znak;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
        }
        else if(znak==42)
        {
            drzewo->czy_spacja=false;
            drzewo->czy_plus_lub_gwiazdka=true;
            drzewo->otwierajacy_nawias=false;
            drzewo->zamykajacy_nawias=false;
            drzewo->znak=znak;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
        }
        else if(znak==43)
        {
            drzewo->czy_spacja=false;
            drzewo->czy_plus_lub_gwiazdka=true;
            drzewo->otwierajacy_nawias=false;
            drzewo->zamykajacy_nawias=false;
            drzewo->znak=znak;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
        }
        else
        {
            drzewo->czy_spacja=false;
            drzewo->czy_plus_lub_gwiazdka=false;
            drzewo->otwierajacy_nawias=false;
            drzewo->zamykajacy_nawias=false;
            drzewo->znak=znak;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
        }
    }
    return drzewo;
}

Node *Wypisz_drzewo(Node *drzewo)
{
    /*if(drzewo->czy_spacja)
    {
        Wypisz_drzewo(drzewo->lewy);
        Wypisz_drzewo(drzewo->prawy);
    }
    else if(drzewo->lewy->otwierajacy_nawias && drzewo->prawy->czy_plus_lub_gwiazdka)
    {
        Wypisz_drzewo(drzewo->prawy);
        printf("%c",drzewo->znak);
    }
    else if(drzewo->lewy->czy_spacja &&  drzewo->zamykajacy_nawias)
    {
        drzewo->lewy->znak='(';
        drzewo->lewy->czy_spacja=false;
        drzewo->lewy->otwierajacy_nawias=true;
        Wypisz_drzewo(drzewo->lewy);
        printf("%c", drzewo->znak);
        Wypisz_drzewo(drzewo->prawy);
    }
    else
    {
        Wypisz_drzewo(drzewo->lewy);
        printf("%c", drzewo->znak);
        Wypisz_drzewo(drzewo->lewy);
    }*/
    Wypisz_drzewo(drzewo->lewy);
    printf("%c",drzewo->znak);
    Wypisz_drzewo(drzewo->prawy);

    return 0;
}

int main()
{
    Node *stos[1000];
    int wierzcholek=0;
    char *wyrazenie=malloc(sizeof(char)*10000);

    wyrazenie=fgets(wyrazenie, 10000, stdin);

    //printf("%c", wyrazenie[3]);
    for(unsigned int i=0;i<strlen(wyrazenie)-1;i++)
    {
        if(i!=0 && i%2!=0)
        {
            stos[wierzcholek]=nowy_lisc(wyrazenie[i]);
            wierzcholek++;
        }
        else
        {
            stos[wierzcholek-2]=nowy_wezel(wyrazenie[i],stos[wierzcholek-2],stos[wierzcholek-1]);
            wierzcholek--;
        }
    }


    Wypisz_drzewo(stos[0]);
    free(stos[0]);
    free(wyrazenie);

    return 0;
}
