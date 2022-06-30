#include "../header/escritor.h"

Escritor::Escritor(string referencia, string nombre_y_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento) {
    
    this -> referencia = referencia;
    this -> nombre_y_apellido = nombre_y_apellido;
    this -> nacionalidad = nacionalidad;
    this -> anio_nacimiento = anio_nacimiento;
    this -> anio_fallecimiento = anio_fallecimiento;
}

Escritor::Escritor() {
    
    referencia = " ";
    nombre_y_apellido = " ";
    nacionalidad = " ";
    anio_nacimiento = 0;
    anio_fallecimiento = 0;
}


void Escritor::mostrar() {
    
    cout << "Isni: " << referencia << endl;

    cout << "Nombre y apellido: " << nombre_y_apellido << endl;

    cout << "Nacionalidad : " << nacionalidad << endl;

    cout << "Año de nacimiento: " << anio_nacimiento << endl;

    cout << "Año de fallecimiento: " << anio_fallecimiento << endl;

    cout << "" << endl;
}

string Escritor::obtener_nombre_y_apellido() {
    
    return nombre_y_apellido;
}

string Escritor::obtener_referencia(){
    
    return referencia;
}

void Escritor::modificar_anio_fallecimiento(int anio_ingresado){
    
    anio_fallecimiento = anio_ingresado;

}

void Escritor::mostrar_isni(){

    cout << "Isni: " << referencia <<endl;
    
    cout << "Nombre y apellido: " << nombre_y_apellido << endl;
}