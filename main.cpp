#include <iostream>
#include "parser.h"
#include "escritor.h"
#include "lista_lectura.h"
#include "lista_escritor.h"

using namespace std;

int main(){
    Lista_escritor hola;
    Lista_lectura chau;
    Parser a("lecturas.txt", "escritor.txt", chau, hola);

    a.procesar_archivo_escritores();
    a.procesar_archivo_lectura();

    Parser b("lecturas.txt", "escritor.txt", a.devolver_lecturas(), a.devolver_escritores());
    b.mostrar();
    
    b.eliminar_listas();
    return 0;
}

