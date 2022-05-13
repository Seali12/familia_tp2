#ifndef PILA_ESCRITORES_H
#define PILA_ESCRITORES_H

class pila{
private:
    Nodo*ultimo;
    Escritor escritor_nue;
public:
    
    //PRE:-
    //POST: construye pila vacia
    Pilas();

    
    //PRE: recibe un daot valido-pila no esta llena
    //POST: da de alta un nuevo escritor
    void alta(Escritor escri);

};






#endif //PILA_ESCRITORES