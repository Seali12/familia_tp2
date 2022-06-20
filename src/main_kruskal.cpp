#include "../header/main_kruskal.h"

void Main_kruskal::ejecutar_kruskal(){
    int total_vertices = CANTIDAD_VERTICES;

    Grafo_matriz_peso grafo(total_vertices);

    grafo.nuevo_vertice(VERTICE_NOVELA);
    grafo.nuevo_vertice(VERTICE_CUENTO);
    grafo.nuevo_vertice(VERTICE_POEMA);
    grafo.nuevo_vertice(VERTICE_POEMA_2);
    grafo.nuevo_vertice(VERTICE_NOVELA_H);
    
    grafo.nueva_arista(VERTICE_CUENTO, VERTICE_NOVELA, 10);
    grafo.nueva_arista(VERTICE_NOVELA, VERTICE_CUENTO, 10);
    grafo.nueva_arista(VERTICE_CUENTO, VERTICE_NOVELA_H, 15);
    grafo.nueva_arista(VERTICE_NOVELA_H, VERTICE_CUENTO, 15);
    grafo.nueva_arista(VERTICE_CUENTO, VERTICE_POEMA ,0);
    grafo.nueva_arista(VERTICE_POEMA, VERTICE_CUENTO ,0);
    grafo.nueva_arista(VERTICE_POEMA, VERTICE_NOVELA , 5);
    grafo.nueva_arista(VERTICE_NOVELA, VERTICE_POEMA , 5);
    grafo.nueva_arista(VERTICE_POEMA, VERTICE_NOVELA_H, 20);
    grafo.nueva_arista(VERTICE_NOVELA_H, VERTICE_POEMA, 20);
    grafo.nueva_arista(VERTICE_NOVELA, VERTICE_NOVELA_H, 60);
    grafo.nueva_arista(VERTICE_NOVELA_H, VERTICE_NOVELA, 60);
    grafo.nueva_arista(VERTICE_POEMA, VERTICE_POEMA_2 , 1);
    grafo.nueva_arista(VERTICE_CUENTO, VERTICE_CUENTO, 8);
    grafo.nueva_arista(VERTICE_NOVELA, VERTICE_NOVELA, 30);
    grafo.nueva_arista(VERTICE_NOVELA_H, VERTICE_NOVELA_H, 80);
    
    cout <<" " << endl;
    cout<<" Vertices del grafo";
    cout <<" " << endl;

    for(int i = 0; i < total_vertices; i++){
        cout << grafo.obtener_vertices()[i].obtener_nombre_vertice()<< " " << endl;
    }
    cout <<" " << endl;
                                                        
    Algoritmo_kruskal kruskal(grafo, grafo.obtener_vertices());
    
    cout << "pasa constructor" << endl;
    kruskal.recorrer();
    cout << "pasa recorrer" << endl;
    //grafo.liberar_grafo();
    kruskal.liberar_kruskal();
    cout << "libero todo" << endl;
}