#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int Silnia(int n)
{
    if(n==1) return n;
    else return n*Silnia(n-1);
}

bool next_perm(int n, int p[n])
{
    if(n==0)
        return false;
    if(n==1)
        return false;

    if(!next_perm(n-1, p+1))
    {
        if(p[0]>p[1])
            return false;

        for(int i=n-1; i>=0; i--)
        {
            if(p[0]<p[i])
            {
                int c=p[0];
                p[0]=p[i];
                p[i]=c;
                break;
            }
        }

        for(int i=1; i<=n/2; i++)
        {
            int c=p[i];
            p[i]=p[n-i];
            p[n-i]=c;
        }
    }
    return true;
}

void Permutacje(int n, int p[n], int wynik[Silnia(n)][n])
{
    int iterator=0;
    do
    {
        if(iterator<Silnia(n))
        {
            for(int i=0;i<n;i++)
            {
                wynik[iterator][i]=p[i];
            }
            iterator++;
        }
        else return;

        for(int i=0;i<n;i++) printf("%d", p[i]);

        printf("\n");

    }while(next_perm(n, p));
}

void losowanie_permutacji(gpointer data)
{
    int *n=data;
    int wynik[*n];
    GtkWidget *Labels[*n][*n];

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"GTK-lista10");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 1);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 1);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);

    for(int i=0;i<*n;i++)
    {
        wynik[i]=i;
    }
    int Permutacja[Silnia(*n)][*n];
    Permutacje(*n, wynik, Permutacja);

    int i=rand()%Silnia(*n);

    for(int j=0;j<*n;j++)
    {
        wynik[j]=Permutacja[i][j];
    }

    for(int i=0; i<*n; i++)
    {
        for(int j=0; j<*n; j++)
        {
            if(wynik[i]==j)
            {
                Labels[i][j]=gtk_label_new("|  X ");
                gtk_grid_attach(GTK_GRID(grid), Labels[i][j], i, j, 1, 1);
            }
            else
            {
                Labels[i][j]=gtk_label_new("|    ");
                gtk_grid_attach(GTK_GRID(grid), Labels[i][j], i, j, 1, 1);
            }

        }
    }

    gtk_widget_show_all(window);
}

int main(int argc,char *argv[])
{
    gtk_init (&argc, &argv);

    if(argc<2)
    {
        printf("Blad, za mala liczba argumentow\n");
        printf("<nazwa> <liczba>");
        exit(1);
    }

    int n=atoi(argv[1]);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"GTK-lista10");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);/**<  */
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 1);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 1);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);

    GtkWidget *tekst = gtk_button_new_with_label("Next");

    int p[n];

    gtk_grid_attach(GTK_GRID(grid), tekst, 0, n+1, n, 1);

    for(int i=0;i<n;i++)
    {
        p[i]=i;
    }

    g_signal_connect(G_OBJECT(tekst), "clicked", G_CALLBACK(losowanie_permutacji),&n);

    GtkWidget *Labels[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p[i]==j)
            {
                Labels[i][j]=gtk_label_new("|  X ");
                gtk_grid_attach(GTK_GRID(grid), Labels[i][j], i, j, 1, 1);
            }
            else
            {
                Labels[i][j]=gtk_label_new("|    ");
                gtk_grid_attach(GTK_GRID(grid), Labels[i][j], i, j, 1, 1);
            }

        }
    }

    gtk_widget_show_all(window);

    gtk_main ();
    return 0;
}
