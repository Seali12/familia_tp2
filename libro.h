#ifndef ALGO_2_TP_2_LIBRO_H
#define ALGO_2_TP_2_LIBRO_H

#include "lectura.h"

class Libro : public Lectura{
private:
    string titulo_libro;

public:
    //Pre:
    //Post: Crea un libro nuevo.
    Libro(string titulo, double minutos, int anio, Escritor escritor, char tipo_de_lectura, int referencia_escritor, string titulo_libro);

    //Pre:
    //Post: Muestra un la informacion de un libro completo por pantalla.
    void mostrar_libro();

};

#endif
