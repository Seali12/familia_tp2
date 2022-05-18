#ifndef PARSER_H
#define PARSER_H

#include "lectura.h"
#include "novela.h"
#include "poema.h"
#include "libro.h"
#include "novela_historica.h"
#include "escritor.h"
#include "lista_lecturas.h"
#include "pila_escritores.h"
#include <string>


class Parser {
private:
    string archivo_lectura;
    
    string archivo_escritor;
    
    Lista lecturas;

    Pila escritores;
    
public:
    
    //PRE:
    //POST:
    Parser(string archivo_lectura, string archivo_escritor, Lista lecturas, Pila escritores);

    //PRE:
    //POST:
    void procesar_archivo_escritores();

    //PRE:
    //POST:
    void procesar_archivo_lectura();    
    
    //PRE:
    //POST:
    ~Parser(){};
};




#endif