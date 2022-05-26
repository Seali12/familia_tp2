#include "../header/cola.h"

Cola::Cola(){
    ultimo = nullptr;
    primero = nullptr;
}

void Cola::alta(Data nueva_lectura){
    Nodo<Data>* nuevo = new Nodo<Data>(nueva_lectura);
    
    if(primero == nullptr){
        primero = nuevo;
        ultimo = nuevo;
    }else{
        ultimo->cambiar_siguiente(nuevo);
        ultimo = nuevo;
    }
}

void Cola::baja(){
    Nodo<Data>* borrar = primero;

    primero = primero->obtener_siguiente();
    delete borrar; 
}

    
Data Cola::consulta(){
    
    return primero->obtener_objeto();     
}


bool Cola::vacia(){

    return (primero == nullptr);
}
  

void Cola::eliminar_cola(){

    while(!vacia()){
        baja();
    }
}

void Cola::mostrar(){

    primero->obtener_objeto()->mostrar();
}
    