#include "../header/novela_historica.h"

Novela_historica::Novela_historica(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string genero, string tema) 
                            : Novela(tipo_lectura, titulo, minutos, anio, escritor, genero){

    this->tema = tema;
                            
}

void Novela_historica::mostrar() {
   
    cout << "Novela Historica" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    cout << "Genero de la novela hisorica: " << genero << endl;

    cout << "Tema de la novela_historica: " << tema << endl;

    cout << "Referencia al escritor: " << escritor->obtener_nombre_y_apellido() << endl;

    cout << "" << endl;

}