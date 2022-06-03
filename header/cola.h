#ifndef COLA_H
#define COLA_H

#include "nodo_simple.h"
#include "lectura.h"


 

class Cola{
    private:
        Nodo<Lectura*>* primero;
        Nodo<Lectura*>* ultimo;
        
    public:
        
        
        //PRE:-
        //POST: Construye una cola vacia.
        Cola();
        
        //PRE: Nueva_lectura debe ser un objeto lectura dinamico.
        //POST: Agrega una lectura a la cola de menor tiempo de lectura a mayor.
        void alta(Lectura*  nueva_lectura);
        
        //PRE: La cola no debe estar vacia.
        //POST: Da de baja la direccion de una lectura.
        void baja();

        //PRE:-
        //POST:Devuelve el dato consultado.
        Lectura* consulta();
        
        //PRE:
        //POST: Devuelve true si la cola esta vacia.
        bool vacia();

        //PRE: La cola no debe estar vacia.
        //POST: Imprime por pantalla la cola.
        void mostrar();

        //PRE: La cola no puede estar vacia.
        //POST: Elimina la cola liberando memoria.
        void eliminar_cola();
};


#endif 