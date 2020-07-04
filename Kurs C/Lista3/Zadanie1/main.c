#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


//Lista3 Zadanie1 Dominik Budzki 314625 bez mnozenia

#define MAX 1002

void scanInt(int n, char Liczba[n]);
void convert(const char Liczba[], char inum[]);
void wypisz(char wynik[]);
void dodawanie(const char inum[], const char inum2[], char wynik[]);
void odejmowanie(const char inum[], const char inum2[], char wynik[]);




int main()
{
    char Tab[MAX];
    char inum[MAX];
    char Tab2[MAX];
    char inum2[MAX];
    char wynik[MAX];
    int lever;

   printf("Podaj liczbe:\n");

    scanInt(MAX, Tab);
    scanInt(MAX, Tab2);
    convert(Tab, inum);
    convert(Tab2, inum2);
    printf("%s\n", Tab);
    printf("%s\n", Tab2);
    wypisz(inum);
    wypisz(inum2);
    printf("Wykonac\n 1)dodawanie,\n 2)odejmowanie?\n");
    scanf("%d", &lever);

    switch(lever)
    {
        case 1: dodawanie(inum, inum2, wynik);
        break;
        case 2: odejmowanie(inum, inum2, wynik);
        break;
        default: printf("Blad!");
    }

    wypisz(wynik);




    return 0;
}

void scanInt(int n, char Liczba[n])
{
    int k=1;
    int c;
    while((c=getchar())!=EOF)
    {
        if(c!=' ' && c!='\t' && c!='\n') break;
    }

    if(c=='-') Liczba[0]='-';
    else
    {
        Liczba[0]='+';
        Liczba[1]=c;
        k++;
    }
    c=getchar();
    while(isdigit(c) && c!=EOF )
    {
        Liczba[k]=c;
        c=getchar();
        k++;
    }

    Liczba[k]='\0';
    return true;
}

void convert(const char Liczba[], char inum[])
{
    if(Liczba[0]=='-') inum[0]='1';
    else inum[0]='0';

    int dlugosc=1;

    while(Liczba[dlugosc]!='\0')
    {
        dlugosc++;
    }

    dlugosc--;
    inum[1]=dlugosc+'0';
    int x;

    for(int k=2;k<=dlugosc+1;k++)
    {
        inum[k]=Liczba[dlugosc-k+2];
        x=k;
    }
    inum[x+1]='\0';
}

void wypisz(char wynik[])
{
    for(int i=0;wynik[i]!='\0';i++) putchar(wynik[i]);

    printf("\n");

}

void dodawanie(const char inum[], const char inum2[], char wynik[])
{
    int cyfra1, cyfra2;
    int suma;
    int zaliczka=0;
    bool sprawdz=false;

    if(inum[0]==inum2[0])
    {
    if(inum[1]>inum2[1])
    {
        wynik[0]=inum[0];
        wynik[1]=inum[1];
        for(int i=2;inum[i]!='\0';i++)
        {
            cyfra1=inum[i]-'0';
            if(inum2[i]=='\0' || sprawdz)
            {
                cyfra2=0;
                sprawdz=true;
                wynik[i]=inum[i];
            }
            else
            {
                cyfra2=inum2[i]-'0';
                suma=cyfra1+cyfra2+zaliczka;

                if(suma>9)
                {
                    wynik[i]=(suma%10)+'0';
                    zaliczka=1;
                }
                else
                {
                    wynik[i]=suma+'0';
                    zaliczka=0;
                }
            }

        }

    }
    else if(inum[1]<inum2[1])
    {
        wynik[0]=inum2[0];
        wynik[1]=inum2[1];
        for(int i=2;inum2[i]!='\0';i++)
        {
            cyfra1=inum2[i]-'0';
            if(inum[i]=='\0' || sprawdz)
            {
                cyfra2=0;
                sprawdz=true;
                wynik[i]=inum2[i];
            }
            else
            {
                cyfra2=inum[i]-'0';
                suma=cyfra1+cyfra2+zaliczka;

                if(suma>9)
                {
                    wynik[i]=(suma%10)+'0';
                    zaliczka=1;
                }
                else
                {
                    wynik[i]=suma+'0';
                    zaliczka=0;
                }
            }

        }
    }
    else
    {
        wynik[0]=inum2[0];
        wynik[1]=inum2[1];

        for(int i=2;inum[i]!='\0';i++)
        {
            cyfra1=inum[i]-'0';
            cyfra2=inum2[i]-'0';

            suma=cyfra1+cyfra2+zaliczka;

            if(suma>9)
            {
                wynik[i]=(suma%10)+'0';
                zaliczka=1;
                if(inum[i+1]=='\0')
                {
                    wynik[i+1]=zaliczka+'0';
                    wynik[1]++;
                }
            }
            else
            {
                wynik[i]=suma+'0';
                zaliczka=0;
            }



        }
    }
    }
    else
    {
        char zapas[MAX];
        for(int i=0;inum2[i]!=EOF;i++) zapas[i]=inum2[i];

        zapas[0]='0';

        odejmowanie(inum, zapas, wynik);
    }
}

