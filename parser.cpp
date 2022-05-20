#include "parser.h"
#include <fstream>
#include <stdlib.h>

Parser::Parser(string archivo_lectura, string archivo_escritor, Lista_lectura lecturas, Lista_escritor escritores){
    this->archivo_lectura = archivo_lectura;
    this->archivo_escritor = archivo_escritor;
    this->lecturas = lecturas;
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
            

            Escritor* nuevo_escritor = new Escritor(referencia, nombre_escritor, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));
            
            
            escritores.alta(nuevo_escritor); 
        }
    escritores.mostrar_lista_escritor();
    }
       
    archivo_escritores.close();
}

void Parser::mostrar(){
    escritores.mostrar_lista_escritor();

    cout << "fin de escritore" << endl;

    lecturas.mostrar_lista_lectura();

    cout << "fin de lecturas" << endl;

}


Parser::~Parser(){
    lecturas.liberar_lista();
    escritores.liberar_lista();
}

void Parser::procesar_archivo_lectura(){
    
    ifstream archivo_lectores(archivo_lectura, ios::in);

    if(!archivo_lectores){
        cout<<"No se pudo abrir el archivo de lectores"<<endl;
    }
    else{
        string tipo_lectura;
        int h = 1;
        while(getline(archivo_lectores, tipo_lectura)){
            cout << "entra al while " << h << " " << tipo_lectura << endl;
            h++;
            
            string titulo, minutos, anio, referencia_escritor,espacio;
            
            getline(archivo_lectores, titulo);
            getline(archivo_lectores, minutos);
            getline(archivo_lectores, anio);
            
            switch (tipo_lectura[CHAR]){
            case N:{
                cout << "switch" << endl;
                string genero;   
                getline(archivo_lectores, genero);
                cout << genero << endl;
                if (genero == "HISTORICA"){
                    
                    string tema_historica;
                    
                    getline(archivo_lectores, tema_historica);
                    getline(archivo_lectores, referencia_escritor);
                    getline(archivo_lectores, espacio);
                   
                    Lectura* nueva_historica = new Novela_historica(titulo, atof(minutos.c_str()), stoi(anio), escritores.consulta(referencia_escritor), genero, tema_historica);
                    
                    lecturas.alta(nueva_historica);
             
                }else{
                    
                    getline(archivo_lectores, referencia_escritor);
                    getline(archivo_lectores, espacio);
 
                    Lectura* nueva_novela = new Novela(titulo, atof(minutos.c_str()), stoi(anio), escritores.consulta(referencia_escritor), genero);
                    
                    lecturas.alta(nueva_novela);
                }
                
                break;
            }
            case P:{
                cout << "switch" << endl;
                string versos;

                getline(archivo_lectores, versos);
                getline(archivo_lectores, referencia_escritor);
                getline(archivo_lectores, espacio);

                Lectura* nuevo_poema = new Poema(titulo, atof(minutos.c_str()), stoi(anio), escritores.consulta(referencia_escritor), stoi(versos));

                lecturas.alta(nuevo_poema);

                break;
            }
            case C:{
                cout << "switch" << endl;
                string titulo_cuento;

                getline(archivo_lectores, titulo_cuento);
                getline(archivo_lectores, referencia_escritor);
                getline(archivo_lectores, espacio);

                Lectura* nuevo_cuento = new Cuento(titulo, atof(minutos.c_str()), stoi(anio), escritores.consulta(referencia_escritor), titulo_cuento);
                cout << "se creo" << endl;
                nuevo_cuento->mostrar();
                lecturas.alta(nuevo_cuento);

                break;
            }      
        }

    }
       
    archivo_lectores.close();
    }
}
