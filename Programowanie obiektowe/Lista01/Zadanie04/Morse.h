#ifndef MORSE_H_INCLUDED
#define MORSE_H_INCLUDED


typedef struct m{
    char *morse_code;
    char litera;
    struct m *left;
    struct m *right;
} Morse;

Morse *init(void);
Morse *Dodaj(Morse *drzewo, char *znak);


#endif // MORSE_H_INCLUDED
