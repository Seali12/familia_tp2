#include "novela.h"

Novela::Novela(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor,  int genero) :
                Lectura(titulo, minutos, anio, escritor, tipo_de_lectura, referencia_escritor){

    this->genero = genero;
}

void Novela::mostrar_novela(){
    
    cout << tipo_de_lectura << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    cout << "El genero es: " << genero << endl;

    cout << "La referencia al escritor es: " << referencia_escritor << endl;

}

