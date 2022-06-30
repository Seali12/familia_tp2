#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include "lectura.h"

const int VACIO = -1;

using namespace std;

class Vertice{
    private:
        Lectura* nueva_lectura;
        int numero_vertice;

    public:
        
        Vertice();

        //PRE:
        //POST:
        Vertice(Lectura* nueva_lectura);

        //PRE: 
        //POST: retorna el nombre del vertice
        Lectura* obtener_vertice();

        //PRE:
        //POST: Compara el vertice actual con el pasado por parametro, devuelve true si el nombre del nuevo vertice es igual al recibido sino false. 
        bool iguales(Vertice nuevo_vertice);

        
        //PRE: Numero debe ser > 0
        //POST: Asigna al numero de vertice el valor que recibe el parametro
        void asignar_vertice(int numero);


        ~Vertice(){};
};

#endif //VERTICE_H


