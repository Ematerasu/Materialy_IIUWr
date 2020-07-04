#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

typedef enum typ {Kolo, Trojkat, Kwadrat} Typfig;

typedef struct fig
{
    Typfig typ;
    float x1, x2, x3, x4;
    float y1, y2, y3 ,y4;
    float promien; //w przypadku kola
}Figura;

Figura *Tab[5];

Figura *nowy_kwadrat(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
Figura *nowy_trojkat(float x1, float y1, float x2, float y2, float x3, float y3);
Figura *nowe_kolo(float x1, float y1, float r);

float dlugosc_boku(float x1, float y1, float x2, float y2);
float pole(Figura *f);
void przesun(Figura *f, float x, float y);
float sumapol(Figura *f, int size);
void Podsumowanie(int iter, Figura *f[]);
void WypisanieBledu(Figura *f);

#endif // FIGURA_H_INCLUDED
