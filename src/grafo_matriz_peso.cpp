#include "../header/grafo_matriz_peso.h"

Grafo_matriz_peso::Grafo_matriz_peso(int valor){

    matriz_peso = new int* [valor];
    
    vertices = new Vertice [valor];

    for(int i = 0; i < valor; i++){
        matriz_peso[i] = new int[valor];
        
        for(int j = 0; j < valor;j++){
            
            matriz_peso[i][j] = INFINITO;
        }
    }
    numero_vertices = 0;
    

}

Grafo_matriz_peso::Grafo_matriz_peso(){
    matriz_peso = nullptr;
    
    vertices = nullptr;

    numero_vertices = 0;
}


//aca puede fallar la memoria si no la eliminamos bien!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Grafo_matriz_peso::nuevo_vertice(string nombre){
    
    bool existe = existe_vertice(nombre) >= 0;
    
    if(!existe){
        Vertice* vertice_nuevo = new Vertice(nombre);
        
        vertice_nuevo->asignar_vertice(numero_vertices);
        
        vertices[numero_vertices++] = *vertice_nuevo;

        delete vertice_nuevo;
    } 
    
}


int Grafo_matriz_peso::peso_arista(string nombre_vertice_1, string nombre_vertice_2){

    int vertice_1, vertice_2;

    vertice_1 = existe_vertice(nombre_vertice_1);
    vertice_2 = existe_vertice(nombre_vertice_2);
    
    
    return matriz_peso[vertice_1][vertice_2];
}


int Grafo_matriz_peso::obtener_numero_de_vertices(){

    return numero_vertices;

}

Vertice* Grafo_matriz_peso::obtener_vertices(){

    return vertices;

}


void Grafo_matriz_peso::nueva_arista(string origen, string destino, int peso){
    
    int vertice_1, vertice_2;
//cmbiar nombre a vertice
    vertice_1 = existe_vertice(origen);
    vertice_2 = existe_vertice(destino);

    matriz_peso[vertice_1][vertice_2] = peso;

}

int Grafo_matriz_peso::existe_vertice(string nuevo_vertice){

    Vertice* vertice_nuevo = new Vertice(nuevo_vertice);

    bool encontrado = false;

    int iterador = 0;

    while(iterador < numero_vertices && !encontrado){
        
        encontrado = vertices[iterador].iguales(*vertice_nuevo);

        if(!encontrado)
            iterador++;
    }

    delete vertice_nuevo;

    return (iterador < numero_vertices) ? iterador : NO_ESTA;

}

int** Grafo_matriz_peso::obtener_matriz_peso(){

    return matriz_peso;

}




