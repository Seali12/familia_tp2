#include <iostream>
#include "pila_escritores.h"
#include "nodo_simple.h"

Pila::Pila(){
    ultimo = nullptr;
}

bool Pila::vacia(){
    return(ultimo == nullptr);
}

Escritor Pila::consulta(){
    return ultimo->obtener_objeto();
}


void Pila::alta(Escritor escritor_alta){
    //hacerlo con los demas
    Nodo<Escritor>*nuevo= new Nodo<Escritor>(escritor_alta);
    nuevo->cambiar_siguiente(ultimo);
    ultimo=nuevo;

}
void Pila::baja(){
    Nodo<Escritor>*borrar=ultimo;
    ultimo=ultimo->obtener_siguiente();
    delete ultimo;
}


void Pila::liberar_Pila(){
    while( ! vacia() ){
        baja();
    }
}
