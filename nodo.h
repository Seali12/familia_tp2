#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>

typedef  Lectura* Dato;


class Nodo {
    // Atributos
private:
    Dato dato;
    Nodo* siguiente;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye un Nodo con d como dato anterior en nullptr
    */
    Nodo(Dato d);


    void cambiar_siguiente(Nodo* n);

    Dato obtener_dato();

    Nodo* obtener_siguiente();

};

#endif // NODO_H_INCLUDED
