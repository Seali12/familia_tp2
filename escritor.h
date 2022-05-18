#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <iostream>

using namespace std;

class Escritor {
private:
    string referencia;
    string nombre_y_apellido;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    

public:

    //Pre:
    //Post: Crea un escritor.
    Escritor(string referencia, string nombre_y_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimineto);

    //Pre:
    //Post: Crea un escritor por defecto.
    Escritor();

    //Pre:
    //Post: Muestra por pantalla los datos del escritor.
    void mostrar();

    //Pre:
    //Post: Devuelve el nombre del escritor y apellido.
    string obtener_nombre_y_apellido();

    //pre:
    //Post: Devuelve el numero de referencia del autor.
    string obtener_referencia();
};


#endif 
