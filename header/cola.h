#ifndef COLA_H
#define COLA_H

#include "nodo_simple.h"
#include "lectura.h"


typedef Lectura* Data; 

class Cola{
    private:
        Nodo<Data>* primero;
        Nodo<Data>* ultimo;
        
    public:
        
        
        //PRE:-
        //POST: Construye una cola vacia.
        Cola();
        
        //PRE: Nueva_lectura debe ser un objeto lectura dinamico.
        //POST: Agrega una lectura a la cola de menor tiempo de lectura a mayor.
        void alta(Data  nueva_lectura);
        
        //PRE: La cola no debe estar vacia.
        //POST: Da de baja la direccion de una lectura.
        void baja();

        //PRE:
        //POST:Devuelve el dato consultado
        Data consulta();
        
        //PRE:
        //POST: Devuelve true si la cola esta vacia
        bool vacia();

        //PRE:
        //POST:
        void mostrar();

        //POST:
        void eliminar_cola();
};


#endif 