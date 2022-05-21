#ifndef PARSER_H
#define PARSER_H

#include "lectura.h"
#include "poema.h"
#include "cuento.h"
#include "novela_historica.h"
#include "escritor.h"
#include "lista_lectura.h"
#include "lista_escritor.h"
#include <string>

const int CHAR = 0;
const char N = 'N';
const char P = 'P';
const char C = 'C';

class Parser {
private:
    string archivo_lectura;
    
    string archivo_escritor;
    
    Lista_lectura lecturas;

    Lista_escritor escritores;
    
public:
    //PRE:
    //POST:
    Parser(string archivo_lectura, string archivo_escritor, Lista_lectura lecturas, Lista_escritor escritores);

    //PRE:
    //POST:
    void procesar_archivo_escritores();

    //PRE:
    //POST:
    void procesar_archivo_lectura();    

    //PRE:
    //POST:
    void mostrar();
    
    //PRE:
    //POST:
    ~Parser();
};




#endif