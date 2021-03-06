#ifndef ALGORITMO_KRUSKAL_H
#define ALGORITMO_KRUSKAL_H

#include "grafo_matriz_peso.h"

class Algoritmo_kruskal{

    private:
        int** matriz;
        
        int* vec_aux;

        int num_vertices;

        Vertice* vertices;

        int infinito = INFINITO;

    public:
        // PRE: construye el algoritmo de kruskal
        // POST: inicializa los valores del algoritmo
        Algoritmo_kruskal(Grafo_matriz_peso peso_grafo, Vertice* vertices);
        
        // PRE: recorre la matriz del kruskal
        // POST: inicializa la matriz
        void recorrer();

        // pre: debe existir un algoritmo de kruskal
        // post: libera la memoria 
        void liberar_kruskal();

    private:

        int encontrar(int buscado);

        //cambiar nombre
        int iguales(int i, int j);

};




#endif //ALGORITMO_KRUSKAL_H