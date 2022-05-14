#ifndef ALGO_2_TP_2_LECTURA_H
#define ALGO_2_TP_2_LECTURA_H

#include "escritor.h"

class Lectura {

protected:
    string titulo;
    double minutos;
    int anio;
    Escritor escritor;
    char tipo_de_lectura; // N para novela, P para poema, C para cuento
    int referencia_escritor;

public:
    //Pre:
    //Post: Crea una nueva lectura
    Lectura(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor);

    //Pre:
    //Post:
    virtual void mostrar() = 0;

};

#endif
