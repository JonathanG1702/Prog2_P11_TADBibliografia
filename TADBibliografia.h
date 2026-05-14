#ifndef P11_TADBIBLIOGRAFIA_TADBIBLIOGRAFIA_H
#define P11_TADBIBLIOGRAFIA_TADBIBLIOGRAFIA_H

#include <cstring>

#include "TADLibro.h"
#include "TADBibliografia.h"
#include "TADusaLibro.h"

using namespace std;

struct Nodo {
    tLibro libro;
    Nodo *sig;
};

struct tBibliografia {
    Nodo *primero;
    int tam;
};

void iniciar(tBibliografia &b);
void añadir(tBibliografia &b, tLibro l);
void eliminar(tBibliografia &b, char ISBN[]);
void extraerISBN(tBibliografia b, char ISBN[], tLibro &l);
void extraerPosicion(tBibliografia b, int pos, tLibro &l);
bool bibliografiaSinLibros(tBibliografia b);
int numeroLibros(tBibliografia b);
void copiarBibliografia(tBibliografia b, tBibliografia &b1);
void mostrarBibliografia(tBibliografia b);
void cambiarTamañoBibliografia(tBibliografia &b, int nuevoTam);

#endif //P11_TADBIBLIOGRAFIA_TADBIBLIOGRAFIA_H
