#include "../header/lectura.h"

Lectura::Lectura(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor) {
    
    this -> tipo_lectura = tipo_lectura;
    this -> titulo = titulo;
    this -> minutos = minutos;
    this -> anio = anio;
    this -> escritor = escritor;
}

int Lectura::obtener_anio(){
    return anio;
}

Escritor* Lectura::obtener_escritor(){
    return escritor;
}

double Lectura::obtener_minutos(){
    return minutos;
}

string Lectura::obtener_titulo(){
    return titulo;
}

char Lectura::obtener_tipo_lectura(){
    return tipo_lectura;
}

void Lectura::anular_escritor(){
    escritor = nullptr;
}