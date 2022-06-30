#include "../header/cola.h"

Cola::Cola(){

    ultimo = nullptr;
    primero = nullptr;
}

void Cola::alta(Lectura* nueva_lectura){
    
    Nodo<Lectura*>* nuevo = new Nodo<Lectura*>(nueva_lectura);
    
    if(primero == nullptr){
        
        primero = nuevo;
        ultimo = nuevo;
    
    }else{
        
        ultimo -> cambiar_siguiente(nuevo);
        ultimo = nuevo;
    }
}

void Cola::baja(){
    
    Nodo<Lectura*>* borrar = primero;

    if (!vacia()){
        
        primero = primero->obtener_siguiente();
        
    }else{

        primero = nullptr;

    }
    
    delete borrar; 
}

    
Lectura* Cola::consulta(){
    
    return primero -> obtener_objeto();     
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
    
    if(!vacia()){
        
        primero -> obtener_objeto() -> mostrar();
    }
}
    