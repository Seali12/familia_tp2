#ifndef ARBOL_MINIMO_H
#define ARBOL_MINIMO_H

#include "algoritmo_kruskal.h"
#include "lista_lectura.h"

//Para no crear el grafo e imprimir en el main, ejecutamos kruskal y creamos el grafo a partir de esta clase.
class Arbol_minimo{

    private:
        Lista_lectura lecturas;

        int total_vertices;


    public:
        //PRE:
        //POST: Arma el grafo y aplica el algortimo de Kruskal para calcular el arbol de minimos caminos
        void ejecutar_kruskal();

        Arbol_minimo();

        void cargar(Lista_lectura lecturas);

    private:
        //valida los pesos y une vertices
        void unir_vertices(Grafo_matriz_peso grafo);
            
};

#endif//MAIN_KRUSKAL



