#include "nodo.h"

// Constructor
Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

// cambiar anterior
void Nodo::cambiar_siguiente(Nodo* n) {
    siguiente = n;
}

// obtener dato
Dato Nodo::obtener_dato() {
    return dato;
}

// obtener anterior
Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}
