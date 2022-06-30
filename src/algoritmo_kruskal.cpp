#include "../header/algoritmo_kruskal.h"
#include "../header/colores.h"

Algoritmo_kruskal::Algoritmo_kruskal(Grafo_matriz_peso peso_grafo, Vertice* vertices){
    
    this -> num_vertices = peso_grafo.obtener_numero_de_vertices();
    
    this -> matriz = peso_grafo.obtener_matriz_peso();
    
    this -> vertices = vertices;
    
    vec_aux = new int [this -> num_vertices + 1];
    
    for(int i = 0; i < this -> num_vertices + 1; i++){
        vec_aux[i] = 0;
    }
}

void Algoritmo_kruskal::recorrer(){
    int i = 0, j = 0, minimo = 0, minimo_costo = 0;

    int aux_1 = 1, aux_2 = 0, aux_3 = 0, aux_4 = 0, aux_5 = 0;
    
    cout << NEGRITA_MAGENTA "CAMINO MINIMO:" NEGRITA_ROJO << endl;

    while(aux_1 < num_vertices){
        
        for(i = 1, minimo = INFINITO; i <= num_vertices; i++){
        
            for( j = 1; j <= num_vertices; j++){
        
                if(matriz[i-1][j-1] < minimo){
                    
                    minimo = matriz[i-1][j-1],
                    aux_2 = aux_3 = i;
                    aux_4 = aux_5 = j;
                }
            }

        }
        aux_3 = encontrar(aux_3);
        aux_5 = encontrar(aux_5);

        if(iguales(aux_3, aux_5)){
            aux_1++;
            
            Lectura* titulo_1 = vertices[aux_2-1].obtener_vertice();
            Lectura* titulo_2 = vertices[aux_4-1].obtener_vertice();
            
            cout << NEGRITA_CYAN " Arista entre las Lecturas: " NEGRITA_ROJO << titulo_1 -> obtener_titulo()
            << NEGRITA_CYAN " y : " NEGRITA_ROJO << titulo_2 -> obtener_titulo() << NEGRITA_CYAN ", lleva un tiempo de: " NEGRITA_ROJO << minimo << NEGRITA_CYAN" minutos" << endl;
            
            minimo_costo += minimo;
        }
        matriz[aux_2-1][aux_4-1] = matriz[aux_4-1][aux_2-1] = INFINITO;

    }
    cout << " " << endl;
    
    cout << NEGRITA_MAGENTA "El costo minimo total es: " NEGRITA_CYAN << minimo_costo << endl;
}


int Algoritmo_kruskal::encontrar(int buscado){
    
    while(vec_aux[buscado] > 0){
        
        buscado = vec_aux[buscado];
    }
    return buscado;
}

int Algoritmo_kruskal::iguales(int i, int j){
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