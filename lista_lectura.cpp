#include "lista_lectura.h"

Lista_lectura::Lista_lectura(){
  ultimo = nullptr;
  actual = ultimo;
  nodo_anterior = nullptr;
  cantidad = 0;
}

void Lista_lectura::alta(Dato objeto){
  Nodo<Dato>* nuevo = new Nodo<Dato>(objeto);

  cout << nuevo->obtener_objeto()->obtener_titulo() << endl;
  
  ordenar(objeto, nuevo);
  cantidad++;

  mostrar_lista_lectura();
}

void Lista_lectura::baja(){
  Nodo<Dato>* borrar = ultimo;

  ultimo = ultimo->obtener_siguiente();

  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

void Lista_lectura::baja(int anio, string titulo){
  desplazar_actual(anio, titulo);

  Nodo<Dato>* borrar = actual;
  nodo_anterior->cambiar_siguiente(actual->obtener_siguiente());
  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

Dato Lista_lectura::consulta(int anio, string titulo){
  desplazar_actual(anio, titulo);
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
 

void Lista_lectura::desplazar_actual(int anio, string titulo){
  if (actual->obtener_objeto()->obtener_anio() > anio){
    actual = ultimo;
    nodo_anterior = nullptr;
  }
  
  while (actual->obtener_objeto()->obtener_anio() != anio 
  and actual->obtener_objeto()->obtener_titulo() != titulo){
    
    nodo_anterior = actual;
    actual = actual->obtener_siguiente();
  }
}