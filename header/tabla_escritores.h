#ifndef TABLA_ESCRITORES_H
#define TABLA_ESCRITORES_H

#include "lista_escritor.h"
#include <string>

const int N = 25;
const int INICIO_CLAVE = 1;

class Tabla_escritores{
    
    private:
        
        Lista_escritor* vector[N];
        
    public:
        
        Tabla_escritores();

        void alta(Escritor* nuevo_escritor);

        void baja(string referencia);

        Escritor* consulta(string referencia);

        void eliminar_tabla();

        void mostrar();

    private:
        
        int hashing(int clave);
        
        int obtener_clave(string referencia);
};

#endif