#include "novela.h"

Novela::Novela(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor,  string genero) :
                Lectura(tipo_lectura, titulo, minutos, anio, escritor){

    this->genero = genero;
}

void Novela::mostrar(){
    
    cout << "Novela" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    cout << "Genero : " << genero << endl;

    cout << "Referencia al escritor: " << escritor->obtener_nombre_y_apellido() << endl;

    cout << "" << endl;

}

string Novela::obtener_atributo_especial(){
    return genero;
}