#ifndef LISTA_LECTURAS_H
#define LISTA_LECTURAS_H

#include "nodo_simple.h"
#include "lectura.h"

class Lista_lecturas {
  public:
    //Constructor
    Lista_lecturas();

    //PRE:
    //POST:
    void alta();

    //PRE:
    //POST:
    void baja();
    
    //PRE:
    //POST:
    Lectura consulta();

    //PRE:
    //POST:
    bool vacia();

    //PRE:
    //POST:
    int obtener_cantidad();

  private:
    int cantidad;
    Nodo* ultimo;
    Nodo* actual;
};

#endif // !LISTA_LECTURAS_H
