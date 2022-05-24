#ifndef MENU_H
#define MENU_H

#include "lista_lectura.h"
#include "lista_escritor.h"
#include "novela.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"

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

void corroborar_tipo_lectura(char tipo_lectura, string titulo, double minutos, int anio, string escritor);

string pasar_mayuscula(string cadena);

public:
 
    //PRE:-
    //POST:Despliega el menu con opciones
    void desplegar_menu();
};

#endif