#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void scanInt(int c, int n, char Obraz[n][n]);
void P1(int n, char Obraz[n][n]);
void Row(int n, char Obraz[n][n]);
void Snake(int n, char Obraz[n][n]);
void Diagonal(int n, char Obraz[n][n]);



int main()
{
    int n;
    int c;
    printf(".............\n");
    getchar();
    c=getchar();
    scanf("\n%d ", &n);
    getchar();

    char Obraz[n][n];

    scanInt(c, n, Obraz);

    Row(n, Obraz);
    Snake(n, Obraz);
    Diagonal(n, Obraz);
    return 0;
}

void scanInt(int c, int n, char Obraz[n][n])
{
    int ciag;
    char zmienna='0';
    if(c=='1')
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;)
            {
                c=getchar();
                if(c=='0' || c=='1')
                {
                    Obraz[i][j]=c;
                    j++;
                }
            }
        }
    }
    else if(c=='R')
    {
        int licznik=0;
        ciag=getchar();
        getchar();

        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;)
            {
                if(isdigit(ciag))
                {
                    if(licznik>=ciag)
                    {
                        ciag=getchar();
                        getchar();
                        licznik=0;
                        if(zmienna=='0') zmienna='1';
                        else zmienna='0';
                    }
                    else
                    {
                        Obraz[k][j]=zmienna;
                        licznik++;
                        j++;
                    }

                }
            }
        }
    }


    else if(c=='S')
    {

    }
    else if(c=='D')
    {

    }

}


void Row(int n, char Obraz[n][n])
{
    int dlugosc=1;
    if(Obraz[0][0]=='1') dlugosc++;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(Obraz[i][j]!=Obraz[i][j-1]) dlugosc++;

            if(j==n-1 && i<n-1)
            {
                if(Obraz[i][j]!=Obraz[i+1][0]) dlugosc++;

            }
        }
    }
    printf("%d ", dlugosc);
}

void Snake(int n, char Obraz[n][n])
{
    int dlugosc=1;
    int j;
    int lever=0;
    if(Obraz[0][0]=='1') dlugosc++;

    for(int i=0;i<n;i++)
    {
        j=0;
        while(lever==0)
        {
            if(j==n-1 && i<n-1)
            {
                if(Obraz[i+1][j]!=Obraz[i][j]) dlugosc++;
            }
            else if(Obraz[i][j+1]!=Obraz[i][j]) dlugosc++;

            j++;
            if(j==n) lever=1;
        }
        i++;
        while(lever==1)
        {
            if(j==0 && i<n-1)
            {
                if(Obraz[i][j]!=Obraz[i+1][j]) dlugosc++;
            }
            else if(Obraz[i][j-1]!=Obraz[i][j]) dlugosc++;

            j--;
            if(j==0) lever=0;


        }
    }
    printf("%d ", dlugosc-1);


}
void Diagonal(int n, char Obraz[n][n])
{
    int dlugosc=1;
    int i=0;
    int j=0;

    if(Obraz[0][0]=='1') dlugosc++;

    while(i<n-1)
    {
        if(Obraz[i][j+1]!=Obraz[i][j]) dlugosc++;
        j++;
        if(i==n-1) break;


        while(j>0)
        {
            if(Obraz[i+1][j-1]!=Obraz[i][j]) dlugosc++;
            i++;
            j--;
        }

        if(i==n-1) break;
        else i++;
        if(Obraz[i-1][j]!=Obraz[i][j]) dlugosc++;

        while(i>0)
        {
            if(Obraz[i-1][j+1]!=Obraz[i][j]) dlugosc++;
            i--;
            j++;
        }
    }

    while(i<n-1 || j<n-1)
    {
        if(Obraz[i][j+1]!=Obraz[i][j]) dlugosc++;
        j++;
        if(i==n-1 && j==n-1) break;

        while(j<n-1)
        {
            if(Obraz[i-1][j+1]!=Obraz[i][j]) dlugosc++;
            i--;
            j++;
        }

        if(i==n-1 && j==n-1) break;
        else i++;
        if(Obraz[i-1][j]!=Obraz[i][j]) dlugosc++;

        while(i<n-1)
        {
            if(Obraz[i+1][j-1]!=Obraz[i][j]) dlugosc++;
            j--;
            i++;
        }

    }
    printf("%d ", dlugosc);

}
