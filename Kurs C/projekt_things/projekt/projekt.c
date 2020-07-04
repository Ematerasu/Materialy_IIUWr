#include <stdio.h>
#include <stdlib.h>
#include "Projekt.h"
#include <gtk/gtk.h>
#include <string.h>
#include <unistd.h>
#include "fifo.h"


void activate1(void)
{
    Okno=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Okno),Tytul);
    g_signal_connect(G_OBJECT(Okno), "destroy",G_CALLBACK(zakoncz), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(Okno), 10);
    gtk_window_set_position(GTK_WINDOW(Okno),GTK_WIN_POS_CENTER);


    grid=gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    box=gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(Okno), box);
    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);

    a=gtk_label_new("A");
    gtk_grid_attach(GTK_GRID(grid), a, 0, 1, 1, 1);
    b=gtk_label_new("B");
    gtk_grid_attach(GTK_GRID(grid), b, 0, 2, 1, 1);
    c=gtk_label_new("C");
    gtk_grid_attach(GTK_GRID(grid), c, 0, 3, 1, 1);
    d=gtk_label_new("D");
    gtk_grid_attach(GTK_GRID(grid), d, 0, 4, 1, 1);
    e=gtk_label_new("E");
    gtk_grid_attach(GTK_GRID(grid), e, 0, 5, 1, 1);
    f=gtk_label_new("F");
    gtk_grid_attach(GTK_GRID(grid), f, 0, 6, 1, 1);
    g=gtk_label_new("G");
    gtk_grid_attach(GTK_GRID(grid), g, 0, 7, 1, 1);
    h=gtk_label_new("H");
    gtk_grid_attach(GTK_GRID(grid), h, 0, 8, 1, 1);
    i=gtk_label_new("I");
    gtk_grid_attach(GTK_GRID(grid), i, 0, 9, 1, 1);
    j=gtk_label_new("J");
    gtk_grid_attach(GTK_GRID(grid), j, 0, 10, 1, 1);

    a1=gtk_label_new("1");
    gtk_grid_attach(GTK_GRID(grid), a1, 1, 0, 1, 1);
    b1=gtk_label_new("2");
    gtk_grid_attach(GTK_GRID(grid), b1, 2, 0, 1, 1);
    c1=gtk_label_new("3");
    gtk_grid_attach(GTK_GRID(grid), c1, 3, 0, 1, 1);
    d1=gtk_label_new("4");
    gtk_grid_attach(GTK_GRID(grid), d1, 4, 0, 1, 1);
    e1=gtk_label_new("5");
    gtk_grid_attach(GTK_GRID(grid), e1, 5, 0, 1, 1);
    f1=gtk_label_new("6");
    gtk_grid_attach(GTK_GRID(grid), f1, 6, 0, 1, 1);
    g1=gtk_label_new("7");
    gtk_grid_attach(GTK_GRID(grid), g1, 7, 0, 1, 1);
    h1=gtk_label_new("8");
    gtk_grid_attach(GTK_GRID(grid), h1, 8, 0, 1, 1);
    i1=gtk_label_new("9");
    gtk_grid_attach(GTK_GRID(grid), i1, 9, 0, 1, 1);
    j1=gtk_label_new("10");
    gtk_grid_attach(GTK_GRID(grid), j1, 10, 0, 1, 1);

    for(int i=0; i<10; i++)
    {
        if(Plansza[0][i]==0)
        {
            A[i]->button=gtk_button_new_with_label("");
            g_signal_connect(A[i]->button,"clicked",G_CALLBACK(UstawienieStatku),A[i]);
        }
        else if(Plansza[0][i]==1)
        {
            A[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), A[i]->button, A[i]->PolozenieY, A[i]->PolozenieX, 1, 1);

        if(Plansza[1][i]==0)
        {
            B[i]->button=gtk_button_new_with_label("");
            g_signal_connect(B[i]->button,"clicked",G_CALLBACK(UstawienieStatku),B[i]);
        }
        else if(Plansza[1][i]==1)
        {
            B[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), B[i]->button, B[i]->PolozenieY, B[i]->PolozenieX, 1, 1);

        if(Plansza[2][i]==0)
        {
            C[i]->button=gtk_button_new_with_label("");
            g_signal_connect(C[i]->button,"clicked",G_CALLBACK(UstawienieStatku),C[i]);
        }
        else if(Plansza[2][i]==1)
        {
            C[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), C[i]->button, C[i]->PolozenieY, C[i]->PolozenieX, 1, 1);

        if(Plansza[3][i]==0)
        {
            D[i]->button=gtk_button_new_with_label("");
            g_signal_connect(D[i]->button,"clicked",G_CALLBACK(UstawienieStatku),D[i]);
        }
        else if(Plansza[3][i]==1)
        {
            D[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), D[i]->button, D[i]->PolozenieY, D[i]->PolozenieX, 1, 1);

        if(Plansza[4][i]==0)
        {
            E[i]->button=gtk_button_new_with_label("");
            g_signal_connect(E[i]->button,"clicked",G_CALLBACK(UstawienieStatku),E[i]);
        }
        else if(Plansza[4][i]==1)
        {
            E[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), E[i]->button, E[i]->PolozenieY, E[i]->PolozenieX, 1, 1);

        if(Plansza[5][i]==0)
        {
            F[i]->button=gtk_button_new_with_label("");
            g_signal_connect(F[i]->button,"clicked",G_CALLBACK(UstawienieStatku),F[i]);
        }
        else if(Plansza[5][i]==1)
        {
            F[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), F[i]->button, F[i]->PolozenieY, F[i]->PolozenieX, 1, 1);

        if(Plansza[6][i]==0)
        {
            G[i]->button=gtk_button_new_with_label("");
            g_signal_connect(G[i]->button,"clicked",G_CALLBACK(UstawienieStatku),G[i]);
        }
        else if(Plansza[6][i]==1)
        {
            G[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), G[i]->button, G[i]->PolozenieY, G[i]->PolozenieX, 1, 1);

        if(Plansza[7][i]==0)
        {
            H[i]->button=gtk_button_new_with_label("");
            g_signal_connect(H[i]->button,"clicked",G_CALLBACK(UstawienieStatku),H[i]);
        }
        else if(Plansza[7][i]==1)
        {
            H[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), H[i]->button, H[i]->PolozenieY, H[i]->PolozenieX, 1, 1);

        if(Plansza[8][i]==0)
        {
            I[i]->button=gtk_button_new_with_label("");
            g_signal_connect(I[i]->button,"clicked",G_CALLBACK(UstawienieStatku),I[i]);
        }
        else if(Plansza[8][i]==1)
        {
            I[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), I[i]->button, I[i]->PolozenieY, I[i]->PolozenieX, 1, 1);

        if(Plansza[9][i]==0)
        {
            J[i]->button=gtk_button_new_with_label("");
            g_signal_connect(J[i]->button,"clicked",G_CALLBACK(UstawienieStatku),J[i]);
        }
        else if(Plansza[9][i]==1)
        {
            J[i]->button=gtk_button_new_with_label("X");
        }
        gtk_grid_attach(GTK_GRID(grid), J[i]->button, J[i]->PolozenieY, J[i]->PolozenieX, 1, 1);

    }

    if(Statek[0]->Czy_zniszczony==true)
    {
        Statek[0]->button=gtk_button_new_with_label("X");
        g_signal_connect(Statek[0]->button, "clicked", G_CALLBACK(RozpoczecieUstawianiaStatku), Statek[0]);
        gtk_grid_attach(GTK_GRID(grid), Statek[0]->button, 1, 15, Statek[0]->Szerokosc, Statek[0]->Dlugosc);
    }

    if(Statek[1]->Czy_zniszczony==true)
    {
        Statek[1]->button=gtk_button_new_with_label("X\nX");
        g_signal_connect(Statek[1]->button, "clicked", G_CALLBACK(RozpoczecieUstawianiaStatku), Statek[1]);
        gtk_grid_attach(GTK_GRID(grid), Statek[1]->button, 2, 15, Statek[1]->Szerokosc, Statek[1]->Dlugosc);
    }

    if(Statek[2]->Czy_zniszczony==true)
    {
        Statek[2]->button=gtk_button_new_with_label("X\nX\nX");
        g_signal_connect(Statek[2]->button, "clicked", G_CALLBACK(RozpoczecieUstawianiaStatku), Statek[2]);
        gtk_grid_attach(GTK_GRID(grid), Statek[2]->button, 3, 15, Statek[2]->Szerokosc, Statek[2]->Dlugosc);
    }

    if(Statek[3]->Czy_zniszczony==true)
    {
        Statek[3]->button=gtk_button_new_with_label("X\nX\nX\nX");
        g_signal_connect(Statek[3]->button, "clicked", G_CALLBACK(RozpoczecieUstawianiaStatku), Statek[3]);
        gtk_grid_attach(GTK_GRID(grid), Statek[3]->button, 4, 15, Statek[3]->Szerokosc, Statek[3]->Dlugosc);
    }

    if(Statek[4]->Czy_zniszczony==true)
    {
        Statek[4]->button=gtk_button_new_with_label("X\nX\nX\nX\nX");
        g_signal_connect(Statek[4]->button, "clicked", G_CALLBACK(RozpoczecieUstawianiaStatku), Statek[4]);
        gtk_grid_attach(GTK_GRID(grid), Statek[4]->button, 5, 15, Statek[4]->Szerokosc, Statek[4]->Dlugosc);
    }

    obrot=gtk_button_new_with_label("Obroc o 90 stopni statek");
    g_signal_connect(obrot, "clicked", G_CALLBACK(ObrocStatek), NULL);
    gtk_grid_attach(GTK_GRID(grid), obrot, 7, 17, 1, 1);

    Wiadomosc=gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid),Wiadomosc, 9, 15, 1, 1);


    Przycisk=gtk_button_new_with_label("Zglos gotowosc");
    g_signal_connect(Przycisk, "clicked", G_CALLBACK(RozpocznijRozgrywke), NULL);
    gtk_grid_attach(GTK_GRID(grid), Przycisk, 10, 15, 1, 2);

    StatusGry=gtk_label_new("Przeciwnik nie jest gotowy!");
    gtk_grid_attach(GTK_GRID(grid), StatusGry, 10, 17, 1,2);

    g_timeout_add(100,pobierz_Plansze,NULL);

    gtk_widget_show_all(Okno);

}

