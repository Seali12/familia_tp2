#ifndef ALGO_2_TP_2_NOVELA_H
#define ALGO_2_TP_2_NOVELA_H

#include "lectura.h"

enum Genero{
    HISTORICA,
    ROMANTICA,
    TERROR,
    SUSPENSO,
    FICCION,
    COMEDIA,
    DRAMA
};

class Novela: public Lectura{
protected:
    string genero;

public:
    //Pre:
    //Post: Crea una novela nueva.
    Novela(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string genero);

    //Pre:
    //Post: Muestra la informacion de una novela completa por pantalla.
    void mostrar();

    //PRE:
    //POST.devuelve el genero
    string obtener_atributo_especial();
};



#endif
