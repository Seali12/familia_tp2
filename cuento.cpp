#include "cuento.h"



Cuento::Cuento(string titulo, double minutos, int anio, Escritor* escritor, string titulo_libro) 
: Lectura(titulo, minutos, anio, escritor){

    this->titulo_cuento = titulo_cuento;
}

void Cuento::mostrar() {
    
    cout << "Libro" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "El titulo del libro es: " << titulo_cuento << endl;

    cout << "La referencia al escritor es: " << escritor->obtener_nombre_y_apellido() << endl;

    cout << "" << endl;

}