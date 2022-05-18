#include "poema.h"

Poema::Poema(string titulo, double minutos, int anio, Escritor escritor, int versos) 
: Lectura(titulo, minutos, anio, escritor){

    this->versos = versos;
}

void Poema::mostrar() {
    cout << "Poema" << endl;

    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "La cantidad de versos es: " << versos << endl;

    cout << "La referencia al escritor es: " << escritor.obtener_nombre_y_apellido() << endl;

}