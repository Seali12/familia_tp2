#include "parser.h"
#include <fstream>
#include <string>


using namespace std;

Parser::Parser(string archivo_lectura, string archivo_escritor, Lista lecturas, Pila escritores){
    this->archivo_lectura = archivo_lectura;
    this->archivo_escritor = archivo_escritor;
    this->lecturas = lecturas;
    this->escritores = escritores;

}



void Parser::procesar_archivo_escritores(){

    ifstream archivo_escritores(archivo_escritor, ios::in);
    
    if(!archivo_escritores){
        cout<<"No se pudo abrir el archivo de escritores"<<endl;
    }
    else{
        string referencia, nombre_escritor, nacionalidad, anio_nacimiento, anio_fallecimiento, espacio;
        while(getline(archivo_escritores, referencia)){
           
            getline(archivo_escritores, nombre_escritor);
            getline(archivo_escritores, nacionalidad);
            getline(archivo_escritores, anio_nacimiento);       
            getline(archivo_escritores, anio_fallecimiento);
            getline(archivo_escritores, espacio);

            Escritor nuevo_escritor(referencia, nombre_escritor, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));
            escritores.alta(nuevo_escritor);
        }

    }
       
    archivo_escritores.close();
}
void Parser::procesar_archivo_lectura(){
    
    ifstream archivo_lectores(archivo_lectura, ios::in);

    if(!archivo_lectores){
        cout<<"No se pudo abrir el archivo de lectores"<<endl;
    }
    else{
        string tipo_lectura;
        
        while(getline(archivo_lectores, tipo_lectura)){

            switch (tipo_lectura[0]){
            case 'N':
                strin titulo
                
                
                Novela nueva_novela();
                
                getline(archivo_lectores, );
                getline(archivo_lectores, );
                getline(archivo_lectores, );       
                getline(archivo_lectores, );
                getline(archivo_lectores, );

                break;
            
            case 'P':

                break;

            case 'C':
            
                break;
            
            default:
                break;
            }

          
        }

    }
       
    archivo_lectores.close();
}




