#include "../header/main_kruskal.h"

Main_kruskal::Main_kruskal(Lista_lectura lecturas){
    
    this->lecturas = lecturas;

    this->total_vertices = lecturas.obtener_cantidad();
}

void Main_kruskal::unir_vertices(Grafo_matriz_peso grafo){
    Lectura *origen;

    Lectura *destino;

    int peso;

    for (int i = 0; i < total_vertices; i++){
        for (int j = 0; j < total_vertices; j++){

            peso = 0;
            origen = grafo.obtener_vertices()[i].obtener_vertice();
            destino = grafo.obtener_vertices()[j].obtener_vertice();

            if (origen->obtener_titulo() != destino->obtener_titulo()){

                if ((origen->obtener_tipo_lectura() == 'N' && destino->obtener_tipo_lectura() == 'C') ||
                    (origen->obtener_tipo_lectura() == 'C' && destino->obtener_tipo_lectura() == 'N')){

                    if (origen->obtener_atributo_especial() == "HISTORICA" || destino->obtener_atributo_especial() == "HISTORICA")
                        peso = 15;

                    else
                        peso = 10;
                }
                else if ((origen->obtener_tipo_lectura() == 'P' && destino->obtener_tipo_lectura() == 'C') ||
                         (origen->obtener_tipo_lectura() == 'C' && destino->obtener_tipo_lectura() == 'P')){
                    
                    peso = 0;
                }

                else if ((origen->obtener_tipo_lectura() == 'N' && destino->obtener_tipo_lectura() == 'P') ||
                         (origen->obtener_tipo_lectura() == 'P' && destino->obtener_tipo_lectura() == 'N')){

                    if (origen->obtener_atributo_especial() == "HISTORICA" || destino->obtener_atributo_especial() == "HISTORICA")
                        peso = 20;

                    else
                        peso = 5;
                }
                else if (origen->obtener_tipo_lectura() == 'N' && destino->obtener_tipo_lectura() == 'N'){

                    if ((origen->obtener_atributo_especial() == "HISTORICA" && destino->obtener_atributo_especial() != "HISTORICA") || 
                            (origen->obtener_atributo_especial() != "HISTORICA" && destino->obtener_atributo_especial() == "HISTORICA"))

                        peso = 60;
                }
                if (origen->obtener_tipo_lectura() == destino->obtener_tipo_lectura()){
                    
                    if (origen->obtener_tipo_lectura() == 'N'){
                       
                        if (origen->obtener_atributo_especial() == "HISTORICA" && destino->obtener_atributo_especial() == "HISTORICA")
                            peso = 80;
                        
                        else
                            peso = 30;
                    }
                    else if (origen->obtener_tipo_lectura() == 'C')
                        peso = 8;
                    else
                        peso = 1;
                    }
            }
            grafo.nueva_arista(grafo.obtener_vertices()[i].obtener_vertice(), grafo.obtener_vertices()[j].obtener_vertice(), peso);
        }
    }
}

void Main_kruskal::ejecutar_kruskal(){
    
    Grafo_matriz_peso grafo(total_vertices);

    for (int pos = 0; pos < total_vertices; pos++){
        
        grafo.nuevo_vertice(lecturas.obtener_lectura(pos));
    }

    unir_vertices(grafo);

   
    cout <<"Vertices del grafo"<<endl;
    cout << " " << endl;

    for (int i = 0; i < total_vertices; i++)
    {
        cout << grafo.obtener_vertices()[i].obtener_vertice()->obtener_titulo() << " " << endl;
    }
    cout << " " << endl;

    Algoritmo_kruskal kruskal(grafo, grafo.obtener_vertices());

    kruskal.recorrer();

    kruskal.liberar_kruskal();

    lecturas.liberar_lista();
}