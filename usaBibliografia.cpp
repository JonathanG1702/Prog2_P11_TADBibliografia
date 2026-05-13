#include "TADLibro.h"
#include "Libro.cpp"
#include "usaLibro.cpp"
#include "TADBibliografia.h"

using namespace std;

bool existe(tBibliografia b, char ISBN[]) {
    tLibro l;

    char ISBNLeido[11];
    bool encontrado = false, parar = false;
    int cont = 0, comp;
    int cantLibros = numeroLibros(b);

    while (!parar && !encontrado && cont <= cantLibros) {
        extraerPosicion(b, cont, l);
        obtenerISBN(l, ISBNLeido);

        comp = strcmp(ISBNLeido, ISBN);
        if (comp > 0) {
            parar = true;
        } else if (comp == 0) {
            encontrado = true;
        } else {
            cont++;
        }
    }

    return encontrado;
}

void modificarAñoLibro(tBibliografia &b, char ISBN[], int año) {
    tLibro l;

    extraerISBN(b, ISBN, l);

    modificarAñoPublicacion(l, año);

    eliminar(b, ISBN);
    añadir(b, l);
}

void masNuevo(tBibliografia b, tLibro &l) {
    tLibro libroLeido;

    int cont = 0, añoMayor = 0, añoPublicacionLeido;
    int cantLibros = numeroLibros(b);

    while (cont < cantLibros) {
        extraerPosicion(b, cont, libroLeido);
        añoPublicacionLeido = obtenerAñoPublicacion(libroLeido);

        if (añoPublicacionLeido > añoMayor || añoMayor == 0) {
            añoMayor = añoPublicacionLeido;
            copiarDatosLibro(libroLeido, l);
        }

        cont++;
    }
}