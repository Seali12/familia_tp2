#ifndef LISTA_LECTURA_H
#define LISTA_LECTURA_H

#include "colores.h"
#include "nodo_simple.h"
#include "lectura.h"



class Lista_lectura {
  
  public:
    //Constructor
    Lista_lectura();

    //PRE: Recive un objeto de tipo Lectura*
    //POST: Agrega al objeto en la lista
    void alta(Lectura* objeto);

    //PRE: La lista no tiene que estar vacia
    //POST: Elimina el ultimo elemento de la lista (por defecto)
    void baja();

    //PRE: La lista no tiene que estar vacia y el objeto tiene que estar en la lista
    //POST: Elimina el elemento que tenga el mismo titulo que se busca.
    void baja(string titulo);
    
    //PRE: La lista no tiene que estar vacia y el objeto que se busca tiene que estar en la lista
    //POST: Devuelve al objeto que se quiere consultar
    Lectura* consulta(string titulo);

    //PRE: Debe existir una lista previamnte creada.
    //POST: Devuelve true si la lista esta vacia sino false.
    bool vacia();

    //PRE:
    //POST: Devuelve cuantos elementos tiene la lista.
    int obtener_cantidad();

    //PRE: la lista no tiene que estar vacia
    //POST: Imprime todo el contenido de la lista
    void mostrar_lista_lectura();

    //PRE: La lista no debe estar vacia, anio_min y anio_max deben ser > 0 anio_min debe < anio_max.
    //Post: Muestra todas las lectuas entre el anio_min y el anio_max.
    void mostrar_rango(int anio_min, int anio_max);

    //PRE: Recibe un numero aleatorio >= 0.
    //POST: Devuelve una lectura aleatoria en base a ese numero 
    void lectura_random(int numero_rand);
    
    //PRE: genero peude ser: "TERROR", "HISTORICA", "FICCION", "COMEDIA", "ROMANTICA", "DRAMA", "SUSPENSO".
    //POST: Muestra todas las lecturas con el genero ingresado
    void listar_por_genero(string genero);

    //PRE: el escritor tiene que estar en la lista de escritores
    //POST: Imprime por pantalla todas las lecturas del escritor que se pasa por parametro
    void listar_por_escritor(string referencia);

    //Destructor
    void liberar_lista();

    Lectura* consulta(double &minimo);

private:
    int cantidad;
    Nodo<Lectura*>* ultimo;
    Nodo<Lectura*>* actual;
    Nodo<Lectura*>* nodo_anterior;

    void reiniciar_actual();

    bool es_ultimo(Nodo<Lectura*>* nodo);

    void ordenar(Lectura* objeto, Nodo<Lectura*>* direccion);

    void desplazar_actual(Nodo<Lectura*>* nodo_actual);

    bool genero_no_encontrado(string genero);
};

#endif // !LISTA_LECTURAS_H
