#include "lista_lecturas.h"

Lista_lecturas::Lista_lecturas(){
  ultimo = nullptr;
  actual = ultimo;
  nodo_anterior = nullptr;
  cantidad = 0;
}

void Lista_lecturas::alta(Dato objeto){
  Nodo<Dato>* nuevo = new Nodo(objeto);
  ordenar(objeto, nuevo);
  cantidad++;
}

void Lista_lecturas::baja(){
  Nodo<Dato>* borrar = ultimo;
  ultimo = ultimo->obtener_siguiente();
}

void Lista_lecturas::baja(int anio, string titulo){
  desplazar_actual(anio, titulo);

  Nodo<Dato>* borrar = actual;
  nodo_anterior->cambiar_siguiente(actual->obtener_siguiente());
  cantidad--;

  delete borrar;
}

Dato Lista_lecturas::consulta(int anio, string titulo){
  desplazar_actual(anio, titulo);
  return actual->obtener_objeto();
}

bool Lista_lecturas::vacia(){
  return (ultimo == 0);
}

int Lista_lecturas::obtener_cantidad(){
  return cantidad;
}

//REVISAR DESTRUCTOR
Lista_lecturas::~Lista_lecturas(){
  while (! vacia() ){
    baja();
  }
}

void Lista_lecturas::ordenar(Dato objeto, Nodo<Dato>* direccion){
  Nodo<Dato>* siguiente = ultimo;
  Nodo<Dato>* anterior = nullptr;

  while(objeto->obtener_anio() > siguiente->obtener_objeto()->obtener_anio()){
    anterior = siguiente;
    siguiente = siguiente->obtener_siguiente();
  }

  direccion->cambiar_siguiente(siguiente);
  if(anterior != nullptr){
    anterior->cambiar_siguiente(direccion);
  }
}

void Lista_lecturas::desplazar_actual(int anio, string titulo){
  Nodo<Dato>* anterior = ultimo;
  if (actual->obtener_objeto()->obtener_anio() > anio){
    actual = ultimo;
    nodo_anterior = nullptr;
  }
  
  while (actual->obtener_objeto()->obtener_anio() != anio 
  && actual->obtener_objeto()->obtener_titulo() != titulo){
    
    nodo_anterior = actual;
    actual = actual->obtener_siguiente();
  }
}