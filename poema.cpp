#include "poema.h"

Poema::Poema(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor,
             int versos) : Lectura(titulo, minutos, anio, escritor, tipo_de_lectura, referencia_escritor){

    this->versos = versos;
}

void Poema::mostrar_poema() {
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "La cantidad de versos es: " << versos << endl;

    cout << "La referencia al escritor es: " << referencia_escritor << endl;

}