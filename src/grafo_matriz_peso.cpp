#include "../header/grafo_matriz_peso.h"

Grafo_matriz_peso::Grafo_matriz_peso(int valor)
{

    matriz_peso = new int *[valor];

    vertices = new Vertice[valor];

    for (int i = 0; i < valor; i++)
    {
        matriz_peso[i] = new int[valor];

        for (int j = 0; j < valor; j++)
        {

            matriz_peso[i][j] = INFINITO;
        }
    }
    numero_vertices = 0;
}

Grafo_matriz_peso::Grafo_matriz_peso()
{
    matriz_peso = nullptr;

    vertices = nullptr;

    numero_vertices = 0;
}

// aca puede fallar la memoria si no la eliminamos bien!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Grafo_matriz_peso::nuevo_vertice(Lectura *nueva_lectura)
{
    
    bool existe = existe_vertice(nueva_lectura) >= 0;
    
    if (!existe)
    {
        Vertice *vertice_nuevo = new Vertice(nueva_lectura);

        vertice_nuevo->asignar_vertice(numero_vertices);

        vertices[numero_vertices++] = *vertice_nuevo;

        delete vertice_nuevo;
    }
}

int Grafo_matriz_peso::peso_arista(Lectura* lectura_vertice_1, Lectura* lectura_vertice_2)
{

    int vertice_1, vertice_2;

    vertice_1 = existe_vertice(lectura_vertice_1);
    vertice_2 = existe_vertice(lectura_vertice_2);

    return matriz_peso[vertice_1][vertice_2];
}

int Grafo_matriz_peso::obtener_numero_de_vertices()
{

    return numero_vertices;
}

Vertice *Grafo_matriz_peso::obtener_vertices()
{

    return vertices;
}

void Grafo_matriz_peso::nueva_arista(Lectura* lectura_origen, Lectura* lectura_destino, int peso)
{

    int vertice_1, vertice_2;
    // cmbiar nombre a vertice
    vertice_1 = existe_vertice(lectura_origen);
    vertice_2 = existe_vertice(lectura_destino);

    matriz_peso[vertice_1][vertice_2] = peso;
}

int Grafo_matriz_peso::existe_vertice(Lectura* nueva_lectura)
{

    Vertice *vertice_nuevo = new Vertice(nueva_lectura);

    bool encontrado = false;

    int iterador = 0;

    while (iterador < numero_vertices && !encontrado)
    {

        encontrado = vertices[iterador].iguales(*vertice_nuevo);

        if (!encontrado)
            iterador++;
    }

    delete vertice_nuevo;

    return (iterador < numero_vertices) ? iterador : NO_ESTA;
}

int **Grafo_matriz_peso::obtener_matriz_peso()
{

    return matriz_peso;
}