void activate2(void)
{
    gtk_widget_destroy(grid);
    grid=gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);

    a=gtk_label_new("A");
    gtk_grid_attach(GTK_GRID(grid), a, 0, 1, 1, 1);
    b=gtk_label_new("B");
    gtk_grid_attach(GTK_GRID(grid), b, 0, 2, 1, 1);
    c=gtk_label_new("C");
    gtk_grid_attach(GTK_GRID(grid), c, 0, 3, 1, 1);
    d=gtk_label_new("D");
    gtk_grid_attach(GTK_GRID(grid), d, 0, 4, 1, 1);
    e=gtk_label_new("E");
    gtk_grid_attach(GTK_GRID(grid), e, 0, 5, 1, 1);
    f=gtk_label_new("F");
    gtk_grid_attach(GTK_GRID(grid), f, 0, 6, 1, 1);
    g=gtk_label_new("G");
    gtk_grid_attach(GTK_GRID(grid), g, 0, 7, 1, 1);
    h=gtk_label_new("H");
    gtk_grid_attach(GTK_GRID(grid), h, 0, 8, 1, 1);
    i=gtk_label_new("I");
    gtk_grid_attach(GTK_GRID(grid), i, 0, 9, 1, 1);
    j=gtk_label_new("J");
    gtk_grid_attach(GTK_GRID(grid), j, 0, 10, 1, 1);

    a1=gtk_label_new("1");
    gtk_grid_attach(GTK_GRID(grid), a1, 1, 0, 1, 1);
    b1=gtk_label_new("2");
    gtk_grid_attach(GTK_GRID(grid), b1, 2, 0, 1, 1);
    c1=gtk_label_new("3");
    gtk_grid_attach(GTK_GRID(grid), c1, 3, 0, 1, 1);
    d1=gtk_label_new("4");
    gtk_grid_attach(GTK_GRID(grid), d1, 4, 0, 1, 1);
    e1=gtk_label_new("5");
    gtk_grid_attach(GTK_GRID(grid), e1, 5, 0, 1, 1);
    f1=gtk_label_new("6");
    gtk_grid_attach(GTK_GRID(grid), f1, 6, 0, 1, 1);
    g1=gtk_label_new("7");
    gtk_grid_attach(GTK_GRID(grid), g1, 7, 0, 1, 1);
    h1=gtk_label_new("8");
    gtk_grid_attach(GTK_GRID(grid), h1, 8, 0, 1, 1);
    i1=gtk_label_new("9");
    gtk_grid_attach(GTK_GRID(grid), i1, 9, 0, 1, 1);
    j1=gtk_label_new("10");
    gtk_grid_attach(GTK_GRID(grid), j1, 10, 0, 1, 1);

    for(int i=0; i<10; i++)
    {
        A[i]->button=gtk_button_new_with_label("");
        g_signal_connect(A[i]->button,"clicked",G_CALLBACK(Strzal), A[i]);

        gtk_grid_attach(GTK_GRID(grid), A[i]->button, A[i]->PolozenieY, A[i]->PolozenieX, 1, 1);

        B[i]->button=gtk_button_new_with_label("");
        g_signal_connect(B[i]->button,"clicked",G_CALLBACK(Strzal),B[i]);

        gtk_grid_attach(GTK_GRID(grid), B[i]->button, B[i]->PolozenieY, B[i]->PolozenieX, 1, 1);

        C[i]->button=gtk_button_new_with_label("");
        g_signal_connect(C[i]->button,"clicked",G_CALLBACK(Strzal),C[i]);

        gtk_grid_attach(GTK_GRID(grid), C[i]->button, C[i]->PolozenieY, C[i]->PolozenieX, 1, 1);

        D[i]->button=gtk_button_new_with_label("");
        g_signal_connect(D[i]->button,"clicked",G_CALLBACK(Strzal),D[i]);

        gtk_grid_attach(GTK_GRID(grid), D[i]->button, D[i]->PolozenieY, D[i]->PolozenieX, 1, 1);

        E[i]->button=gtk_button_new_with_label("");
        g_signal_connect(E[i]->button,"clicked",G_CALLBACK(Strzal),E[i]);

        gtk_grid_attach(GTK_GRID(grid), E[i]->button, E[i]->PolozenieY, E[i]->PolozenieX, 1, 1);

        F[i]->button=gtk_button_new_with_label("");
        g_signal_connect(F[i]->button,"clicked",G_CALLBACK(Strzal),F[i]);

        gtk_grid_attach(GTK_GRID(grid), F[i]->button, F[i]->PolozenieY, F[i]->PolozenieX, 1, 1);

        G[i]->button=gtk_button_new_with_label("");
        g_signal_connect(G[i]->button,"clicked",G_CALLBACK(Strzal),G[i]);

        gtk_grid_attach(GTK_GRID(grid), G[i]->button, G[i]->PolozenieY, G[i]->PolozenieX, 1, 1);

        H[i]->button=gtk_button_new_with_label("");
        g_signal_connect(H[i]->button,"clicked",G_CALLBACK(Strzal),H[i]);

        gtk_grid_attach(GTK_GRID(grid), H[i]->button, H[i]->PolozenieY, H[i]->PolozenieX, 1, 1);

        I[i]->button=gtk_button_new_with_label("");
        g_signal_connect(I[i]->button,"clicked",G_CALLBACK(Strzal),I[i]);

        gtk_grid_attach(GTK_GRID(grid), I[i]->button, I[i]->PolozenieY, I[i]->PolozenieX, 1, 1);

        J[i]->button=gtk_button_new_with_label("");
        g_signal_connect(J[i]->button,"clicked",G_CALLBACK(Strzal),J[i]);

        gtk_grid_attach(GTK_GRID(grid), J[i]->button, J[i]->PolozenieY, J[i]->PolozenieX, 1, 1);
    }

    PunktacjaA=0;
    PunktacjaB=0;

    pom1=malloc(sizeof(char)*2);
    pom2=malloc(sizeof(char)*2);

    sprintf(pom1, "%d", PunktacjaA);
    sprintf(pom2, "%d", PunktacjaB);
    PunkA=gtk_label_new(pom1);
    PunkB=gtk_label_new(pom2);
    Punksrednik=gtk_label_new(":");

    free(Statek[0]);
    free(Statek[1]);
    free(Statek[2]);
    free(Statek[3]);
    free(Statek[4]);


    Gracz1=gtk_label_new("Gracz A");
    Gracz2=gtk_label_new("Gracz B");
    gtk_grid_attach(GTK_GRID(grid),Gracz1, 11, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid),Gracz2, 13, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid),PunkA, 11, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid),Punksrednik, 12, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid),PunkB, 13, 3, 1, 1);

    Odswiez=gtk_button_new_with_label("Odswiez");
    g_signal_connect(Odswiez,"clicked",G_CALLBACK(ZmianaGrida2),NULL);
    gtk_grid_attach(GTK_GRID(grid),Odswiez, 12, 1, 1, 1);

    if(Gracz1_move==true)
        tekst2="Twoj ruch";
    else
        tekst2="Ruch przeciwnika";
    Wiadomosc=gtk_label_new(tekst2);
    gtk_grid_attach(GTK_GRID(grid),Wiadomosc, 5, 17, 1, 1);

    StatusGry=gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid),StatusGry, 11, 5, 2, 1);

    g_timeout_add(100,pobierz_tekst,NULL);

    gtk_widget_show_all(Okno);

}

