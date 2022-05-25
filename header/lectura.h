#ifndef LECTURA_H
#define LECTURA_H

#include "escritor.h"

class Lectura {

protected:
    char tipo_lectura;
    string titulo;
    double minutos;
    int anio;
    Escritor* escritor;

public:
    //PRE:
    //POST: Crea una nueva lectura
    Lectura(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor);

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

    //PRE:
    //POST: Devuelve el tipo de la lactura, N para novela, C para cuento, P para poema.
    char obtener_tipo_lectura();

    //Pre:
    //Post:
    virtual void mostrar() = 0;
    
    virtual string obtener_atributo_especial() = 0;

    //Destructor
    virtual ~Lectura(){};

};

#endif
