#include "parser.h"
#include <fstream>
#include <string>


using namespace std;

Parser::Parser(string archivo_lectura, string archivo_escritor, /*Lista_lectura lecturas*/ Lista_escritor escritores){
    this->archivo_lectura = archivo_lectura;
    this->archivo_escritor = archivo_escritor;
    /*this->lecturas = lecturas;*/
    this->escritores = escritores;

}



void Parser::procesar_archivo_escritores(){

    ifstream archivo_escritores(archivo_escritor, ios::in);
    
    if(!archivo_escritores){
        cout << "No se pudo abrir el archivo de escritores" << endl;
    }
    else{
        string referencia, nombre_escritor, nacionalidad, anio_nacimiento, anio_fallecimiento, espacio;
        while(getline(archivo_escritores, referencia)){
            
            
            getline(archivo_escritores, nombre_escritor);
            
            
            getline(archivo_escritores, nacionalidad);
            
            
            getline(archivo_escritores, anio_nacimiento);
            
            
            if(!anio_nacimiento.empty()){
                getline(archivo_escritores, anio_fallecimiento);
                
            }else{
                anio_nacimiento = "-1";
                
            }
            if(anio_fallecimiento.empty()){
               anio_fallecimiento = "-1";
               
            }else{
                getline(archivo_escritores, espacio);
                
            }   
            

            Escritor nuevo_escritor(referencia, nombre_escritor, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));
            
            
            escritores.alta(nuevo_escritor);
            
        }

    }
       
    archivo_escritores.close();
}

void Parser::mostrar(){
    escritores.mostrar_lista_escritor();

}


Parser::~Parser(){
    escritores.liberar_lista();
}
/*
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
                string titulo;
                
                
                Novela nueva_novela();

                //escrotres.hallarescritor(referencia_escritor_leida) -> necesitamos este metodo en la pila escritores para poder pasarle un escritor a la novela que creemos
                
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
*/