void ZmianaGrida(void)
{
    for(int i=0; i<10; i++)
    {
        if(Plansza[0][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(A[i]->button),"");
            g_signal_connect(A[i]->button,"clicked",G_CALLBACK(UstawienieStatku),A[i]);
        }
        else if(Plansza[0][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(A[i]->button),"X");
        }
        else if(Plansza[0][i]==2)
        {
            gtk_widget_hide(A[i]->button);
        }

        if(Plansza[1][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(B[i]->button),"");
            g_signal_connect(B[i]->button,"clicked",G_CALLBACK(UstawienieStatku),B[i]);
        }
        else if(Plansza[1][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(B[i]->button),"X");
        }
        else if(Plansza[1][i]==2)
        {
            gtk_widget_hide(B[i]->button);
        }

        if(Plansza[2][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(C[i]->button),"");
            g_signal_connect(C[i]->button,"clicked",G_CALLBACK(UstawienieStatku),C[i]);
        }
        else if(Plansza[2][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(C[i]->button),"X");
        }
        else if(Plansza[2][i]==2)
        {
            gtk_widget_hide(C[i]->button);
        }

        if(Plansza[3][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(D[i]->button),"");
            g_signal_connect(D[i]->button,"clicked",G_CALLBACK(UstawienieStatku),D[i]);
        }
        else if(Plansza[3][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(D[i]->button),"X");
        }
        else if(Plansza[3][i]==2)
        {
            gtk_widget_hide(D[i]->button);
        }

        if(Plansza[4][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(E[i]->button),"");
            g_signal_connect(E[i]->button,"clicked",G_CALLBACK(UstawienieStatku),E[i]);
        }
        else if(Plansza[4][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(E[i]->button),"X");
        }
        else if(Plansza[4][i]==2)
        {
            gtk_widget_hide(E[i]->button);
        }

        if(Plansza[5][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(F[i]->button),"");
            g_signal_connect(F[i]->button,"clicked",G_CALLBACK(UstawienieStatku),F[i]);
        }
        else if(Plansza[5][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(F[i]->button),"X");
        }
        else if(Plansza[5][i]==2)
        {
            gtk_widget_hide(F[i]->button);
        }

        if(Plansza[6][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(G[i]->button),"");
            g_signal_connect(G[i]->button,"clicked",G_CALLBACK(UstawienieStatku),G[i]);
        }
        else if(Plansza[6][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(G[i]->button),"X");
        }
        else if(Plansza[6][i]==2)
        {
            gtk_widget_hide(G[i]->button);
        }

        if(Plansza[7][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(H[i]->button),"");
            g_signal_connect(H[i]->button,"clicked",G_CALLBACK(UstawienieStatku),H[i]);
        }
        else if(Plansza[7][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(H[i]->button),"X");
        }
        else if(Plansza[7][i]==2)
        {
            gtk_widget_hide(H[i]->button);
        }

        if(Plansza[8][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(I[i]->button),"");
            g_signal_connect(I[i]->button,"clicked",G_CALLBACK(UstawienieStatku),I[i]);
        }
        else if(Plansza[8][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(I[i]->button),"X");
        }
        else if(Plansza[8][i]==2)
        {
            gtk_widget_hide(I[i]->button);
        }

        if(Plansza[9][i]==0)
        {
            gtk_button_set_label(GTK_BUTTON(J[i]->button),"");
            g_signal_connect(J[i]->button,"clicked",G_CALLBACK(UstawienieStatku),J[i]);
        }
        else if(Plansza[9][i]==1)
        {
            gtk_button_set_label(GTK_BUTTON(J[i]->button),"X");
        }
        else if(Plansza[9][i]==2)
        {
            gtk_widget_hide(J[i]->button);
        }

    }

}

