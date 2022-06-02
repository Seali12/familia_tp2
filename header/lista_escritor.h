#ifndef LISTA_ESCRITOR_H
#define LISTA_ESCRITOR_H

#include "colores.h"
#include "nodo_simple.h"
#include "escritor.h"



class Lista_escritor{

public:
    //Constructor
    Lista_escritor();

    //PRE: Recive un objeto de tipo Lista_escritor*
    //POST: Agrega al objeto en la lista
    void alta(Escritor* objeto);

    //PRE: La lista no tiene que estar vacia
    //POST: Elimina el ultimo elemento de la lista (por defecto)
    void baja();

    //PRE: La lista no tiene que estar vacia y el objeto tiene que estar en la lista
    //POST: Elimina el elemento que tenga el mismo titulo que se busca.
    void baja(string nombre_y_apellido);
    
    //PRE: La lista no tiene que estar vacia y el objeto que se busca tiene que estar en la lista
    //POST: Devuelve al objeto que se quiere consultar
    Escritor* consulta(string referencia_escritor);

    //PRE: La lista no tiene que estar vacia y el objeto que se busca tiene que estar en la lista, busca un escritor segun su nombre.
    //POST: Devuelve al objeto que se quiere consultar
    void modificar_fallecimiento(string nombre_y_apellido, int anio_ingresado);

    //PRE:La lista no debe estar vacia
    //POST: Verifica que la lista no este vacia
    bool vacia();

    //PRE: La lista no debe estar vacia
    //POST: Devuelve cuantos elementos tiene la lista
    int obtener_cantidad();

    //Pre: La lista no debe estar vacia
    //Post: Muestra por pantalla los datos del escritor.
    void mostrar_lista_escritor();

    //Destructor
    void liberar_lista();

private:
    int cantidad;
    Nodo<Escritor*>* ultimo;
    Nodo<Escritor*>* actual;
    Nodo<Escritor*>* anterior;

    void desplazar_actual(string referencia); 
    
    bool es_ultimo(Nodo<Escritor*>* nodo);   
};






#endif //LISTA_ESCRITORES