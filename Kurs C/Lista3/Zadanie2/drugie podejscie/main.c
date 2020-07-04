#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Dominik Budzki 314625 Lista2 Zadanie2

void Wczytaj(int x, int y, bool Obrazek[x][y])
{
    int c;
    for(int i=0;i<x;i++)
    {
        getchar();  //NADMIAR SPACJI USUWA
        for(int j=0;j<y;j++)
        {
            if((c=getchar())=='X') Obrazek[i][j]=true;
            else Obrazek[i][j]=false;
        }
    }
}

void Wypisz(int x, int y, bool Obrazek[x][y])
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
                if(Obrazek[i][j]) putchar('X');
                else putchar(' ');
        }
        printf("\n");
    }

}

void Obrot(int x, int y, bool Obrazek[x][y], bool Obrazek2[y][x], bool Obrazek3[x][y], int obrot)
{
    bool k;
    if(x==y)
    {
        if(obrot==90)
        {
        for(int i=0;i<x;i++)
        {
            for(int j=i;j<y-1-i;j++)
            {
                k=Obrazek[i][j];                //Gdy obrazek jest "kwadratem" to obracam go "koliscie" by zaoszczedzic pamiec i czas.
                Obrazek[i][j]=Obrazek[y-1-j][i];
                Obrazek[y-1-j][i] = Obrazek[y-1-i][y-1-j];
                Obrazek[y-1-i][y-1-j] = Obrazek[j][y-1-i];
                Obrazek[j][y-1-i] = k;
            }
        }
        Wypisz(x, y, Obrazek);
        }
        else if(obrot==180)
        {
        for(int p=0;p<2;p++) //2*90
        {
            for(int i=0;i<x;i++)
            {
                for(int j=i;j<y-1-i;j++)
                {
                    k=Obrazek[i][j];
                    Obrazek[i][j]=Obrazek[y-1-j][i];
                    Obrazek[y-1-j][i] = Obrazek[y-1-i][y-1-j];
                    Obrazek[y-1-i][y-1-j] = Obrazek[j][y-1-i];
                    Obrazek[j][y-1-i] = k;
                }
            }

        }
        Wypisz(x, y, Obrazek);
        }
        else if(obrot==270)
        {
        for(int p=0;p<3;p++) //3*90
        {
            for(int i=0;i<x;i++)
            {
                for(int j=i;j<y-1-i;j++)
                {
                    k=Obrazek[i][j];
                    Obrazek[i][j]=Obrazek[y-1-j][i];
                    Obrazek[y-1-j][i] = Obrazek[y-1-i][y-1-j];
                    Obrazek[y-1-i][y-1-j] = Obrazek[j][y-1-i];
                    Obrazek[j][y-1-i] = k;
                }
            }

        }
        Wypisz(x, y, Obrazek);
        }
        else
        {
        if(obrot!=0) printf("Obrot mozliwy tylko o 90, 180 lub 270 stopni!\n");
        Wypisz(x, y, Obrazek);

        }
    }
    else
    {
        if(obrot==90)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(Obrazek[i][j]) Obrazek2[j][x-1-i]=true;
                else Obrazek2[j][x-1-i]=false;
            }
        }
        Wypisz(y, x, Obrazek2);
    }
    else if(obrot==180)
    {
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<y;j++)
                {
                    if(Obrazek[i][j]) Obrazek3[x-1-i][j]=true;
                    else Obrazek3[x-1-i][j]=false;
                }
            }


        Wypisz(x, y, Obrazek3);
    }
    else if(obrot==270)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(Obrazek[i][j]) Obrazek2[y-1-j][i]=true;
                else Obrazek2[y-1-j][i]=false;
            }
        }

        Wypisz(y, x, Obrazek2);
    }
    else
    {
        if(obrot!=0) printf("Obrot mozliwy tylko o 90, 180 lub 270 stopni!\n");
        Wypisz(x, y, Obrazek);

    }
    }
}

int main()
{
    int x;
    int y;
    int obrot;
    printf("Podaj wymiary obrazka: \n");
    scanf("%d", &x);
    scanf("%d", &y);

    bool Obrazek[x][y];
    bool Obrazek2[y][x];
    bool Obrazek3[x][y];



    Wczytaj(x, y, Obrazek);
    printf("\n");
    Wypisz(x, y, Obrazek);
    printf("\n");
    printf("Obroc o ");
    scanf("%d", &obrot);
    printf(" stopni\n\n");
    Obrot(x, y, Obrazek, Obrazek2, Obrazek3, obrot);
    printf("\n");


    return 0;
}
