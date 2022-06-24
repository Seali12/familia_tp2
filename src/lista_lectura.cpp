#include "../header/lista_lectura.h"

Lista_lectura::Lista_lectura(){
  ultimo = nullptr;
  actual = ultimo;
  nodo_anterior = nullptr;
  cantidad = 0;
}

void Lista_lectura::alta(Lectura* objeto){
  Nodo<Lectura*>* nuevo = new Nodo<Lectura*>(objeto);
  
  ordenar(objeto, nuevo);
  cantidad++;
}

void Lista_lectura::baja(){
  Nodo<Lectura*>* borrar = ultimo;

  ultimo = ultimo->obtener_siguiente();

  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

void Lista_lectura::baja(string titulo){
  
  reiniciar_actual();

  while(actual->obtener_objeto()->obtener_titulo() != titulo){
      desplazar_actual(actual);
  }

  Nodo<Lectura*>* borrar = actual;
  nodo_anterior->cambiar_siguiente(actual->obtener_siguiente());
  cantidad--;

  borrar->eliminar_objeto();
  delete borrar;
}

Lectura* Lista_lectura::consulta(string titulo){
  
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
  reiniciar_actual();
  int i = 0;
  
  while(i < obtener_cantidad()){
    actual->obtener_objeto()->mostrar();
    actual = actual->obtener_siguiente();
    i++;
  }
}

void Lista_lectura::mostrar_rango(int anio_min, int anio_max ){
  cout << NEGRITA_ROJO << endl;
  reiniciar_actual();
  
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

void Lista_lectura::lectura_random(int numero_rand){
  
  reiniciar_actual();
  int iterador = 0;

  while(iterador < numero_rand){
    
    desplazar_actual(actual);
    iterador++;

  }
  cout << NEGRITA_ROJO << endl;
  actual->obtener_objeto()->mostrar();
}

Lectura* Lista_lectura::obtener_lectura(int posicion){
  reiniciar_actual();
  int iterador = 0;

  while(iterador < posicion){
    
    desplazar_actual(actual);
    iterador++;

  }
  cout << NEGRITA_ROJO << endl;
  return actual->obtener_objeto();
}

bool Lista_lectura::genero_no_encontrado(string genero){
  return (genero != "TERROR" and genero != "HISTORICA" and genero != "COMEDIA" 
            and genero != "FICCION" and genero != "ROMANCE" and genero != "DRAMA" and genero != "SUSPENSO");
}

void Lista_lectura::listar_por_genero(string genero){
  cout << NEGRITA_ROJO << endl;
  reiniciar_actual();
 
  if(genero_no_encontrado(genero))
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
  reiniciar_actual();

  int contador_lecturas = 0;
  while(actual != nullptr){
    
    if(actual->obtener_objeto()->obtener_escritor()->obtener_nombre_y_apellido() == referencia 
        or actual->obtener_objeto()->obtener_escritor()->obtener_referencia() == referencia){
            
        actual->obtener_objeto()->mostrar();
        contador_lecturas++;
      }   

      desplazar_actual(actual);
    }

    if(!contador_lecturas){
      cout << "El escritor no se encuentra en la lista" << endl;
    }
    
}

void Lista_lectura::liberar_lista(){
  while (!vacia()){
    baja();
  }
}

Lectura* Lista_lectura::consulta(double &minimo){
  reiniciar_actual();
    
  double minimo_max = 0;
    
  Lectura* lectura_minima = nullptr;

  for(int iterador = 0; iterador < obtener_cantidad(); iterador++){
      
    double minutos_objeto = actual->obtener_objeto()->obtener_minutos();
      
    if(minimo_max == 0 and minimo < minutos_objeto){
        
      minimo_max = minutos_objeto;
      lectura_minima = actual->obtener_objeto();
    }

    else if(minimo < minutos_objeto and minutos_objeto < minimo_max){
      minimo_max = minutos_objeto;
      lectura_minima = actual->obtener_objeto();
    }
    if(!es_ultimo(actual)){
      desplazar_actual(actual);
    }
  }
  minimo = minimo_max;
      
  return lectura_minima;
}

bool Lista_lectura::es_ultimo(Nodo<Lectura*>*nodo){
  return (nodo->obtener_siguiente() == nullptr);
}

void Lista_lectura::ordenar(Lectura* objeto, Nodo<Lectura*>* direccion){
  Nodo<Lectura*>* siguiente = ultimo;
  Nodo<Lectura*>* anterior = nullptr;

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

void Lista_lectura::desplazar_actual(Nodo<Lectura*>* nodo_actual){
  
  nodo_anterior = nodo_actual;
  actual = nodo_actual->obtener_siguiente();
}

void Lista_lectura::reiniciar_actual(){
  actual = ultimo;
}

