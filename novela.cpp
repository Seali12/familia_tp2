#include "novela.h"

Novela::Novela(string titulo, double minutos, int anio, Escritor* escritor,  int genero) :
                Lectura(titulo, minutos, anio, escritor){

    this->genero = genero;
}

void Novela::mostrar(){
    
    cout << "Novela" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    cout << "El genero es: " << genero << endl;

    cout << "La referencia al escritor es: " << escritor->obtener_nombre() << " " << escritor->obtener_apellido() << endl;

}