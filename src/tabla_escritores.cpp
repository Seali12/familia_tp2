
#include "../header/tabla_escritores.h"

Tabla_escritores::Tabla_escritores(){
    
    for(int pos = 0; pos < N; pos++){
        
        vector[pos] = nullptr;
    }
}

// O(1) PARA TODO LOS CASOS ES ASI
void Tabla_escritores::alta(Escritor* nuevo_escritor){
    int clave = obtener_clave(nuevo_escritor -> obtener_referencia());
    
    int posicion = clave_hashing(clave);
    
    if(vector[posicion] == nullptr){

        vector[posicion] = new Lista_escritor();
    }
    
    vector[posicion] -> alta(nuevo_escritor); 
}

//O(n) cuando el escritor es el ultimo de la lista
//o(1) cuando el escritor es el primero de la lista
void Tabla_escritores::baja_tabla(string referencia){
    
    int clave = obtener_clave(referencia);
    
    int posicion = clave_hashing(clave);

    
    vector[posicion] -> baja(referencia);
    
    
}
//O(n) cuando el escritor es el ultimo de la lista
//o(1) cuando el escritor es el primero de la lista
Escritor* Tabla_escritores::consulta(string referencia){
    
    int clave = obtener_clave(referencia);
    
    int posicion = clave_hashing(clave);

    return vector[posicion] -> consulta(referencia);
}

void Tabla_escritores::mostrar(){
    
    for(int pos = 0; pos < N; pos++){
        
        if(vector[pos] != nullptr){
            
            vector[pos] -> mostrar_lista_escritor();
        }
    }
}

void Tabla_escritores::eliminar_tabla(){
    
    for(int pos = 0; pos < N; pos++){

        if(vector[pos] != nullptr){

            vector[pos] -> liberar_lista();
            
            delete vector[pos];

        }
    }    
}

int Tabla_escritores::clave_hashing(int clave){
    
    return (clave % N);
}

int Tabla_escritores::obtener_clave(string referencia){
    
    string aux;
    
    for(int pos = INICIO_CLAVE; pos < (int)referencia.length() - 1; pos++){
        
        aux += referencia[pos];
    }
    
    return stoi(aux);
}

void Tabla_escritores::listar_isni_escritor(){

    for(int pos = 0; pos < N; pos++){
        
        if(vector[pos] != nullptr){
            
            vector[pos] -> listar_isni();
        }
    }

}