void ZmianaGrida2(void)
{
    if(PunktacjaA<15 && PunktacjaB<15)
    {
        if(Gracz1_move==true)
            tekst2="Twoj ruch";
        else
            tekst2="Ruch przeciwnika";

    }
    else if(PunktacjaA==15 && PunktacjaB<15)
    {
        tekst2="Gracz A wygrywa!";
    }
    else if(PunktacjaB==15 && PunktacjaA<15)
    {
        tekst2="Gracz B wygrywa!";
    }
    sprintf(pom1, "%d", PunktacjaA);
    sprintf(pom2, "%d", PunktacjaB);
    gtk_label_set_label(GTK_LABEL(PunkA),pom1);
    gtk_label_set_label(GTK_LABEL(PunkB),pom2);

    gtk_label_set_label(GTK_LABEL(StatusGry),tekst);
    gtk_label_set_label(GTK_LABEL(Wiadomosc),tekst2);


}

void RozpoczecieUstawianiaStatku(GtkWidget *button, gpointer user_data)
{
    if(lever==0)
    {
        Okret *Statek=(Okret*)user_data;
        if(Statek->Czy_zniszczony)
        {
            gtk_button_set_label(GTK_BUTTON(button), "()");
            lever=Statek->Dlugosc;
            free(Statek);
        }
    }
}

