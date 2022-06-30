#ifndef NOVELA_HISTORICA_H
#define NOVELA_HISTORICA_H


#include "novela.h"

class Novela_historica : public Novela{

private:
    string* tema;
    
public: 

    //Pre:
    //Post: Crea una novela_historica nueva.
    Novela_historica(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor, string genero, string* tema);

    //Pre: Debe existir una novela_historica la cual se quiere mostrar.
    //Post: Muestra por pantalla la informacion de una novela_historica.
    void mostrar();

    //Destructor
    ~Novela_historica();

};

#endif