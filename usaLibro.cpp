#include "TADusaLibro.h"

void mostrarDatosLibro(tLibro &l) {
    char ISBN[11], titulo[MAX_TITULO];
    int añoPublicacion;

    obtenerISBN(l, ISBN);
    obtenerTitulo(l, titulo);
    añoPublicacion = obtenerAñoPublicacion(l);

    cout << "- " << ISBN << " | " << titulo << " | " << añoPublicacion << endl;
}

void leerDatosLibro(tLibro &l) {
    char ISBN[11], titulo[MAX_TITULO];
    int añoPublicacion;

    cout << "> Introduzca ISBN: " << endl;
    cin >> ISBN;

    cout << "> Introduzca titulo: " << endl;
    cin >> titulo;

    cout << "> Introduzca el año de publicacion: " << endl;
    cin >> añoPublicacion;

    crearLibro(l, ISBN, titulo, añoPublicacion);
}

void copiarDatosLibro(tLibro &l1, tLibro &l2) {
    char ISBN [11], titulo[MAX_TITULO];
    int añoPublicacion;

    obtenerISBN(l1, ISBN);
    obtenerTitulo(l1, titulo);
    añoPublicacion = obtenerAñoPublicacion(l1);

    crearLibro(l2, ISBN, titulo, añoPublicacion);
}
