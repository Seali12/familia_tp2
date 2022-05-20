#include "lectura.h"

Lectura::Lectura(string titulo, float minutos, int anio, Escritor escritor) {
    this->titulo = titulo;
    this->minutos = minutos;
    this->anio = anio;
    this->escritor = escritor;
}
int Lectura::obtener_anio(){
    return anio;
}

Escritor Lectura::obtener_escritor(){
    return escritor;
}

double Lectura::obtener_minutos(){
    return minutos;
}

string Lectura::obtener_titulo(){
    return titulo;
}
