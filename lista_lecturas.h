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
    void alta(Lectura* objeto);

    //PRE:
    //POST:
    void baja();
    
    //PRE:
    //POST:
    Lectura* consulta();

    //PRE:
    //POST:
    bool vacia();

    //PRE:
    //POST:
    int obtener_cantidad();

    //Destructor
    ~Lista_lecturas();

  private:
    int cantidad;
    Nodo<Lectura*>* ultimo;
    Nodo<Lectura*>* actual;

    auto desplazamiento(int posicion_esperada);
    void ordenar(Nodo<Lectura*> objeto);
};

#endif // !LISTA_LECTURAS_H
