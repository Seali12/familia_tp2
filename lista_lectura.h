#ifndef LISTA_LECTURA_H
#define LISTA_LECTURA_H

#include "nodo_simple.h"
#include "lectura.h"

typedef Lectura* Dato;

class Lista_lectura {
  public:
    //Constructor
    Lista_lectura();

    //PRE: Recive un objeto de tipo Lectura*
    //POST: Agrega al objeto en la lista
    void alta(Dato objeto);

    //PRE: La lista no tiene que estar vacia
    //POST: Elimina el ultimo elemento de la lista (por defecto)
    void baja();

    //PRE: La lista no tiene que estar vacia y el objeto tiene que estar en la lista
    //POST: Elimina el elemento que tenga el mismo titulo que se busca.
    void baja(int anio, string titulo);
    
    //PRE: La lista no tiene que estar vacia y el objeto que se busca tiene que estar en la lista
    //POST: Devuelve al objeto que se quiere consultar
    Dato consulta(int anio, string titulo);

    //PRE:
    //POST: Verifica que la lista no este vacia
    bool vacia();

    //PRE:
    //POST: Devuelve cuantos elementos tiene la lista
    int obtener_cantidad();

    //PRE: la lista no tiene que estar vacia
    //POST: Imprime todo el contenido de la lista
    void mostrar_lista_lectura();

    //Destructor
    void liberar_lista();

  private:
    int cantidad;
    Nodo<Dato>* ultimo;
    Nodo<Dato>* actual;
    Nodo<Dato>* nodo_anterior;

    void ordenar(Dato objeto, Nodo<Dato>* direccion);

    void desplazar_actual(int anio, string titulo);
};

#endif // !LISTA_LECTURAS_H
