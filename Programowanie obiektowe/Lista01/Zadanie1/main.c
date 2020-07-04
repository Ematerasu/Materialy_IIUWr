#include <stdio.h>
#include <stdlib.h>
#include "Figura.c"

int main()
{
        int iter=0;

        Figura *f;

        f=nowe_kolo(1, 2, 3);
        Tab[iter]=f;
        iter++;

        f=nowy_kwadrat(0, 0, 1, 0, 1, 1, 0, 1);
        Tab[iter]=f;
        iter++;

        f=nowy_trojkat(0, 0, 5, 0, 0, 5);
        Tab[iter]=f;
        iter++;

        f=nowe_kolo(23, 43.12, 5.18);
        Tab[iter]=f;
        iter++;

        f=nowy_kwadrat(1, 1, 2, 2, 1, 2, 2, 1);
        Tab[iter]=f;
        iter++;


        Podsumowanie(iter, Tab);

    return 0;
}
