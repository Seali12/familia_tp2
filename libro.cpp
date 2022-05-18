#include "libro.h"



Libro::Libro(string titulo, double minutos, int anio, Escritor escritor, string titulo_libro) 
: Lectura(titulo, minutos, anio, escritor){

    this->titulo_libro = titulo_libro;
}

void Libro::mostrar() {
    
    cout << "Libro" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "El titulo del libro es: " << titulo_libro << endl;

    cout << "La referencia al escritor es: " << escritor.obtener_nombre_y_apellido() << endl;

}