void odejmowanie(const char inum[], const char inum2[], char wynik[])
{
    int cyfra1, cyfra2;
    int suma;
    int zaliczka=0;
    bool sprawdz=false;
    int x;


    if(inum[1]>inum2[1])
    {
        wynik[0]=inum[0];
        wynik[1]=inum[1];
        for(int i=2;inum[i]!='\0';i++)
        {
            cyfra1=inum[i]-'0';
            if(inum2[i]=='\0' || sprawdz)
            {
                cyfra2=0;
                sprawdz=true;
            }
            else
            {
                cyfra2=inum2[i]-'0';
                suma=cyfra1-cyfra2-zaliczka;

                if(suma<0)
                {
                    wynik[i]=(suma+10)+'0';
                    zaliczka=1;
                }
                else
                {
                    wynik[i]=suma+'0';
                    zaliczka=0;
                }
            }
            if(sprawdz)
            {
                suma=cyfra1-cyfra2-zaliczka;

                if(suma<0)
                {
                    wynik[i]=(suma+10)+'0';
                    zaliczka=1;
                }
                else
                {
                    wynik[i]=suma+'0';
                    zaliczka=0;
                }

            }
        x=i+1;
        }
        wynik[x]='\0';
    }
    else if(inum[1]<inum2[1])
    {
        wynik[0]=inum2[0];
        wynik[1]=inum2[1];
        for(int i=2;inum2[i]!='\0';i++)
        {
            cyfra1=inum2[i]-'0';
            if(inum[i]=='\0' || sprawdz)
            {
                cyfra2=0;
                sprawdz=true;
                wynik[i]=inum2[i];
            }
            else
            {
                cyfra2=inum[i]-'0';
                suma=cyfra1-cyfra2-zaliczka;

                if(suma<0)
                {
                    wynik[i]=(suma+10)+'0';
                    zaliczka=1;
                }
                else
                {
                    wynik[i]=suma+'0';
                    zaliczka=0;
                }
            }
            if(sprawdz)
            {
                suma=cyfra1-cyfra2-zaliczka;

                if(suma<0)
                {
                    wynik[i]=(suma+10)+'0';
                    zaliczka=1;
                }
                else
                {
                    wynik[i]=suma+'0';
                    zaliczka=0;
                }

            }

        x=i+1;
        }
        wynik[x]='\0';
    }
    else
    {
        wynik[0]=inum2[0];
        wynik[1]=inum2[1];

        for(int i=2;inum[i]!='\0';i++)
        {
            cyfra1=inum[i]-'0';
            cyfra2=inum2[i]-'0';

            suma=cyfra1-cyfra2-zaliczka;

            if(suma<0)
            {
                wynik[i]=(suma+10)+'0';
                zaliczka=1;
                if(inum[i+1]=='\0')
                {
                    wynik[i+1]=zaliczka+'0';
                    wynik[1]++;
                }
            }
            else
            {
                wynik[i]=suma+'0';
                zaliczka=0;
            }
        x=i+1;
        }
        wynik[x]='\0';
    }
}




