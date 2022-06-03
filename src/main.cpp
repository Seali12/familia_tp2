#include <iostream>
#include "../header/lector.h"
#include "../header/menu.h"

using namespace std;

int main(){
    Lista_escritor hola;
    Lista_lectura chau;
    Lector Lector_1("lecturas.txt", "escritor.txt", chau, hola);

    Lector_1.procesar_archivo_escritores();
    Lector_1.procesar_archivo_lectura();

    Menu Menu_1(Lector_1.devolver_lecturas(), Lector_1.devolver_escritores());

    Menu_1.sid();
    
    while(Menu_1.continuar()){
        Menu_1.desplegar_menu();
    }
        
    Menu_1.eliminar_listas();

    return 0;
}



