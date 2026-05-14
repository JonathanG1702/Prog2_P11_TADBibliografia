#include <iostream>

#include "TADLibro.h"
#include "TADBibliografia.h"
#include "TADusaLibro.h"
#include "TADusaBibliografia.h"

using namespace std;

void añadirLibroMenu(tBibliografia &b);
void modificarAñoMenu(tBibliografia &b);
void buscarLibroMenu(tBibliografia b);
void eliminarLibroMenu(tBibliografia &b);
void mostrarOrdenadoAño(tBibliografia b);

int main() {
    tBibliografia b;
    int opcionElegida;

    iniciar(b);

    do {
        cout << "\n--- MENU TAD BIBLIOGRAFIA ---" << endl;
        cout << "1. Añadir libro" << endl;
        cout << "2. Modificar año de un libro" << endl;
        cout << "3. Listar libros por ISBN (Orden actual)" << endl;
        cout << "4. Listar libros por orden decreciente de año" << endl;
        cout << "5. Buscar libros por ISBN" << endl;
        cout << "6. Eliminar libro por ISBN" << endl;
        cout << "7. Indicar el numero de libros que existen" << endl;
        cout << "8. Copiar y mostrar total de la copia" << endl;
        cout << "9. Terminar" << endl;
        cout << "Elija una opcion: ";
        cin >> opcionElegida;

        switch (opcionElegida) {
            case 1: añadirLibroMenu(b); break;
            case 2: modificarAñoMenu(b); break;
            case 3:
                cout << "\nBIBLIOGRAFIA ACTUAL:" << endl;
                mostrarBibliografia(b);
                break;
            case 4: mostrarOrdenadoAño(b); break;
            case 5: buscarLibroMenu(b); break;
            case 6: eliminarLibroMenu(b); break;
            case 7:
                cout << "Total libros: " << numeroLibros(b) << endl;
                break;
            case 8: {
                tBibliografia copia;
                copiarBibliografia(b, copia);
                cout << "Copia realizada. Libros en copia: " << numeroLibros(copia) << endl;
                break;
            }
            case 9: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcionElegida != 9);

    return 0;
}

void añadirLibroMenu(tBibliografia &b) {
    tLibro l;
    char ISBN[11];
    leerDatosLibro(l);
    obtenerISBN(l, ISBN);

    if (existe(b, ISBN)) {
        cout << "> ERROR: El libro ya existe." << endl;
    } else {
        añadir(b, l);
        cout << "> SYSTEM: Añadido correctamente." << endl;
    }
}

void modificarAñoMenu(tBibliografia &b) {
    char ISBN[11];
    int nuevoAño;
    cout << "Introduzca ISBN: "; cin >> ISBN;
    if (existe(b, ISBN)) {
        cout << "Nuevo año: "; cin >> nuevoAño;
        modificarAñoLibro(b, ISBN, nuevoAño);
    } else {
        cout << "> ERROR: Libro no encontrado." << endl;
    }
}

void buscarLibroMenu(tBibliografia b) {
    char ISBN[11];
    tLibro l;
    cout << "ISBN a buscar: "; cin >> ISBN;
    if (existe(b, ISBN)) {
        extraerISBN(b, ISBN, l);
        mostrarDatosLibro(l);
    } else {
        cout << "> ERROR: No encontrado." << endl;
    }
}

void eliminarLibroMenu(tBibliografia &b) {
    char ISBN[11];
    cout << "ISBN a eliminar: "; cin >> ISBN;
    if (existe(b, ISBN)) {
        eliminar(b, ISBN);
        cout << "> SYSTEM: Eliminado." << endl;
    } else {
        cout << "> ERROR: No existe." << endl;
    }
}

void mostrarOrdenadoAño(tBibliografia b) {
    tBibliografia bAux;
    tLibro l;
    char ISBN[11];

    iniciar(bAux);
    copiarBibliografia(b, bAux);

    cout << "\nLIBROS POR AÑO (MÁS NUEVOS PRIMERO):" << endl;
    while (!bibliografiaSinLibros(bAux)) {
        masNuevo(bAux, l);
        mostrarDatosLibro(l);
        obtenerISBN(l, ISBN);
        eliminar(bAux, ISBN); // Borramos de la COPIA para encontrar el siguiente
    }
}