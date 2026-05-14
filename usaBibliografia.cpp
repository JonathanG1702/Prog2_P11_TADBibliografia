#include "TADusaBibliografia.h"

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

void modificarAñoLibro(tBibliografia &b, char ISBN[], int añoNuevo) {
    tLibro l;

    int añoViejo;

    extraerISBN(b, ISBN, l);
    añoViejo = obtenerAñoPublicacion(l);

    if (añoViejo != añoNuevo) {
        modificarAñoPublicacion(l, añoNuevo);

        eliminar(b, ISBN);
        añadir(b, l);
    } else {
        cout << "> ERROR: El nuevo año que intentas establecer (" << añoNuevo << ") es el mismo que el que hay establecido actualmente." << endl;
    }

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

// OTROS METODOS EXTRA
void juntarBibliografias(tBibliografia b1, tBibliografia b2, tBibliografia &resultado) {
    tLibro l1, l2;
    char ISBNL1[11], ISBNL2[11];
    int pos1 = 0, pos2 = 0;
    int tam1, tam2, comp;
    bool leer1 = true, leer2 = true;

    tam1 = numeroLibros(b1);
    tam2 = numeroLibros(b2);
    iniciar(resultado);

    while (pos1 < tam1 && pos2 < tam2) {
        if (leer1) {
            extraerPosicion(b1, pos1, l1);
            obtenerISBN(l1, ISBNL1);
            leer1 = false;
        }

        if (leer2) {
            extraerPosicion(b2, pos2, l2);
            obtenerISBN(l2, ISBNL2);
            leer2 = false;
        }

        comp = strcmp(ISBNL1, ISBNL2);

        if (comp < 0) {
            añadir(resultado, l1);
            pos1++;
            leer1 = true;
        } else if (comp == 0) {
            añadir(resultado, l1);
            pos1++;
            pos2++;
            leer1 = true;
            leer2 = true;
        } else {
            añadir(resultado, l2);
            pos2++;
            leer2 = true;
        }
    }

    while (pos1 < tam1) {
        extraerPosicion(b1, pos1, l1);
        añadir(resultado, l1);
        pos1++;
    }

    while (pos2 < tam2) {
        extraerPosicion(b2, pos2, l2);
        añadir(resultado, l2);
        pos2++;
    }

    cambiarTamañoBibliografia(resultado, tam1 + tam2);
}