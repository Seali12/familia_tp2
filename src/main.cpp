#include <iostream>
#include "../header/lector.h"
#include "../header/menu.h"
#include "../header/main_kruskal.h"

using namespace std;

int main(){
   
    Tabla_escritores escritores;
    
    Lista_lectura lecturas;
    
    Lector lector("lecturas.txt", "escritor.txt", lecturas, escritores);
    
    lector.procesar_archivo_escritores();

    lector.procesar_archivo_lectura();

    lector.devolver_escritores().mostrar();
    
    lector.devolver_escritores().eliminar_tabla();
    
    /* Menu menu(lector.devolver_lecturas(), lector.devolver_escritores());
    cout << "pasa menu" << endl;
    menu.sid();
    
    while(menu.continuar()){
        menu.desplegar_menu();
    }
       
    menu.eliminar_listas();
    
*/
    Main_kruskal arbol_minimo(lector.devolver_lecturas());

    arbol_minimo.ejecutar_kruskal();
    
    


    
   
    return 0;
}





