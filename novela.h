#ifndef ALGO_2_TP_2_NOVELA_H
#define ALGO_2_TP_2_NOVELA_H

#include "lectura.h"

class Novela: public Lectura{
protected:
    int genero;

public:
    //Pre:
    //Post: Crea una novela nueva.
    Novela(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor, int genero);

    //Pre:
    //Post: Muestra la informacion de una novela completa por pantalla.
    void mostrar_novela();
};


#endif
