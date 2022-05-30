#ifndef CUENTO_H
#define CUENTO_H

#include "lectura.h"

class Cuento : public Lectura{
    public:
    
    //Pre:
    //Post: Crea un libro nuevo.
    Cuento(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string titulo_cuento);

    //Pre: Exista un cuento previamente creado.
    //Post: Muestra un la informacion de un libro completo por pantalla.
    void mostrar();


    //PRE: Exista un cuento previamente creado.
    //POST: Retorna el titulo del cuento.
    //Se considera como atributo especial, aquel que varia entre las clases hijas.
    string obtener_atributo_especial();

    private:
        string titulo_cuento;

};

#endif
