#include <iostream>
#include "parser.h"
#include "lectura.h"
#include "escritor.h"
//#include "lista_lectura.h"
#include "lista_escritor.h"
#include <fstream>

using namespace std;

int main(){
    Lista_escritor hola;
    
    Parser a("lecturas.txt", "escritor.txt", hola);
    //Lista_lectura chau;
    a.procesar_archivo_escritores();
    a.mostrar();
    
    return 0;
}

