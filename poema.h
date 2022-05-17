#ifndef ALGO_2_TP_2_POEMA_H
#define ALGO_2_TP_2_POEMA_H

#include "lectura.h"

class Poema: public Lectura {
private:
    int versos;

public:
    //Pre:
    //Post: Crea un poema nuevo.
    Poema(string titulo, double minutos, int anio, Escritor* escritor, int versos);

    //Pre:
    //Post: Muestra un la informacion de un poema completo por pantalla.
    void mostrar();

};


#endif
