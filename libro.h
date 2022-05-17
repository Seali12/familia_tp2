#ifndef ALGO_2_TP_2_LIBRO_H
#define ALGO_2_TP_2_LIBRO_H

#include "lectura.h"

class Libro : public Lectura{
    public:
    //Pre:
    //Post: Crea un libro nuevo.
    Libro(string titulo, double minutos, int anio, Escritor* escritor, string titulo_libro);

    //Pre:
    //Post: Muestra un la informacion de un libro completo por pantalla.
    void mostrar();

    private:
        string titulo_libro;

};

#endif
