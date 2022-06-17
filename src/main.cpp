#include <iostream>
#include "../header/lector.h"
#include "../header/menu.h"
#include "../header/algoritmo_kruskal.h"

using namespace std;

int main(){
   
   /* Lista_escritor escritores;
    Lista_lectura lecturas;
    Lector lector("lecturas.txt", "escritor.txt", lecturas, escritores);

    lector.procesar_archivo_escritores();
    lector.procesar_archivo_lectura();

    Menu menu(lector.devolver_lecturas(), lector.devolver_escritores());

    menu.sid();
    
    while(menu.continuar()){
        menu.desplegar_menu();
    }
        
    menu.eliminar_listas();
    */


    int n = 7;

    Grafo_matriz_peso grafo(n);

    string a = "A";
    string b = "B";
    string c = "C";
    string d = "D";
    string e = "E";
    string f = "F";
    string g = "G";


    grafo.nuevo_vertice(a);
    grafo.nuevo_vertice(b);
    grafo.nuevo_vertice(c);
    grafo.nuevo_vertice(d);
    grafo.nuevo_vertice(e);
    grafo.nuevo_vertice(f);
    grafo.nuevo_vertice(g);


   
    
    grafo.nueva_arista(a, b, 7);
    grafo.nueva_arista(b, a, 7);
    grafo.nueva_arista(a,d,5);
    grafo.nueva_arista(d,a,5);
    grafo.nueva_arista(b, c, 8);
    grafo.nueva_arista(c,b,8);
    grafo.nueva_arista(d,b , 9);
    grafo.nueva_arista(b,e,7);
    grafo.nueva_arista(e,b,7);
    grafo.nueva_arista(e,c,5);
    grafo.nueva_arista(c,e,5);
    grafo.nueva_arista(e,d,15);
    grafo.nueva_arista(d,e,15);  
    grafo.nueva_arista(d,f,6);
    grafo.nueva_arista(f,d,6);
    grafo.nueva_arista(e,f,8);
    grafo.nueva_arista(f,e,8);
    grafo.nueva_arista(e,g,9);
    grafo.nueva_arista(g,e,9);
    grafo.nueva_arista(f,g,11);
    grafo.nueva_arista(g,f,11);

    cout<<" Vertices del grafo"<<endl;

    for(int i = 0; i < n; i++){
        cout << grafo.obtener_vertices()[i].obtener_nombre_vertice()<< " " << endl;
    }
    cout <<" " << endl;
                                                        
    Algoritmo_kruskal kruskal(grafo, grafo.obtener_vertices());
  
    kruskal.recorrer();
    
    grafo.liberar_grafo();
    kruskal.liberar_kruskal();



   
    return 0;
}





