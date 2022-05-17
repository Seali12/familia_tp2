#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <iostream>

using namespace std;

class Escritor {
private:
    string nombre;
    string apellido;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    int referencia;

public:

    //Pre:
    //Post: Crea un escritor.
    Escritor(string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimineto);

    //Pre:
    //Post: Crea un escritor por defecto.
    Escritor();

    //Pre:
    //Post: Muestra por pantalla los datos del escritor.
    void mostrar();

    //Pre:
    //Post: Devuelve el nombre del escritor
    string obtener_nombre();

    //Pre:
    //Post: Devuelve el apellido del escritor
    string obtener_apellido();

    //pre:
    //Post: Devuelve el numero de referencia del autor.
    int obtener_referencia();
};


#endif 
