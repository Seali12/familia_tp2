#include <iostream>
#include "../header/lector.h"
#include "../header/menu.h"

using namespace std;

int main(){
    Lista_escritor hola;
    Lista_lectura chau;
    Lector a("lecturas.txt", "escritor.txt", chau, hola);

    a.procesar_archivo_escritores();
    a.procesar_archivo_lectura();

    Menu b(a.devolver_lecturas(), a.devolver_escritores());

    while(b.continuar()){
        b.desplegar_menu();
    }
        
    b.eliminar_listas();

    return 0;
}

