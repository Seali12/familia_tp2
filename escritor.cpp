#include "escritor.h"

Escritor::Escritor(string referecnia, string nombre_y_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimineto) {
    
    this->referencia = referencia;
    this->nombre_y_apellido = nombre_y_apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimineto;
}

Escritor::Escritor() {
    referencia = " ";
    nombre_y_apellido = " ";
    nacionalidad = " ";
    anio_nacimiento = 0;
    anio_fallecimiento = 0;
}


void Escritor::mostrar() {
    
    cout << "La referencia del escritor es: " << referencia << endl;

    cout << "El nombre y apellido del escritor es: " << nombre_y_apellido << endl;

    cout << "La nacionalidad del escritor es: " << nacionalidad << endl;

    cout << "El año de nacimiento  del escritor es: " << anio_nacimiento << endl;

    cout << "El año de fallecimiento del escritor es: " << anio_fallecimiento << endl;
}

string Escritor::obtener_nombre_y_apellido() {
    return nombre_y_apellido;
}

string Escritor::obtener_referencia(){
    return referencia;
}