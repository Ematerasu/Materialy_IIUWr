#include <stdio.h>
#include <stdlib.h>
#include "Figura.h"
#include <math.h>

float dlugosc_boku(float x1, float y1, float x2, float y2)
{
    return(sqrt( (pow((x2-x1), 2) + (pow((y2-y1), 2))) ));

}

void WypisanieBledu(Figura *f)
{
    printf("Bledne dane!\n");
}

Figura *nowy_kwadrat(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    Figura *f;
    f=malloc(sizeof(Figura));

    f->typ=2;

    f->x1=x1;
    f->y1=y1;
    f->x2=x2;
    f->y2=y2;
    f->x3=x3;
    f->y3=y3;
    f->x4=x4;
    f->y4=y4;

    float a,b,c,d;
    a=dlugosc_boku(f->x1,f->y1,f->x2,f->y2);
    b=dlugosc_boku(f->x2,f->y2,f->x3,f->y3);
    c=dlugosc_boku(f->x3,f->y3,f->x4,f->y4);
    d=dlugosc_boku(f->x1,f->y1,f->x4,f->y4);

    if(a!=b || b!=c || c!=d || a!=d)
    {
        return NULL;
    }

    return f;
}

Figura *nowy_trojkat(float x1, float y1, float x2, float y2, float x3, float y3)
{
    Figura *f;
    f=malloc(sizeof(Figura));
    f->typ=1;

    f->x1=x1;
    f->y1=y1;
    f->x2=x2;
    f->y2=y2;
    f->x3=x3;
    f->y3=y3;


    float a,b,c;
    a=dlugosc_boku(f->x1, f->y1, f->x2, f->y2);
    b=dlugosc_boku(f->x2, f->y2, f->x3, f->y3);
    c=dlugosc_boku(f->x1, f->y1, f->x3, f->y3);

    if(a>=b+c || b>=a+c || c>=a+b)
    {
        return NULL;
    }

    return f;
}

Figura *nowe_kolo(float x1, float y1, float r)
{
    Figura *f;
    f=malloc(sizeof(Figura));
    f->typ=0;

    f->x1=x1;
    f->y1=y1;
    f->promien=r;

    if(r<0)
    {
        return NULL;
    }


    return f;
}

float pole(Figura *f)
{
    float p;
    float pi=3.141592653589;

    if(f->typ==Kolo)
    {
        p=pi*f->promien*f->promien;
    }
    else if(f->typ==Trojkat)
    {
        p=0.5* fabs((f->x2-f->x1)*(f->y3-f->y1) - (f->y2-f->y1)*(f->x3-f->x1));
    }
    else if(f->typ==Kwadrat)
    {
        p=dlugosc_boku(f->x1,f->y1,f->x2,f->y2)*dlugosc_boku(f->x1,f->y1,f->x2,f->y2);
    }

    return p;
}

void przesun(Figura *f, float x, float y)
{
    if(f->typ==Kolo)
    {
        f->x1+=x;
        f->y1+=y;
    }
    else if(f->typ==Trojkat)
    {
        f->x1+=x;
        f->y1+=y;
        f->x2+=x;
        f->y2+=y;
        f->x3+=x;
        f->y3+=y;
    }
    else if(f->typ==Kwadrat)
    {
        f->x1+=x;
        f->y1+=y;
        f->x2+=x;
        f->y2+=y;
        f->x3+=x;
        f->y3+=y;
        f->x4+=x;
        f->y4+=y;
    }

}

float sumapol(Figura *f, int size)
{
    float suma;

    for(int i=0; i<size; i++)
        suma+=pole(Tab[i]);

    return suma;
}

void Podsumowanie(int n, Figura *f[n])
{
    for(int i=0; i<n; i++)
    {
        if(f[i])
        {
        printf("\nTyp Figury: ");
        if(f[i]->typ==Kolo)
            printf("Kolo\n");
        else if(f[i]->typ==Trojkat)
            printf("Trojkat\n");
        else if(f[i]->typ==Kwadrat)
            printf("Kwadrat\n");

        printf("Pole figury: %f\n", pole(f[i]));

        printf("Wspolrzedne wierzcholkow: ");

        if(f[i]->typ==Kolo)
            printf("(%f, %f)\n",f[i]->x1, f[i]->y1);
        else if(f[i]->typ==Trojkat)
            printf("(%f, %f), (%f, %f), (%f, %f)\n",f[i]->x1, f[i]->y1, f[i]->x2, f[i]->y2, f[i]->x3, f[i]->y3);
        else if(f[i]->typ==Kwadrat)
            printf("(%f, %f), (%f, %f), (%f, %f), (%f, %f)\n",f[i]->x1, f[i]->y1, f[i]->x2, f[i]->y2, f[i]->x3, f[i]->y3, f[i]->x4, f[i]->y4);

        printf("Dotychczasowa suma pol: %f\n\n", sumapol(f[i], i+1));
        }
        else
        {
            WypisanieBledu(f[i]);
            printf("Dotychczasowa suma pol: %f\n\n", sumapol(f[i], i));
        }
    }
}
