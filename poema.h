#ifndef POEMA_H
#define POEMA_H

#include "lectura.h"

class Poema: public Lectura {
private:
    int versos;

public:
    //Pre:
    //Post: Crea un poema nuevo.
    Poema(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, int versos);

    //Pre:
    //Post: Muestra un la informacion de un poema completo por pantalla.
    void mostrar();

    string obtener_atributo_especial();

};

#endif
