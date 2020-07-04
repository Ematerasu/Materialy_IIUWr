#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Zadanie2.h"

//Dominik Budzki Lista6 Zadanie2 314625

int main()
{
    int n;

    printf("Jaki rozmiar danych przyjac?\n5000, 10000, 50000\nProsze wpisac odpowiednia liczbe: ");
    scanf("%d", &n);

    LicznikCzasu(Sortowanie, n);
    LicznikQCzasu(n);

    return 0;
}
