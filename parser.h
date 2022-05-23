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
    //POST: Inicializa al objeto
    Parser(string archivo_lectura, string archivo_escritor, Lista_lectura lecturas, Lista_escritor escritores);

    //PRE: El archivo tiene que tener el formato correcto
    //POST: Carga en la lista de escritores todo los escritores que estan en el archivo_escritor
    void procesar_archivo_escritores();

    //PRE: El archivo tiene que tener el formato correcto
    //POST: Carga en la lista de lecturas todo las lecturas que estan en el archivo_lectura
    void procesar_archivo_lectura();
    
    //PRE:
    //POST: Devuelve la lista de lecturas
    Lista_lectura devolver_lecturas();

    //PRE:
    //POST: Devuelve la lista de escritores
    Lista_escritor devolver_escritores();

    //BORRAR
    void mostrar();

    void eliminar_listas();

    //PRE:
    //POST: Destructor
    ~Parser(){};
};

#endif