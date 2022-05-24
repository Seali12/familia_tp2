#include <iostream>
#include "lista_escritor.h"
#include "nodo_simple.h"

Lista_escritor::Lista_escritor(){
  ultimo = nullptr;
  actual = nullptr;
  cantidad = 0;
}

void Lista_escritor::alta(Tipo objeto){
  Nodo<Tipo>* nuevo = new Nodo<Tipo>(objeto);
  //actual = ultimo;
  
  nuevo->cambiar_siguiente(ultimo);
  ultimo = nuevo;
  
  cantidad++;
}

void Lista_escritor::baja(){
  Nodo<Tipo>* borrar = ultimo;
  ultimo = ultimo->obtener_siguiente();

  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

void Lista_escritor::baja(string nombre_y_apellido){
  desplazar_actual(nombre_y_apellido);

  Nodo<Tipo>* borrar = actual;
  anterior->cambiar_siguiente(actual->obtener_siguiente());
  
  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

Tipo Lista_escritor::consulta(string referencia_escritor){
  desplazar_actual(referencia_escritor);
  return actual->obtener_objeto();
}

void Lista_escritor::modificar_fallecimiento(string nombre_y_apellido, int anio_ingresado){
  desplazar_actual(nombre_y_apellido);
  actual->obtener_objeto()->modificar_anio_fallecimiento(anio_ingresado);

}

bool Lista_escritor::referencia_repetida(string referencia){
  desplazar_actual(referencia);
  return (actual->obtener_siguiente() != nullptr and actual->obtener_objeto()->obtener_referencia() != referencia);
}

bool Lista_escritor::vacia(){
  return (ultimo == 0);
}

int Lista_escritor::obtener_cantidad(){
  return cantidad;
}

void Lista_escritor::liberar_lista(){
  while (! vacia() ){
    baja();
  }
}


void Lista_escritor::mostrar_lista_escritor(){
  cout << NEGRITA_ROJO << endl;
  actual = ultimo;
  int i = 0;
  
  while(i < obtener_cantidad()){
    
    actual->obtener_objeto()->mostrar();
    actual = actual->obtener_siguiente();
    i++;
  
  }
}


void Lista_escritor::desplazar_actual(string referencia){
  actual = ultimo;
  anterior = nullptr;
  
  while (actual->obtener_objeto()->obtener_referencia() != referencia 
          and actual->obtener_objeto()->obtener_nombre_y_apellido() != referencia and actual->obtener_siguiente() != nullptr){
            
    anterior = actual;
    actual = actual->obtener_siguiente();
  }
}
