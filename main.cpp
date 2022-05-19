#include <iostream>
//#include "parser.h"
//#include "lectura.h"
#include "escritor.h"
//#include "lista_lecturas.h"
//#include "pila_escritores.h"
#include <fstream>

using namespace std;

int main(){
    
    ifstream archivo_escritores("escritores.txt", ios::in);
    
    if(!archivo_escritores){
        cout<<"No se pudo abrir el archivo de escritores"<<endl;
    }
    else{
        string referencia, nombre_escritor, nacionalidad, anio_nacimiento, anio_fallecimiento, linea_aux;
        
        while(getline(archivo_escritores, referencia)){
            getline(archivo_escritores, nombre_escritor);
            getline(archivo_escritores, nacionalidad);
            getline(archivo_escritores, anio_nacimiento);
            getline(archivo_escritores, anio_fallecimiento );
            getline(archivo_escritores, linea_aux);
           
            Escritor nuevo_escritor(referencia, nombre_escritor, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));

            nuevo_escritor.mostrar();
            
           
        }

    }
    
    archivo_escritores.close();

    return 0;
}

