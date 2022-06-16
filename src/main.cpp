#include <iostream>
#include "../header/lector.h"
#include "../header/menu.h"

using namespace std;

int main(){
    Lista_escritor escritores;
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

    return 0;
}



