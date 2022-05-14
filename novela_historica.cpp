#include "novela_historica.h"

Novela_historica::Novela_historica(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor, int genero, string tema) 
                            : Novela(titulo, minutos, anio, escritor, tipo_de_lectura,  referencia_escritor, genero){

    this->tema = tema;
                            
}

void Novela_historica::mostrar_novela_historica() {
   
    cout << tipo_de_lectura << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    cout << "El genero de la novela hisorica es: " << genero << endl;

    cout << "El tema de la novela_historica es: " << tema << endl;

    cout << "La referencia al escritor es: " << referencia_escritor << endl;

}