#include <stdio.h>
#include <limits.h>
#include <math.h>

int Suma_dzielnikow(int a)
{
    int suma=1;

    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            if((a/i)!=i)
            {
                suma += i + a/i;
            }
            else suma += i;
        }
    }
    return suma;
}

int main()
{
    int s;
    scanf("%d", &s);
    int ok = 1;

    for(int i=s;i<INT_MAX;i++)
    {
        if((i+1)==Suma_dzielnikow(Suma_dzielnikow(i+1)))
        {
            if(i+1<Suma_dzielnikow(i+1))
            {
                 printf("%d %d\n", i+1, Suma_dzielnikow(i+1));
                 ok = 0;
                 break;
            }
        }
    }
    if(ok == 1) printf("BRAK\n");

    return 0;
}

