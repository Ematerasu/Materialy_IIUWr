#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dominik Budzki Lista2 Zadanie1 314625

int main(int argc, char *argv[])
{
    int c;
    int win1250[18]={0xA5,0xC6,0xCA,0xA3,0xD1,0xD3,0x8C,0x8F,0xAF,0xB9,0xE6,0xEA,0xB3,0xF1,0xF3,0x9C,0x9F,0xBF};
    int utf2[18]={0x84,0x86,0x98,0x81,0x83,0x93,0x9A,0xB9,0xBB,0x85,0x87,0x99,0x82,0x84,0xB3,0x9B,0xBA,0xBC};
    int utf[18]={0xC4,0xC4,0xC4,0xC5,0xC5,0xC3,0xC5,0xC5,0xC5,0xC4,0xC4,0xC4,0xC5,0xC5,0xC3,0xC5,0xC5,0xC5};

    int sprawdz;

    if(argc <= 1){printf("Brak argumentow \n"); return 1;}

    if(strcmp(argv[1],"win2utf") == 0)
    {

    while((c=getchar())!=EOF)
    {
            sprawdz = 0;
            for(int i=0;i<18;i++)
            {
                if(c==win1250[i])
                {
                   putchar(utf[i]);
                   putchar(utf2[i]);
                   sprawdz = 1;
                   break;
                }
            }

            if(sprawdz == 0)
            {
                putchar(c);
            }
    }
    }

    if(strcmp(argv[1],"utf2win") == 0)
    {
        while((c=getchar())!=EOF)
    {
            sprawdz = 0;
            for(int i=0;i<18;i++)
            {
                if(c==utf[i])
                {
                        c=getchar();
                        for(int j=0;j<18;j++)
                        {
                            if(c==utf2[j])
                            {
                                putchar(win1250[j]);
                                sprawdz = 1;
                                break;
                            }
                        }
                    if(sprawdz == 1)
                    {
                        break;
                    }
                }

            }

            if(sprawdz == 0)
            {
                putchar(c);
            }
    }
    }

    return 0;
}
