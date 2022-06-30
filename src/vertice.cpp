#include "../header/vertice.h"


Vertice::Vertice(){
    
    nueva_lectura = nullptr;
    numero_vertice = VACIO;
}


Vertice::Vertice(Lectura* nueva_lectura){
   
    this -> nueva_lectura = nueva_lectura;
    numero_vertice = VACIO;
}


Lectura* Vertice::obtener_vertice(){
   
    return nueva_lectura;
}


bool Vertice::iguales(Vertice nuevo_vertice){
   
    return (nueva_lectura -> obtener_titulo() == nuevo_vertice.nueva_lectura -> obtener_titulo());
}

void Vertice::asignar_vertice(int numero){
   
    numero_vertice = numero;
}