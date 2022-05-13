#include <iostream>
#include "pila_escritores.h"
#include "nodo_simple.h"

Pila::Pila(){
    ultimo=0;
    //llamar constructor de ESCRITOR

}

bool Pila::vacia(){
    return(ultimo==0);
}

Escritor consulta(){
    return ultimo->obtener_objeto();
}




void Pila::alta(Escritor escritor_alta){
    //hacerlo con los demas

}

