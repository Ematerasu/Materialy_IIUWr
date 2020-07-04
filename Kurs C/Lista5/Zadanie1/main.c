#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Dominik Budzki Lista5 Zadanie1 314625

bool next_perm(int n, int p[n])
{
    if(n==0) return false;
    if(n==1) return false;

    if(!next_perm(n-1, p+1))
    {
        if(p[0]>p[1]) return false;

        for(int i=n-1;i>=0;i--)
        {
            if(p[0]<p[i])
            {
                int c=p[0];
                p[0]=p[i];
                p[i]=c;
                break;
            }
        }

        for(int i=1;i<=n/2;i++)
        {
            int c=p[i];
            p[i]=p[n-i];
            p[n-i]=c;
        }
    }
    return true;
}

int main()
{
    int n;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);
    int p[n];

    for(int i=0;i<n;i++)
    {
        p[i]=i+1;
    }

    do
    {
        for(int i=0;i<n;i++) printf("%d, ", p[i]);
        printf("\n");

    }while(next_perm(n, p));

    return 0;
}
