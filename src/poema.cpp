#include "../header/poema.h"

Poema::Poema(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, int versos) 
: Lectura(tipo_lectura, titulo, minutos, anio, escritor){

    this -> versos = versos;
}

string Poema::obtener_atributo_especial(){
    
    return to_string(versos);
}

void Poema::mostrar() {
    cout << "Poema" << endl;

    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año del poema: " << anio << endl;

    cout << "Cantidad de versos: " << versos << endl;

    if(escritor == 0){
        
        cout << "Referencia al escritor: No existe" << endl;
    }
    else{
        
        cout << "Referencia al escritor: " << escritor -> obtener_referencia() << endl;
    }

    cout << "" << endl;

    cout << "" << endl;

}