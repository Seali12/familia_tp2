#include "../header/cuento.h"

Cuento::Cuento(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string titulo_cuento) 
: Lectura(tipo_lectura, titulo, minutos, anio, escritor){

    this -> titulo_cuento = titulo_cuento;
}

string Cuento::obtener_atributo_especial(){
    
    return titulo_cuento;
}

void Cuento::mostrar() {
    
    cout << "Libro" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "Titulo del libro: " << titulo_cuento << endl;

    if(escritor == 0){
        
        cout << "Referencia al escritor: No existe" << endl;
    }
    else{
        
        cout << "Referencia al escritor: " << escritor -> obtener_referencia() << endl;
    }

    cout << "" << endl;

}