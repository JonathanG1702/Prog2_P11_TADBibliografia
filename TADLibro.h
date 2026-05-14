#ifndef P11_TADBIBLIOGRAFIA_TADLIBRO_H
#define P11_TADBIBLIOGRAFIA_TADLIBRO_H

#include <cstring>
#include <iostream>

using namespace std;

#include "TADLibro.h"

const int MAX_TITULO = 100;

struct tLibro {
    char ISBN [11];
    char titulo[MAX_TITULO];
    int añoPublicacion;
};

void crearLibro(tLibro &l, char ISBN[], char titulo[], int añoPublicacion);

void modificarAñoPublicacion(tLibro &l, int nuevoAño);
void obtenerTitulo(tLibro &l, char titulo[MAX_TITULO]);
int obtenerAñoPublicacion(tLibro &l);
void obtenerISBN(tLibro &l, char ISBN[]);

#endif //P11_TADBIBLIOGRAFIA_TADLIBRO_H
