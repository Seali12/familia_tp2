#ifndef ALGO_2_TP_2_ESCRITOR_H
#define ALGO_2_TP_2_ESCRITOR_H

#include <iostream>

using namespace std;

class Escritor {
private:
    string nombre;
    string apellido;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;

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


    
};


#endif 
