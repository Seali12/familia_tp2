#ifndef ALGO_2_TP_2_LECTURA_H
#define ALGO_2_TP_2_LECTURA_H

#include "escritor.h"

class Lectura {

protected:
    string titulo;
    double minutos;
    int anio;
    Escritor escritor;

public:
    //Pre:
    //Post: Crea una nueva lectura
    Lectura(string titulo, double minutos, int anio, Escritor escritor);

    //Pre:
    //Post:
    virtual void mostrar() = 0;

};

#endif
