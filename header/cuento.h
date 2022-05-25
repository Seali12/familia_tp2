#ifndef CUENTO_H
#define CUENTO_H

#include "lectura.h"

class Cuento : public Lectura{
    public:
    //Pre:
    //Post: Crea un libro nuevo.
    Cuento(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string titulo_cuento);

    //Pre:
    //Post: Muestra un la informacion de un libro completo por pantalla.
    void mostrar();

    string obtener_atributo_especial();

    private:
        string titulo_cuento;

};

#endif
