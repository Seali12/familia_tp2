#ifndef LECTURA_H
#define LECTURA_H

#include "escritor.h"

class Lectura {

protected:
    string titulo;
    double minutos;
    int anio;
    Escritor* escritor;

public:
    //PRE:
    //POST: Crea una nueva lectura
    Lectura(string titulo, double minutos, int anio, Escritor* escritor);

    //PRE:
    //POST: Devuelve el anio
    int obtener_anio();

    //PRE:
    //POST: Devuelve el titulo
    string obtener_titulo();

    //PRE:
    //POST: Devuelve los minutos
    double obtener_minutos();

    //PRE:
    //POST: Devuelve el escritor
    Escritor* obtener_escritor();

    //Pre:
    //Post:
    virtual void mostrar() = 0;

};

#endif
