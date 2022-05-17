#include "novela_historica.h"

Novela_historica::Novela_historica(string titulo, double minutos, int anio, Escritor* escritor, int genero, string tema) 
                            : Novela(titulo, minutos, anio, escritor, NOVELA_HISTORICA){

    
    this->tema = tema;
                            
}

void Novela_historica::mostrar() {
   
    cout << "Novela Historica" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    cout << "El genero de la novela hisorica es: " << genero << endl;

    cout << "El tema de la novela_historica es: " << tema << endl;

    cout << "La referencia al escritor es: " << escritor->obtener_nombre() << " " << escritor->obtener_apellido() << endl;

}