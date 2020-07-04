#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//Dominik Budzki Lista8 Zadanie1 314625


typedef struct node
{
    bool czy_liczba;
    double liczba;
    char operacja;
    struct node *lewy;
    struct node *prawy;

} Node;

Node *nowy_lisc(double liczb)
{
    Node *lisc;
    if((lisc=(Node*)malloc(sizeof(Node)))== NULL)
    {
        printf("Brak pamieci");
        return NULL;
    }
    else
    {
        lisc->liczba=liczb;
        lisc->prawy=lisc->lewy=NULL;
        lisc->czy_liczba=true;
    }

    return lisc;
}

Node *nowa_operacja(char op, Node *lewy, Node *prawy)
{
    Node *drzewo;
    if((drzewo=(Node*)malloc(sizeof(Node)))== NULL)
    {
        printf("Brak pamieci");
        return NULL;
    }
    else
    {
            drzewo->operacja=op;
            drzewo->lewy=lewy;
            drzewo->prawy=prawy;
            drzewo->czy_liczba=false;
    }

    return drzewo;
}

Node *Wypisz_drzewo(Node *drzewo)
{
    if(drzewo->czy_liczba)
        printf("%0.0f", drzewo->liczba);

    else if((drzewo->lewy->czy_liczba==true) && (((drzewo->lewy->operacja=='+' || drzewo->lewy->operacja=='-') && (drzewo->operacja=='/' || drzewo->operacja=='*'))|| ((drzewo->prawy->operacja=='+' || drzewo->prawy->operacja=='-') && (drzewo->operacja=='/' || drzewo->operacja=='*'))))
    {
        Wypisz_drzewo(drzewo->lewy);
        printf("%c",drzewo->operacja);
        printf("( ");
        Wypisz_drzewo(drzewo->prawy);
        printf(" )");

    }
    else if((drzewo->prawy->czy_liczba==true) && (((drzewo->lewy->operacja=='+' || drzewo->lewy->operacja=='-') && (drzewo->operacja=='/' || drzewo->operacja=='*'))|| ((drzewo->prawy->operacja=='+' || drzewo->prawy->operacja=='-') && (drzewo->operacja=='/' || drzewo->operacja=='*'))))
    {
        printf("( ");
        Wypisz_drzewo(drzewo->lewy);
        printf(" )");
        printf("%c",drzewo->operacja);
        Wypisz_drzewo(drzewo->prawy);
    }
    else if(((drzewo->lewy->operacja=='+' || drzewo->lewy->operacja=='-') && (drzewo->operacja=='/' || drzewo->operacja=='*'))|| ((drzewo->prawy->operacja=='+' || drzewo->prawy->operacja=='-') && (drzewo->operacja=='/' || drzewo->operacja=='*')))
    {
        printf("( ");
        Wypisz_drzewo(drzewo->lewy);
        printf(" )");
        printf("%c",drzewo->operacja);
        printf("( ");
        Wypisz_drzewo(drzewo->prawy);
        printf(" )");
    }
    else
    {
        printf("( ");
        Wypisz_drzewo(drzewo->lewy);
        printf("%c",drzewo->operacja);
        Wypisz_drzewo(drzewo->prawy);
        printf(" )");
    }
    return 0;
}

int main()
{
    Node *stos[1000];
    int wierzcholek=0;
    char op;
    double liczba;
    while(true)
    {
        if((scanf(" %c", &op))==1)
        {
            if(isdigit(op))
            {
                ungetc(op, stdin);
                scanf("%lf", &liczba);
                stos[wierzcholek]=nowy_lisc(liczba);
                wierzcholek++;
            }
            else if(op!='=')
            {
                stos[wierzcholek-2]=nowa_operacja(op,stos[wierzcholek-2],stos[wierzcholek-1]);
                wierzcholek--;

            }
            else
                break;

        }
    }

    Wypisz_drzewo(stos[0]);
    free(stos[0]);

    return 0;
}
