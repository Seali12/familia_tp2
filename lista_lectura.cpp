#include "lista_lectura.h"

Lista_lectura::Lista_lectura(){
  ultimo = nullptr;
  actual = ultimo;
  nodo_anterior = nullptr;
  cantidad = 0;
}

void Lista_lectura::alta(Dato objeto){
  Nodo<Dato>* nuevo = new Nodo<Dato>(objeto);
  
  ordenar(objeto, nuevo);
  cantidad++;
}

void Lista_lectura::baja(){
  Nodo<Dato>* borrar = ultimo;

  ultimo = ultimo->obtener_siguiente();

  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

void Lista_lectura::baja(string titulo){
  
  actual = ultimo;

  while(actual->obtener_objeto()->obtener_titulo() != titulo){
      desplazar_actual(actual);
  }

  Nodo<Dato>* borrar = actual;
  nodo_anterior->cambiar_siguiente(actual->obtener_siguiente());
  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

Dato Lista_lectura::consulta(string titulo){
  
  while (actual->obtener_objeto()->obtener_titulo() != titulo){
    desplazar_actual(actual);
  }

  return actual->obtener_objeto();
}

bool Lista_lectura::vacia(){
  return (ultimo == 0);
}

int Lista_lectura::obtener_cantidad(){
  return cantidad;
}

void Lista_lectura::mostrar_lista_lectura(){
  actual = ultimo;
  int i = 0;
  
  while(i < obtener_cantidad()){
    actual->obtener_objeto()->mostrar();
    actual = actual->obtener_siguiente();
    i++;
  }
}

//REVISAR DESTRUCTOR
void Lista_lectura::liberar_lista(){
  while (! vacia() ){
    baja();
  }
}

bool Lista_lectura::es_ultimo(Nodo<Dato>*nodo){
  return (nodo->obtener_siguiente()== 0);
}


void Lista_lectura::ordenar(Dato objeto, Nodo<Dato>* direccion){
  Nodo<Dato>* siguiente = ultimo;
  Nodo<Dato>* anterior = nullptr;

  if (vacia()){
    ultimo = direccion;
  }else{
    while(!es_ultimo(siguiente) and objeto->obtener_anio() > siguiente->obtener_objeto()->obtener_anio()){

      anterior = siguiente;
      siguiente = siguiente->obtener_siguiente();
    }

    if(es_ultimo(siguiente)){
      siguiente->cambiar_siguiente(direccion);
    }else{
      direccion->cambiar_siguiente(siguiente);
      if(anterior != nullptr){
        anterior->cambiar_siguiente(direccion);
      }else{
        ultimo = direccion;
      }
    }
  }
}



void Lista_lectura::lectura_random(int numero_rand){
  
  actual = ultimo;
  int iterador = 0;

  while(iterador < numero_rand){
    
    desplazar_actual(actual);
    iterador++;

  }
  
  actual->obtener_objeto()->mostrar();
}



void Lista_lectura::listar_por_genero(string genero){
  actual = ultimo;
 
  if(genero != "TERROR" || genero != "HISTORICA" || genero != "COMEDIA" 
          || genero != "FICCION" || genero != "ROMANTICA" || genero != "DRAMA" || genero != "SUSPENSO")

          cout << "El genero ingresado no existe, los generos son: TERROR, HISTORICA, FICCION, COMEDIA, ROMANTICA, DRAMA, SUSPENSO " << endl;
  
  else{ 
    while(!es_ultimo(actual)){
    
      if(actual->obtener_objeto()->obtener_tipo_lectura() == 'N' 
            and actual->obtener_objeto()->obtener_atributo_especial() == genero)
            
              actual->obtener_objeto()->mostrar();
          
      desplazar_actual(actual);
  
    }
  }
      
      
}

void Lista_lectura::listar_por_escritor(string nombre_escritor){

  actual = ultimo;

  while(!es_ultimo(actual)){
    
      if(actual->obtener_objeto()->obtener_escritor()->obtener_nombre_y_apellido() == nombre_escritor)
            
              actual->obtener_objeto()->mostrar();
          
      desplazar_actual(actual);
  
    }
}

void Lista_lectura::desplazar_actual(Nodo<Dato>* nodo_actual){
  
  nodo_anterior = nodo_actual;
  actual = nodo_actual->obtener_siguiente();
}


void Lista_lectura::mostrar_rango(int anio_min, int anio_max ){
  
  actual = ultimo;
  
  while (actual->obtener_objeto()->obtener_anio() < anio_max and !es_ultimo(actual)){

    if (actual->obtener_objeto()->obtener_anio() > anio_min)
        
        actual->obtener_objeto()->mostrar();
    
    desplazar_actual(actual);
  }
  
  actual->obtener_objeto()->mostrar();

}


