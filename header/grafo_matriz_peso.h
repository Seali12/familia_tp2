#ifndef GRAFO_MATRIZ_PESO_H
#define GRAFO_MATRIZ_PESO_H

#include "vertice.h"

const int INFINITO = 0xFFFF;
const int NULO = 0;
const int NO_ESTA = -1;

class Grafo_matriz_peso{

    private:
        int** matriz_peso;

        Vertice* vertices;

        int numero_vertices;


    public:
        int infinito = INFINITO;
        
        //PRE: 
        //POST: Crea una matriz de peso del grafo
        Grafo_matriz_peso(int valor);


        //Constructor por defecto
        Grafo_matriz_peso();
        
        //PRE: Nombre debe ser un string valido.
        // POST: Crea un nuevo vertice en el grafo
        void nuevo_vertice(string nombre);
        
        // PRE:
        // POST:
        int peso_arista(string arista_1, string arista_2);
        
        // PRE:
        // POST: Devuelve la cantidad de vertices que tiene el grafo
        int obtener_numero_de_vertices();
    
        //PRE: 
        //POST: Devuelve los vertices del grafo
        Vertice* obtener_vertices();

        //PRE: 
        //POST: Crea un nuevo arco entre dos vertices con un peso especificado en los parametros.
        void nueva_arista(string origen, string destino, int peso);

        //PRE:el nuevo_vertice debe existir
        //POST: valida que exista el vertice que recibe por parametro, si no existe devuelve -1
        int existe_vertice(string nuevo_vertice);

        // PRE:
        // POST: Devuel la matriz con los pesos.
        int** obtener_matriz_peso();

        //Pre: 
        //Post: 
        void liberar_grafo();
};  



#endif //GRAFO_MATRIZ_PESO_H