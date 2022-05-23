#ifndef MENU_H
#define MENU_H

#include "lista_lectura.h"
#include "lista_escritor.h"


class Menu{

private:

Lista_escritor escritores;

Lista_lectura lecturas;

bool seguir;

void agregar_nueva_lectura();

void quitar_lectura();

void agregar_escritor();

void cambiar_fecha_escritor();

void listar_escritores();

void sortear_lectura();

void listar_todas_lecturas();

void listar_lecturas_anios();

void listar_lecturas_escritor();

void listar_novela_genero();

void cola_tiempo_lectura();

void salir();


public:
 
    //PRE:-
    //POST:Despliega el menu con opciones
    void desplegar_menu();

    




};





#endif