void UstawienieStatku(GtkWidget *button, gpointer user_data)
{
    int x, y;

    Pole *pozycja=(Pole*)user_data;
    if(lever>0)
    {
        if(lever<6)
        {
            Statek[lever-1]->Czy_zniszczony=false;
            y=pozycja->PolozenieX-1;
            x=pozycja->PolozenieY-1;

            for(int i=1; i<lever; i++)
            {
                if(y+i>9)
                {
                    if(Plansza[y-lever+i][x]==2)
                    {
                        gtk_label_set_label(GTK_LABEL(Wiadomosc), "Nie mozna ustawic statku!");
                        Statek[lever-1]->Czy_zniszczony=true;
                        return;
                    }
                }
                else
                {
                    if(Plansza[y+i][x]==2)
                    {
                        gtk_label_set_label(GTK_LABEL(Wiadomosc), "Nie mozna ustawic statku!");
                        Statek[lever-1]->Czy_zniszczony=true;
                        return;
                    }

                }
            }

            gtk_label_set_label(GTK_LABEL(Wiadomosc),"");

            Plansza[y][x]=1;

            if(y-1>=0 && Plansza[y-1][x]!=1)
                Plansza[y-1][x]=2;
            if(x-1>=0 && Plansza[y][x-1]!=1)
                Plansza[y][x-1]=2;
            if(x+1<10 && Plansza[y][x+1]!=1)
                Plansza[y][x+1]=2;
            if(y+lever<10 && Plansza[y+lever][x]!=1)
                Plansza[y+lever][x]=2;

            for(int i=1; i<lever; i++)
            {
                if(y+i>9)
                {
                    Plansza[y-lever+i][x]=1;
                    if(x-1>=0 && Plansza[y-lever+i][x-1]!=1)
                        Plansza[y-lever+i][x-1]=2;
                    if(x+1<10 && Plansza[y-lever+i][x+1]!=1)
                        Plansza[y-lever+i][x+1]=2;
                    if((9-lever)>=0 && Plansza[9-lever][x]!=1)
                        Plansza[9-lever][x]=2;
                }
                else
                {
                    Plansza[y+i][x]=1;
                    if(x-1>=0)
                        Plansza[y+i][x-1]=2;
                    if(x+1<10)
                        Plansza[y+i][x+1]=2;
                }
            }

        }


        else if(lever>=6)
        {
            lever-=5;
            Statek[lever-1]->Czy_zniszczony=false;

            temp=Statek[lever-1]->Dlugosc;
            Statek[lever-1]->Dlugosc=Statek[lever-1]->Szerokosc;
            Statek[lever-1]->Szerokosc=temp;

            y=pozycja->PolozenieX-1;
            x=pozycja->PolozenieY-1;

            Plansza[y][x]=1;

            if(x-1>=0 && Plansza[y][x-1]!=1)
                Plansza[y][x-1]=2;
            if(x+lever<10 && Plansza[y][x+lever]!=1)
                Plansza[y][x+lever]=2;
            if(y-1>=0 && Plansza[y-1][x]!=1)
                Plansza[y-1][x]=2;
            if(y+1<10 && Plansza[y+1][x]!=1)
                Plansza[y+1][x]=2;

            if(x+lever<10 && Plansza[y][x+lever]!=1)
                Plansza[y][x+lever]=2;

            for(int i=1; i<lever; i++)
            {
                if(x+i>9)
                {
                    Plansza[y][x-lever+i]=1;
                    if(y-1>=0 && Plansza[y-1][x-lever+i]!=1)
                        Plansza[y-1][x-lever+i]=2;
                    if(y+1>=0 && Plansza[y+1][x-lever+i]!=1)
                        Plansza[y+1][x-lever+i]=2;
                    if(9-lever>=0 && Plansza[y][x-lever]!=1)
                        Plansza[y][9-lever]=2;

                }
                else
                {
                    Plansza[y][x+i]=1;
                    if(y-1>=0 && Plansza[y-1][x+i]!=1)
                        Plansza[y-1][x+i]=2;
                    if(y+1>=0 && Plansza[y+1][x+i]!=1)
                        Plansza[y+1][x+i]=2;

                }
            }


        }

        ZmianaGrida();

        lever=0;
        ilosc_statkow++;

    }
}

