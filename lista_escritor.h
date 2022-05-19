#ifndef Lista_escritor_ESCRITOR_H
#define Lista_escritor_ESCRITOR_H

#include "nodo_simple.h"
#include "escritor.h"


typedef Escritor Tipo;
class Lista_escritor{
public:
//Constructor
    Lista_escritor();

    //PRE: Recive un objeto de tipo escrLista_escritor*
    //POST: Agrega al objeto en la lista
    void alta(Tipo objeto);

    //PRE: La lista no tiene que estar vacia
    //POST: Elimina el ultimo elemento de la lista (por defecto)
    void baja();

    //PRE: La lista no tiene que estar vacia y el objeto tiene que estar en la lista
    //POST: Elimina el elemento que tenga el mismo titulo que se busca.
    void baja(string nombre_y_apellido);
    
    //PRE: La lista no tiene que estar vacia y el objeto que se busca tiene que estar en la lista
    //POST: Devuelve al objeto que se quiere consultar
    Tipo consulta(string referencia_escritor);

    //PRE:
    //POST: Verifica que la lista no este vacia
    bool vacia();

    //PRE:
    //POST: Devuelve cuantos elementos tiene la lista
    int obtener_cantidad();


    //Pre:
    //Post: Muestra por pantalla los datos del escritor.
    void mostrar_lista_escritor();

    //Destructor
    void liberar_lista();

  private:
    int cantidad;
    Nodo<Tipo>* ultimo;
    Nodo<Tipo>* actual;


    void desplazar_actual(string referencia);    
};






#endif //LISTA_ESCRITORES