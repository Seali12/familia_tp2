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
        //Constructor
        Tabla_escritores();

        // pre: -
        // post: Da de alta un escritor en la tabla
        void alta(Escritor* nuevo_escritor);

        // pre: La tabla no debe estar vacia
        // post: Da de baja la refencia pasada por parametro
        void baja_tabla (string referencia);
        
        // pre: La tabla no debe estar vacia.
        // post: devuelve el escritor consultado por su referencia
        Escritor* consulta(string referencia);
        
        // pre: -
        // post: elimina todos los elementos de la tabla
        void eliminar_tabla();
        
        // pre: 
        // post: Muestra todos los elementos de la tabla
        void mostrar();
        
        // pre: -
        // post: Lista el ISNI con el nombre del escritor correspondiente
        void listar_isni_escritor();

    private:
        
        int clave_hashing(int clave);
        
        int obtener_clave(string referencia);
};

#endif