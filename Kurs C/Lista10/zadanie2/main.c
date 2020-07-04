#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct katalog
{
    int liczba_podkatalogow;
    char *Nazwa_katalogu;
    struct katalog *nastepny[256];
    struct katalog *poprzedni;

} Katalog;

void pwd(Katalog *Drzewo_katalogow)
{
    if(Drzewo_katalogow->poprzedni==NULL)
        printf("/");
    else
    {
        pwd(Drzewo_katalogow->poprzedni);
        printf("%s", Drzewo_katalogow->Nazwa_katalogu);
        printf("/");
    }
}

Katalog mkdir(Katalog *Drzewo_katalogow)
{
    int c;
    char *tekst=malloc(sizeof(char)*256);
    int iterator=0;
    if(Drzewo_katalogow->liczba_podkatalogow<256)
    {
        while((c=getchar())!='\n')
        {
            tekst[iterator]=c;
            iterator++;
        }
        tekst[strlen(tekst)-1]='\0';
        for(int i=0; i<Drzewo_katalogow->liczba_podkatalogow; i++)
        {
            if(strcmp(tekst, Drzewo_katalogow->nastepny[i]->Nazwa_katalogu)==0)
                return *Drzewo_katalogow;
        }
        Drzewo_katalogow->liczba_podkatalogow+=1;
        Drzewo_katalogow->nastepny[Drzewo_katalogow->liczba_podkatalogow-1]=(Katalog*)malloc(sizeof(Katalog));


        Drzewo_katalogow->nastepny[Drzewo_katalogow->liczba_podkatalogow-1]->Nazwa_katalogu=tekst;
    }

    free(tekst);

    return *Drzewo_katalogow;
}

Katalog cd(Katalog *Drzewo_katalogow)
{
    int c;
    char *tekst=malloc(sizeof(char)*256);
    int iterator=0;

    while((c=getchar())!='\n')
    {
        tekst[iterator]=c;
        iterator++;
    }

    tekst[strlen(tekst)-1]='\0';

    if((strcmp(tekst,".."))==0 && Drzewo_katalogow->poprzedni!=NULL)
        Drzewo_katalogow=Drzewo_katalogow->poprzedni;
    else if(Drzewo_katalogow->liczba_podkatalogow>0)
    {
        for(int i=0; i<Drzewo_katalogow->liczba_podkatalogow; i++)
        {
            if((strcmp(tekst,Drzewo_katalogow->nastepny[i]->Nazwa_katalogu))==0)
            {
                Drzewo_katalogow=Drzewo_katalogow->nastepny[i];
                break;
            }

        }
    }
    free(tekst);

    return *Drzewo_katalogow;
}

Katalog Czytaj_funkcje(char *tekst, Katalog *Drzewo_katalogow)
{
    if(strcmp(tekst, "mkdir")==0)
    {
        *Drzewo_katalogow=mkdir(Drzewo_katalogow);
    }
    if(strcmp(tekst, "cd")==0)
        *Drzewo_katalogow=cd(Drzewo_katalogow);
    return *Drzewo_katalogow;
}

int main()
{
    int c;
    char *tekst=malloc(sizeof(char)*5);
    int iterator=0;
    Katalog *Drzewo_katalogow=(Katalog*)malloc(sizeof(Katalog));
    Drzewo_katalogow->poprzedni=NULL;
    Drzewo_katalogow->liczba_podkatalogow=0;

    for(int i=0;i<256;i++)
    {
        Drzewo_katalogow->nastepny[i]=NULL;
    }

    while((c=getchar())!='A')
    {
        if(c!=' ' || c!='\n')
        {
            tekst[iterator]=c;
            iterator++;
        }
        if(c==' ')
        {
            tekst[strlen(tekst)-1]='\0';
            *Drzewo_katalogow=Czytaj_funkcje(tekst, Drzewo_katalogow);
            iterator=0;
            free(tekst);
            tekst=malloc(sizeof(char)*256);
        }
        if(c=='B')
        {
            if(strcmp(tekst, "pwdB")==0) pwd(Drzewo_katalogow);
        }
    }

    free(tekst);
    return 0;
}
