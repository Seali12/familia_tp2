#include "../header/vertice.h"


Vertice::Vertice(){
    
    nombre = " ";
    numero_vertice = VACIO;
}


Vertice::Vertice(string nombre){
   
    this->nombre = nombre;
    numero_vertice = VACIO;
}



string Vertice::obtener_nombre_vertice(){
   
    return nombre;
}


bool Vertice::iguales(Vertice nuevo_vertice){
   
    return (nombre == nuevo_vertice.nombre);
}

void Vertice::asignar_vertice(int numero){
   
    numero_vertice = numero;
}