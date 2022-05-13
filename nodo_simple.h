#ifndef NODO_H
#define NODO_H

template < class dato >
class Nodo{
  public:
    Nodo(dato objeto);

    dato obtener_objeto() const;

    Nodo* obtener_siguiente() const;

    void cambiar_objeto(dato nuevo_objeto);

    void cambiar_siguiente(Nodo* nueva_direccion);

  private:
    dato objeto;
    Nodo* direccion;
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
void Nodo<dato>::cambiar_objeto(dato nuevo_objeto){
  this->objeto = nuevo_objeto;
}

template < typename dato >
void Nodo<dato>::cambiar_siguiente(Nodo<dato>* nueva_direccion){
  this->direccion = nueva_direccion;
}

#endif // !NODO_H
