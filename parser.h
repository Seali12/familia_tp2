#ifndef PARSER_H
#define PARSER_H

#include "lectura.h"
#include "escritor.h"
#include <string>

template <typename Tipo>

class Parser {
private:
    string linea;
    
    int referenia_escritor;

    string nombre_escritor;

    string nacionalidad;
    
    int anio_nacimiento;

    int anio_fallecimiento;
    //hasta aca el archivo escritor

    char tipo_lectura;

    string titulo;

    int minutos;

    int anio;

    string caracterisca;

    int referencia_lectura;
    //Archivo lectura
    
public:
    
    //PRE:
    //POST:
    Parser(string linea);

    Parser(string linea);

    
    //PRE:
    //POST:
    Lectura* procesar_archivo_escritores() const;
    

    //PRE:
    //POST:
    Lectura* procesar_archivo_lectura() const;
       
    
    //PRE:
    //POST:
    ~Parser(){};

};

template <typename Tipo>

Parser::Parser(Tipo linea){
    Tipo
    
}


#endif