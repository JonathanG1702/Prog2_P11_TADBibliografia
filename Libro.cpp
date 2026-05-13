#include <cstring>
#include <iostream>

using namespace std;

#include "TADLibro.h";

void crearLibro(tLibro &l, char ISBN[], char titulo[], int añoPublicacion) {
    strcpy(l.ISBN, ISBN);
    strcpy(l.titulo, titulo);
    l.añoPublicacion = añoPublicacion;
}

void modificarAñoPublicacion(tLibro &l, int nuevoAño) {
    l.añoPublicacion = nuevoAño;
}
void obtenerTitulo(tLibro &l, char titulo[MAX_TITULO]) {
    strcpy(titulo, l.titulo);
}

int obtenerAñoPublicacion(tLibro &l) {
    return l.añoPublicacion;
}

void obtenerISBN(tLibro &l, char ISBN[]) {
    strcpy(ISBN, l.ISBN);
}