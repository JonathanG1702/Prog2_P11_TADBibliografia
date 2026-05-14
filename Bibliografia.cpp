#include "TADBibliografia.h"

void iniciar(tBibliografia &b) {
    b.primero = nullptr;
    b.tam = 0;
}

void añadir(tBibliografia &b, tLibro l) {
    Nodo *nuevo = new Nodo();
    Nodo *ant = nullptr;
    Nodo *act = b.primero;

    char ISBNLibro[11];
    char ISBNLibroActual[11];
    bool parar = false;

    copiarDatosLibro(l, (*nuevo).libro);
    (*nuevo).sig = nullptr;
    obtenerISBN((*nuevo).libro, ISBNLibro);


    while (act != nullptr && !parar) {
        obtenerISBN((*act).libro, ISBNLibroActual);

        if (strcmp(ISBNLibroActual, ISBNLibro) >= 0) {
            parar = true;
        } else {
            ant = act;
            act = (*act).sig;
        }
    }

    if (ant == nullptr) {
        (*nuevo).sig = b.primero;
        b.primero = nuevo;
    } else {
        (*nuevo).sig = act;
        (*ant).sig = nuevo;
    }

    b.tam++;
}

void eliminar(tBibliografia &b, char ISBN[]) {
    Nodo *ant = nullptr;
    Nodo *act = b.primero;

    char ISBNLeido[11];
    bool encontrado = false;

    while (act != nullptr && !encontrado) {
        obtenerISBN((*act).libro, ISBNLeido);

        if (strcmp(ISBNLeido, ISBN) == 0) {
            encontrado = true;
        } else {
            ant = act;
            act = (*act).sig;
        }
    }

    if (ant == nullptr) {
        b.primero = (*act).sig;
    } else {
        (*ant).sig = (*act).sig;
    }

    delete act;
    b.tam--;
}

void extraerISBN(tBibliografia b, char ISBN[], tLibro &l) {
    Nodo *act = b.primero;

    char ISBNLeido[11];
    bool encontrado = false;

    while (act != nullptr && !encontrado) {
        obtenerISBN((*act).libro, ISBNLeido);

        if (strcmp(ISBNLeido, ISBN) == 0) {
            encontrado = true;
        } else {
            act = (*act).sig;
        }
    }

    copiarDatosLibro((*act).libro, l);
}

void extraerPosicion(tBibliografia b, int pos, tLibro &l) {
    Nodo *act = b.primero;

    int cont = 0;

    while (act != nullptr && cont < pos) {
        act = (*act).sig;
        cont++;
    }

    if (act != nullptr) {
        copiarDatosLibro((*act).libro, l);
    }
}

bool bibliografiaSinLibros(tBibliografia b) {
    return b.primero == nullptr;
}

int numeroLibros(tBibliografia b) {
    Nodo *act = b.primero;

    int cont = 0;

    while (act != nullptr) {
        act = (*act).sig;
        cont++;
    }

    return cont;
}

void copiarBibliografia(tBibliografia b, tBibliografia &b1) {
    Nodo *actOriginal = b.primero;
    Nodo *nuevo;
    Nodo *ultimoCopiado = nullptr;

    iniciar(b1);

    while (actOriginal != nullptr) {
        nuevo = new Nodo;

        copiarDatosLibro((*actOriginal).libro, (*nuevo).libro);
        (*nuevo).sig = nullptr;

        if (b1.primero == nullptr) {
            b1.primero = nuevo;
        } else {
            (*ultimoCopiado).sig = nuevo;
        }

        ultimoCopiado = nuevo;
        actOriginal = (*actOriginal).sig;
    }

    b1.tam = b.tam;
}

void mostrarBibliografia(tBibliografia b) {
    Nodo *act = b.primero;

    while (act != nullptr) {
        mostrarDatosLibro((*act).libro);
        act = (*act).sig;
    }
}

void cambiarTamañoBibliografia(tBibliografia &b, int nuevoTam) {
    b.tam = nuevoTam;
}