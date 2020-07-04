#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Zadanie2.h"
#include <stdbool.h>

//Dominik Budzki Lista6 Zadanie2 314625


// Porównywacz potrzebna do qsort (https://stackoverflow.com/questions/34565028/cmpfunc-in-qsort-function-in-c)
int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void Generator(int n, double t[n])
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        t[i]=rand();
    }
}

bool czy_Poprawny(int n, int t[n], int t2[n])
{
    bool ok=true;
    for(int i=0; i<n; i++)
    {
        ok=true;
        for(int j=0; j<n; j++)
        {
            if(t[i]==t2[j])
                ok=false;
        }
        if(ok)
            return false;
    }

    for(int i=1; i<n; i++)
    {
        if(t2[i]<=t2[i-1])
            return false;
    }
    return true;
}

void Sortowanie(int n, double t[n])
{
    int x, k, p;
    for (k=1; k<n; k++)
    {
        x=t[k];
        p=k;
        while (p>0 && x<t[p-1])
        {
            t[p]=t[p-1];
            p--;
        }
        t[p]=x;
    }
}

void LicznikCzasu(void (*funkcja)(int, double*),int n)
{
    double srednia=0.0;
    double min=20.0;
    double max=0.0;
    double wynik;

    for(int i=0; i<100; i++)
    {
        double t[n];
        Generator(n, t);

        clock_t czas;
        czas=clock();
        (*funkcja)(n, t);
        czas=clock()-czas;
        wynik=((double)czas)/CLOCKS_PER_SEC;

        if(wynik<min)
            min=wynik;
        if(wynik>max)
            max=wynik;
        srednia=srednia+wynik;
    }
    srednia/=100;
    printf("Maksymalny czas mojego sortowanie: %0.6f\n", max);
    printf("Minimalny czas mojego sortowania: %0.6f\n", min);
    printf("Sredni czas mojego sortowania: %0.6f\n\n", srednia);


}
void LicznikQCzasu(int n)
{

    double min2=20.0;
    double max2=0;
    double srednia2=0;

    double wynik;
    for(int i=0; i<100; i++)
    {
        double t2[n];
        Generator(n, t2);

        clock_t czas;
        czas=clock();
        qsort(t2, n, sizeof(int), cmpfunc);
        czas=clock()-czas;
        wynik=((double)czas)/CLOCKS_PER_SEC;

        if(wynik>max2)
            max2=wynik;
        if(wynik<min2)
            min2=wynik;
        srednia2=srednia2+wynik;
    }
    srednia2/=100;

    printf("Maksymalny czas sortowania qsort: %0.6f\n", max2);
    printf("Minimalny czas sortowania qsort: %0.6f\n", min2);
    printf("Sredni czas sortowania qsort: %0.6f\n", srednia2);

}

