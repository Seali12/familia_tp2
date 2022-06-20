#include "../header/algoritmo_kruskal.h"


Algoritmo_kruskal::Algoritmo_kruskal(Grafo_matriz_peso peso_grafo, Vertice* vertices){
    
    this->num_vertices = peso_grafo.obtener_numero_de_vertices();
    
    this->matriz = peso_grafo.obtener_matriz_peso();
    
    this->vertices = vertices;
    
    vec_aux = new int [this->num_vertices+1];
    for(int i = 0; i < this->num_vertices + 1; i++){
        vec_aux[i] = 0;
    }
}

void Algoritmo_kruskal::recorrer(){
    int i = 0, j = 0, minimo = 0, minimo_costo = 0;

    int aux_1 = 1, aux_2 = 0, aux_3 = 0, aux_4 = 0, aux_5 = 0;
    
    cout << "CAMINO MINIMO:" << endl;

    while(aux_1 < num_vertices){
        
        for(i = 1, minimo = INFINITO; i <= num_vertices; i++){
        
            for( j = 1; j <= num_vertices; j++){
        
                if( matriz[i-1][j-1] < minimo ){
                    
                    minimo = matriz[i-1][j-1],
                    aux_2 = aux_3 = i;
                    aux_4 = aux_5 = j;
                }
            }

        }
        aux_3 = encontrar(aux_3);
        aux_5 = encontrar(aux_5);

        if(uni(aux_3, aux_5)){
            aux_1++;
            cout << " Arista entre Vertice: " << vertices[aux_2-1].obtener_nombre_vertice()
            << " y Vertice: " << vertices[aux_4-1].obtener_nombre_vertice() << ", lleva un timepo de: "<< minimo << " minutos" << endl;
            minimo_costo += minimo;
        }
        matriz[aux_2-1][aux_4-1] = matriz[aux_4-1][aux_2-1]= INFINITO;

    }
    cout << " " << endl;
    
    cout<< "El costo minimo total es: "<< minimo_costo << endl;
}


int Algoritmo_kruskal::encontrar(int buscado){
    
    while(vec_aux[buscado] > 0){
        
        buscado = vec_aux[buscado];
    }
    return buscado;
}

int Algoritmo_kruskal::uni(int i, int j){
    int condicion = 0;
    
    if( i != j){
        
        vec_aux[j] = i;
        
        condicion = 1;
    }
    return condicion;
}


void Algoritmo_kruskal::liberar_kruskal(){
    
    delete [] vertices;

    delete [] vec_aux;

    for(int i = 0; i < num_vertices; i++){
        
        delete [] matriz[i];
    }
    
    delete [] matriz;

}