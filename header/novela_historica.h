#ifndef NOVELA_HISTORICA_H
#define NOVELA_HISTORICA_H


#include "novela.h"

class Novela_historica : public Novela{

private:
    string tema;
    
public:

    //Pre:
    //Post: Crea una novela_historica nueva.
    Novela_historica(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string genero_recibido, string tema);

    //Pre:
    //Post: Muestra la informacion de una novela_historica.
    void mostrar();
};

















#endif