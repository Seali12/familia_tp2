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

    //PRE: Deber existir una lectura de la cual se quiere consultar el año.
    //POST: Devuelve el año de la lectura.
    int obtener_anio();

    //PRE: Deber existir una lectura de la cual se quiere consultar el titulo.
    //POST: Devuelve el titulo.
    string obtener_titulo();

    //PRE: Debe existir una lectura de la cual se quiere consultar los minutos.
    //POST: Devuelve los minutos.
    double obtener_minutos();

    //PRE: Debe existir una lectura de la cual se quiere consultar el escritor.
    //POST: Devuelve el escritor.
    Escritor* obtener_escritor();

    //PRE: Debe existir una lectura de la cual se quiere consultar el tipo.
    //POST: Devuelve el tipo de la lactura, N para novela, C para cuento, P para poema.
    char obtener_tipo_lectura();

    virtual void mostrar() = 0;
    
    virtual string obtener_atributo_especial() = 0;

    //Destructor
    virtual ~Lectura(){};

};

#endif
