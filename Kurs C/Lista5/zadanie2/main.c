#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool next_perm(int n, int wiersz[n])
{
    if(n==0) return false;
    if(n==1) return false;
    if(!next_perm(n-1, wiersz+1))
    {
        if(wiersz[0]>wiersz[1]) return false;

        for(int i=n-1;i>=0;i--)
        {
            if(wiersz[0]<wiersz[i])
            {
                int c=wiersz[0];
                wiersz[0]=wiersz[i];
                wiersz[i]=c;
                break;
            }
        }

        for(int i=1;i<=n/2;i++)
        {
            int c=wiersz[i];
            wiersz[i]=wiersz[n-i];
            wiersz[n-i]=c;
        }
    }
    return true;
}

void Poprawne(int n, int wiersz[n])
{
    int Hetman[n];

    if(next_perm(n, wiersz))
    {
        for(int i=0;i<n;i++)
        {
            Hetman[i]=wiersz[i];
        }

    }

    for(int i=0;i<n;i++)
        {
            printf("%d, ", Hetman[i]);
        }
        printf("\n");

}

int main()
{
    int n, k;
    printf("Podaj szerokosc szachownicy: ");
    scanf("%d", &n);
    printf("Podaj ilosc poprawnych ustawien ktore wygenerowac: ");
    scanf("%d", &k);
    int wiersz[n];

    printf("Wspolrzedne hetmanow ustawionych poprawnie: \n");
    for(int i=0;i<n;i++)
    {
        wiersz[i]=i+1;
        printf("%d, ", i+1);
    }

    printf("\n");

    while(k>0 && next_perm(n, wiersz))
    {
        Poprawne(n, wiersz);
        k--;
    }


    return 0;
}
