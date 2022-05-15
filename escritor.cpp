#include "escritor.h"


Escritor::Escritor() {
    nombre = " ";
    apellido = " ";
    nacionalidad = " ";
    anio_nacimiento =
}


void Escritor::mostrar() {
    cout << "El nombre del escritor es: " << nombre << endl;

    cout << "El apellido del escritor es: " << apellido << endl;

    cout << "La nacionalidad del escritor es: " << nacionalidad << endl;

    cout << "El año de nacimiento  del escritor es: " << anio_nacimiento << endl;

    cout << "El año de fallecimiento del escritor es: " << anio_fallecimiento << endl;
}