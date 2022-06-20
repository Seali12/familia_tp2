#ifndef MENU_H
#define MENU_H

#include "colores.h"
#include "lista_lectura.h"
#include "tabla_escritores.h"
#include "novela.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"
#include "cola.h"

enum Opciones{
    
    AGREGAR_LECTURA = 1,
    QUITAR_LECTURA,
    AGREGAR_ESCRITOR,
    CAMBIAR_DATO_ESCRITOR,
    LISTAR_ESCRITORES,
    SORTEAR_RANDOM,
    LISTAR_LECTURAS,
    LISTAR_LECTURAS_ANIO,
    LISTAR_LECTURAS_ESCRITOR,
    LISTAR_NOVELAS_GENERO,
    ARMAR_COLA,
    SALIR,
    
};

class Menu{

private:

Tabla_escritores escritores;

Lista_lectura lecturas;

Cola cola_lecturas;

bool seguir;

void agregar_nueva_lectura();

void quitar_lectura();

void agregar_escritor();

void cambiar_fecha_escritor();

void listar_escritores();

void sortear_lectura();

void listar_todas_lecturas();

void listar_lecturas_anios();

void listar_lecturas_rango();

void listar_novela_genero();

void listar_lecturas_escritor();

void cola_tiempo_lectura();

void salir();

void opciones(int opcion);

void corroborar_tipo_lectura(char tipo_lectura, string titulo, double minutos, int anio, string escritor);

string pasar_mayuscula(string cadena);

void armar_cola();

void limpiar_consola();

public:
 
    //PRE:
    //POST: Construye un objeto Menu.
    Menu(Lista_lectura lecturas, Tabla_escritores escritores);
    
    //PRE: Debe existir un menu previamente creado.
    //POST:Despliega el menu con opciones.
    void desplegar_menu();

    //PRE: Debe existir un menu previamente creado.
    //POST: Devuelve true si el usuario quiere seguir consultado sino false.
    bool continuar();

    //PRE: Deben existir las listas a eliminar.
    //POST: Elimina las listas y libera la memoria ocupada por ella.
    void eliminar_listas();

    //PRE: -
    //POST: Imprime por pantalla la imagen de Sid.
    void sid();

    //Destructor
    ~Menu(){};
};

#endif