#include <iostream>
#include "lista_escritor.h"
#include "nodo_simple.h"



Lista_escritor::Lista_escritor(){
  ultimo = nullptr;
  actual = ultimo;
  cantidad = 0;
}

void Lista_escritor::alta(Tipo objeto){
  Nodo<Tipo>* nuevo = new Nodo<Tipo>(objeto);
  
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

bool Lista_escritor::vacia(){
  return (ultimo == 0);
}

int Lista_escritor::obtener_cantidad(){
  return cantidad;
}

//REVISAR DESTRUCTOR
void Lista_escritor::liberar_lista(){
  while (! vacia() ){
    baja();
  }
}


void Lista_escritor::mostrar_lista_escritor(){
  actual = ultimo;
  int i = 0;
  
  while(i < obtener_cantidad()){
    actual->obtener_objeto()->mostrar();
    actual = actual->obtener_siguiente();
    i++;
  }
}


void Lista_escritor::desplazar_actual(string referencia){
  if (actual->obtener_objeto()->obtener_referencia() > referencia){
    actual = ultimo;
    anterior = nullptr;
  }
  
  while (actual->obtener_objeto()->obtener_referencia() != referencia){
    anterior = actual;
    actual = actual->obtener_siguiente();
  }
}






