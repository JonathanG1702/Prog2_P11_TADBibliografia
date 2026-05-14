#ifndef P11_TADBIBLIOGRAFIA_TADUSABIBLIOGRAFIA_H
#define P11_TADBIBLIOGRAFIA_TADUSABIBLIOGRAFIA_H

#include "TADLibro.h"
#include "TADBibliografia.h"

using namespace std;

bool existe(tBibliografia b, char ISBN[]);
void modificarAñoLibro(tBibliografia &b, char ISBN[], int añoNuevo);
void masNuevo(tBibliografia b, tLibro &l);
void juntarBibliografias(tBibliografia b1, tBibliografia b2, tBibliografia &resultado);

#endif //P11_TADBIBLIOGRAFIA_TADUSABIBLIOGRAFIA_H
