#include "lista_lecturas.h"

Lista_lecturas::Lista_lecturas(){
  ultimo = nullptr;
  actual = nullptr;
  cantidad = 0;
}

void Lista_lecturas::alta(Lectura* objeto){
}

void Lista_lecturas::baja(){
}

Lectura* Lista_lecturas::consulta(){

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

