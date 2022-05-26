#include "../header/lista_lectura.h"

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
  cout << NEGRITA_ROJO << endl;
  actual = ultimo;
  int i = 0;
  
  while(i < obtener_cantidad()){
    actual->obtener_objeto()->mostrar();
    actual = actual->obtener_siguiente();
    i++;
  }
}

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

    if(objeto->obtener_anio() > siguiente->obtener_objeto()->obtener_anio()){
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
  cout << NEGRITA_ROJO << endl;
  actual->obtener_objeto()->mostrar();
}



void Lista_lectura::listar_por_genero(string genero){
  cout << NEGRITA_ROJO << endl;
  actual = ultimo;
 
  if(genero != "TERROR" and genero != "HISTORICA" and genero != "COMEDIA" 
          and genero != "FICCION" and genero != "ROMANCE" and genero != "DRAMA" and genero != "SUSPENSO")

    cout << BLANCO "El genero ingresado no existe, los generos son: TERROR, HISTORICA, FICCION, COMEDIA, ROMANTICA, DRAMA, SUSPENSO " NEGRITA_ROJO << endl;
  
  else{ 

    bool seguir = true;
    while(seguir){
    
      if(actual->obtener_objeto()->obtener_tipo_lectura() == 'N' 
            and actual->obtener_objeto()->obtener_atributo_especial() == genero){
            
        actual->obtener_objeto()->mostrar();
      }
      if (!es_ultimo(actual)){
        desplazar_actual(actual);
      }else{
        seguir = false;
      }
    }
  }   
}

void Lista_lectura::listar_por_escritor(string referencia){
  cout << NEGRITA_ROJO << endl;
  actual = ultimo;

  while(!es_ultimo(actual)){
    
      if(actual->obtener_objeto()->obtener_escritor()->obtener_nombre_y_apellido() == referencia 
        or actual->obtener_objeto()->obtener_escritor()->obtener_referencia() == referencia){
            
        actual->obtener_objeto()->mostrar();
      }   

      desplazar_actual(actual);
    }
}

void Lista_lectura::desplazar_actual(Nodo<Dato>* nodo_actual){
  
  nodo_anterior = nodo_actual;
  actual = nodo_actual->obtener_siguiente();
}


void Lista_lectura::mostrar_rango(int anio_min, int anio_max ){
  cout << NEGRITA_ROJO << endl;
  actual = ultimo;
  
  while (actual->obtener_objeto()->obtener_anio() <= anio_max and !es_ultimo(actual)){

    if (actual->obtener_objeto()->obtener_anio() >= anio_min){
        
      actual->obtener_objeto()->mostrar();
    }

    desplazar_actual(actual);
  }

  if (actual->obtener_objeto()->obtener_anio() <= anio_max){
    actual->obtener_objeto()->mostrar();
  }
}