void ObrocStatek(GtkWidget *button)
{
    if(lever>0 && lever<6)
        lever+=5;
    else if(lever>=6)
        lever-=5;
}

void RozpocznijRozgrywke(void)
{
    char *Wspolrzedna;
    Wspolrzedna=malloc(sizeof(char)*102);

    int iterator=0;

    if(ilosc_statkow==5)
    {
        if(strcmp(gracz1,"A")==0)
        {
            Gracz1_move=true;
        }
        else if(strcmp(gracz1,"B")==0)
        {
            Gracz1_move=false;
        }

        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(Plansza[i][j]==1)
                {
                    Wspolrzedna[iterator]='1';
                    iterator++;
                }
                else
                {
                    Wspolrzedna[iterator]='0';
                    iterator++;
                }
            }
        }
        Wspolrzedna[iterator]='\n';
        Wspolrzedna[iterator+1]='\0';

        if(lever==0)
        {
            sendStringToPipe(Potoki, Wspolrzedna);
            lever=11;
        }

        if(strcmp(gracz1,"B")==0)
        {
            if(PlanszaA_ready)
            {
                PlanszaB_ready=true;
                activate2();
            }
            else
            {
                gtk_button_set_label(GTK_BUTTON(Przycisk),"Przejdz do gry,\njesli przeciwnik\njest gotowy");
            }
        }
        else if(strcmp(gracz1,"A")==0)
        {
            if(PlanszaB_ready)
            {
                PlanszaA_ready=true;
                activate2();
            }
            else
            {
                gtk_button_set_label(GTK_BUTTON(Przycisk),"Przejdz do gry,\njesli przeciwnik\njest gotowy");
            }
        }

    }
    else if(ilosc_statkow<5)
    {
        gtk_label_set_label(GTK_LABEL(Wiadomosc),"Uloz najpierw 5 statkow!");
    }
}

