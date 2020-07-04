#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Znaki[64]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', ','};
    char Permutacja[64];
    int c;
    char Index[8]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char Macierz[8][8]={{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},{'B', 'C', 'D', 'E', 'F', 'G', 'H', 'A'},{'C', 'D', 'E', 'F', 'G', 'H', 'A', 'B'}, {'D', 'E', 'F', 'G', 'H','A', 'B', 'C'}, {'E', 'F', 'G', 'H','A', 'B', 'C', 'D'}, {'F', 'G', 'H','A', 'B', 'C', 'D', 'E'}, {'G', 'H','A', 'B', 'C', 'D', 'E', 'F'}, {'H','A', 'B', 'C', 'D', 'E', 'F','G'}};
    char klucz[256];
    char tekst[256];
    char wynik[256];


    if("encrypt\n")
    {
        while((c=getchar())!=EOF )
        {
                for(int i=0;i<64;i++)
                {

                    Permutacja[i]=Znaki[c];

                }
                getchar();

                for(int i=0;i<256 && (c=getchar())!=EOF;i++)
                {
                        if((klucz[i]=c)=='\n')
                        {
                            break;
                        }

                }
                for(int i=0;i<256 && (c=getchar())!=EOF;i++)
                {
                        if((tekst[i]=c)=='\n')
                        {
                            break;
                        }

                }

                if(strlen(tekst)!=strlen(klucz))
                {
                    if(strlen(tekst)>strlen(klucz))
                    {
                        for(int i=0;strlen(klucz)<strlen(tekst);i++)
                        {
                            klucz[strlen(klucz)+1+i]=klucz[i];

                        }

                    }
                }

        for(int k=0;k<strlen(tekst);k++)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    if(tekst[k]==Index[i] && klucz[k]==Index[j]) putchar(Macierz[i][j]);
                }
            }
        }
    }
    }
    if(strcmp(argv[1],"decrypt\n") == 0)
    {
        while((c=getchar())!=EOF )
        {

        }

    }

    return 0;
}
