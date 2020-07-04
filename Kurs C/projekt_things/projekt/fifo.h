#include <stdbool.h>
#include <gtk/gtk.h>

typedef struct pipes *PipesPtr;

PipesPtr initPipes(int argc, char *argv[]);
void     sendStringToPipe(PipesPtr channel, const char *data);
bool     getStringFromPipe(PipesPtr channel, char *buffer, size_t size);
void     closePipes(PipesPtr channel);
gboolean pobierz_tekst(gpointer data);
gboolean pobierz_Plansze(gpointer data);
