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
        //POST
        Grafo_matriz_peso(int valor);


        //PRE:
        // POST:
        Grafo_matriz_peso();
        
        //PRE:
        // POST:
        void nuevo_vertice(string nombre);
        
        // PRE:
        // POST:
        int peso_arista(string arista_1, string arista_2);
        
        // PRE:
        // POST:
        int obtener_numero_de_vertices();
    
        //PRE: 
        //POST: 
        Vertice* obtener_vertices();

        //PRE: 
        //POST: Crea un nuevo arco entre dos vertices con un peso especificado en los parametros.
        void nueva_arista(string origen, string destino, int peso);

        //PRE:el nuevo_vertice debe existir
        //POST: valida que exista el vertice que recibe por parametro, si no existe devuelve -1
        int existe_vertice(string nuevo_vertice);

        // PRE:
        // POST:
        int** obtener_matriz_peso();

        //Pre: 
        //Post: 
        void liberar_grafo();
};  



#endif //GRAFO_MATRIZ_PESO_H