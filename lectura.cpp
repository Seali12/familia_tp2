#include "lectura.h"

Lectura::Lectura(string titulo, double minutos, int anio, Escritor escritor,
                 char tipo_de_lectura, int referencia_escritor) {

    this->titulo = titulo;
    this->minutos = minutos;
    this->anio = anio;
    this->escritor = escritor;
    this->tipo_de_lectura = tipo_de_lectura;
    this->referencia_escritor = referencia_escritor;
}
