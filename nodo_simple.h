#ifndef NODO_H
#define NODO_H

template < class dato >
class Nodo{
  public:
    //Constructor  
    Nodo(dato objeto);

    //PRE: El nodo no tiene que estar vacio.
    //POST: Devuelve el dato que almacena.
    dato obtener_objeto() const;

    //PRE: "Siguiente" debe ser un puntero a Nodo.
    //POST: Devuelve la direccion que almacena de otro nodo.
    Nodo* obtener_siguiente() const;

    //PRE: El nuevo dato debe ser del mismo tipo del que estaba antes. 
    //POST: Cambia el dato que estaba almacenado por otro.
    void cambiar_objeto(dato* nuevo_objeto);

    //PRE: La nueva direccion debe ser de tipo puntero a Nodo.
    //POST: Cambia el puntero a Nodo por uno nuevo.
    void cambiar_siguiente(Nodo* nueva_direccion);

    void eliminar_objeto();
  private:
    dato objeto;
    Nodo<dato>* direccion;
};

template < typename dato >
Nodo<dato>::Nodo(dato objeto){
  this->objeto = objeto;
  this->direccion = 0;
}

template < typename dato >
dato Nodo<dato>::obtener_objeto() const {
  return objeto;
}

template < typename dato >
Nodo<dato> *Nodo<dato>::obtener_siguiente() const {
  return direccion;
}

template < typename dato >
void Nodo<dato>::cambiar_objeto(dato* nuevo_objeto){
  this->objeto = nuevo_objeto;
}

template < typename dato >
void Nodo<dato>::cambiar_siguiente(Nodo<dato>* nueva_direccion){
  this->direccion = nueva_direccion;
}

template < typename dato >
void Nodo<dato>::eliminar_objeto(){
  delete []objeto;
  objeto = nullptr;
}

#endif // !NODO_H
