
#ifndef MAIN_KRUSKAL_H
#define MAIN_KRUSKAL_H

#include "algoritmo_kruskal.h"

const string VERTICE_NOVELA = "Novela";
const string VERTICE_CUENTO = "Cuento";
const string VERTICE_POEMA = "Poema";
const string VERTICE_NOVELA_H = "Novela_H";
const string VERTICE_POEMA_2 = "Poema_2";
const int CANTIDAD_VERTICES = 5;

//Para no crear el grafo e imprimir en el main, llamamos a kruskal y listo
class Main_kruskal{

    public:
       //PRE:
       //POST: Arma el grafo y aplica el algortimo de Kruskal para calcular el arbol de minimos caminos
       void ejecutar_kruskal();

    
};

#endif//MAIN_KRUSKAL



