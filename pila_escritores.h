#ifndef PILA_ESCRITORES_H
#define PILA_ESCRITORES_H

#include "nodo_simple.h"
#include "escritor.h"

class Pila{
private:
    Nodo<Escritor>*ultimo;   

public:
    
    //PRE:-
    //POST: construye pila vacia
    Pila();

    
    //PRE: recibe un daot valido-pila no esta llena
    //POST: da de alta un nuevo escritor
    void alta(Escritor escritor_alta );


    //PRE:Pila no vacia
    //POST:quita el ultimo 
    void baja();


    //PRE:la pila no puede estar vacia
    //POST:retorna el ultimo elemento 
    Escritor consulta();

    //PRE:-
    //POST:devuelve true si la pila esta vacia
    bool vacia();


    void liberar_Pila();


};
#endif //PILA_ESCRITORES