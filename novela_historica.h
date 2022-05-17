#ifndef NOVELA_HISTORICA_H
#define NOVELA_HISTORICA_H


#include "novela.h"

class Novela_historica : public Novela{

private:
    string tema;
    
public:
    
    //Pre:
    //Post: Crea una novela_historica nueva.
    Novela_historica(string titulo, double minutos, int anio, Escritor* escritor, int genero, string tema);

    //Pre:
    //Post: Muestra la informacion de una novela_historica.
    void mostrar();






};

















#endif