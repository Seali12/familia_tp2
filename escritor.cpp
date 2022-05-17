#include "escritor.h"

Escritor::Escritor(string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimineto) {

    this->nombre = nombre;
    this->apellido = apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimineto;
}

Escritor::Escritor() {
    nombre = " ";
    apellido = " ";
    nacionalidad = " ";
    anio_nacimiento = 0;
    anio_fallecimiento = 0;
}


void Escritor::mostrar() {
    cout << "El nombre del escritor es: " << nombre << endl;

    cout << "El apellido del escritor es: " << apellido << endl;

    cout << "La nacionalidad del escritor es: " << nacionalidad << endl;

    cout << "El año de nacimiento  del escritor es: " << anio_nacimiento << endl;

    cout << "El año de fallecimiento del escritor es: " << anio_fallecimiento << endl;
}

string Escritor::obtener_nombre() {
    return nombre;
}

string Escritor::obtener_apellido() {
    return apellido;
}

int Escritor::obtener_referencia() {
    return referencia;
}