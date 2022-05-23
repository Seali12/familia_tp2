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

    a.mostrar();
    
    return 0;
}

