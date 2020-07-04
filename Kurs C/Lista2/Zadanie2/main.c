#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, m;
    char c;
    int dlugosc;
    char spacja=32;


    if(argc <= 1) {printf("Brak argumentow \n"); return 1;}
    sscanf(argv[1], "%d", &m);
    sscanf(argv[2], "%d", &n);

    for(int i=0;i<m;i++)
    {
        putchar(spacja);
        dlugosc=0;

        while((c=getchar())!=EOF)
        {
            if(c>65 && c<122)
            {
                putchar(c);
                dlugosc++;
            }
            else
            {
                dlugosc=0;

            }

            if(dlugosc>(n-m+1))
            {
                printf("Za dlugie slowo!\n");
                return 1;
            }
        }
    }






    return 0;
}
