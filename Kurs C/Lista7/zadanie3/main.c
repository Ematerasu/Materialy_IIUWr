#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m, n;
    int zapisn=0, zapism=0;
    int ilosc_sladow=0;
    scanf("%d %d", &m, &n);

    char **Plansza=malloc(sizeof(char*)*n);

    for(int i=0; i<n; i++)
    {
        Plansza[i]=malloc(sizeof(char)*m);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            scanf("%c",&Plansza[i][j]);
        }
    }

    int Legowiskox, legowiskoy;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(Plansza[i][j]=='L')
            {
                zapisn=i;
                zapism=j;
                Plansza[i][j]='.';
                Legowiskox=i;
                legowiskoy=j;
            }
            if(Plansza[i][j]=='S')
            {
                ilosc_sladow++;
            }
        }
    }
    if(ilosc_sladow==1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(Plansza[i][j]=='S')
                    Plansza[i][j]='.';

                if(Plansza[i][j]=='.')
                    Plansza[i][j]='X';

                printf("%c", Plansza[i][j]);
            }
        }
        exit(0);
    }

    int *Poszlaki=malloc(sizeof(int)*2);
    int drugie_max_x=0, drugie_max_y=0;
    zapisn=Legowiskox;
    zapism=legowiskoy;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(Plansza[i][j]=='S')
            {
                Poszlaki[0]=i;
                Poszlaki[1]=j;

                if(Legowiskox<Poszlaki[0])
                {
                    drugie_max_x=zapisn;
                    drugie_max_y=zapism;
                    zapisn=Poszlaki[0];
                    zapism=Poszlaki[1];
                }
                else
                {
                    drugie_max_x=zapisn;
                    drugie_max_y=zapism;
                    zapisn=Poszlaki[0];
                    zapism=Poszlaki[1];
                }
            }
        }
    }

    free(Poszlaki);

    printf("\n%d, %d\n", zapisn, zapism);
    printf("\n%d, %d\n", drugie_max_x, drugie_max_y);

    if(zapisn>drugie_max_x)
    {

        Plansza[zapisn][zapism]='X';
        for(int l=n-1; l>drugie_max_x; l--)
        {
            for(int z=0; z<=m; z++)
            {
                if(Plansza[l][z]=='.')
                    Plansza[l][z]='X';
            }
        }
    }
    else if(zapisn<drugie_max_x)
    {

        Plansza[zapisn][zapism]='X';

        for(int l=0; l<drugie_max_x; l++)
        {
            for(int z=0; z<=m; z++)
            {
                if(Plansza[l][z]=='.')
                    Plansza[l][z]='X';
            }
        }
    }
    else if(zapism<drugie_max_y)
    {

        Plansza[zapisn][drugie_max_y]='X';
        drugie_max_y++;

        while(Plansza[zapisn][drugie_max_y]!='S')
        {
            if(Plansza[zapisn][drugie_max_y]=='.')
                Plansza[zapisn][drugie_max_y]='X';
            drugie_max_y++;
        }
        Plansza[zapisn][drugie_max_y]='X';

    }
    else if(zapism>drugie_max_y)
    {
        Plansza[zapisn][zapism-1]='X';
        zapism--;

        while(Plansza[zapisn][zapism]!='S')
        {
            if(Plansza[zapisn][zapism]=='.')
                Plansza[zapisn][zapism]='X';
            zapism--;
        }
        Plansza[zapisn][zapism]='X';

    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(Plansza[i][j]=='S')
                Plansza[i][j]='.';

            printf("%c", Plansza[i][j]);
        }
    }
    //free(Poszlaki);

    return 0;
}
