#ifndef ALGO_2_TP_2_NOVELA_H
#define ALGO_2_TP_2_NOVELA_H

#include "lectura.h"

enum Genero{
    HISTORICA,
    ROMANCE,
    TERROR,
    SUSPENSO,
    FICCION,
    COMEDIA,
    DRAMA
};

class Novela: public Lectura{
protected:
    int genero;

public:
    //Pre:
    //Post: Crea una novela nueva.
    Novela(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string genero);

    //Pre: Debe existir una novela la cual se quiere mostrar.
    //Post: Muestra la informacion de una novela completa por pantalla.
    void mostrar();

    //PRE: Debe existir una novela la cual se quiere mostrar.
    //POST Muestra el género de la novela.
    void mostrar_genero();

    //PRE: Debe existir una novela la cual se quiere consultar.
    //POST: Devuelve el genero de la novela.
    //Se considera como atributo especial, aquel que varia entre las clases hijas.
    string obtener_atributo_especial();
};

#endif