void Strzal(GtkWidget *button, gpointer user_data)
{
    if(Gracz1_move && PunktacjaA<15 && PunktacjaB<15 && PlanszaA_ready && PlanszaB_ready)
    {
        gint x, y;
        Pole *pozycja=(Pole*)user_data;
        y=pozycja->PolozenieX-1;
        x=pozycja->PolozenieY-1;

        if(UstawieniePrzeciwnika[y][x]==1)
        {
            gtk_button_set_label(GTK_BUTTON(button),"X");
            tekst="Trafiony!";
            UstawieniePrzeciwnika[y][x]=2;

            if(strcmp(gracz1,"A")==0)
                PunktacjaA+=1;
            else
                PunktacjaB+=1;

            sendStringToPipe(Potoki, "Punkt\n");
        }
        else if(UstawieniePrzeciwnika[y][x]==0)
        {
            tekst="Pudlo!";
            UstawieniePrzeciwnika[y][x]=3;
            gtk_button_set_label(GTK_BUTTON(button),"()");
            Gracz1_move=false;
            sendStringToPipe(Potoki, "Zmiana\n");
        }
        else if(UstawieniePrzeciwnika[y][x]==2 || UstawieniePrzeciwnika[y][x]==3 || UstawieniePrzeciwnika[y][x]==4 || UstawieniePrzeciwnika[y][x]==5)
        {
            tekst="Juz strzeliles w te pole!";
        }
    }
    else if(PlanszaA_ready==false)
    {
        tekst="Gracz A nie jest gotowy!";
    }
    else if(PlanszaB_ready==false)
    {
        tekst="Gracz B nie jest gotowy!";
    }
    ZmianaGrida2();
}
