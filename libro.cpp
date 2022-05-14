#include "libro.h"



Libro::Libro(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor,
             string titulo_libro) : Lectura(titulo, minutos, anio, escritor, tipo_de_lectura, referencia_escritor){

    this->titulo_libro = titulo_libro;
}

void Libro::mostrar_libro() {
    
    cout << tipo_de_lectura << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "El titulo del libro es: " << titulo_libro << endl;

    cout << "La referencia al escritor es: " << referencia_escritor << endl;

}