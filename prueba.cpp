#include "nodo_simple.h"
#include "lectura.h"
#include "string"
#include <iostream>
using namespace std;

class A: public Lectura {
    private:
    int numero;
    public:
    A::A(string titulo, double minutos, int anio, Escritor escritor, int numero) 
    : Lectura(titulo, minutos, anio, escritor){
        this->numero = numero;
    }
    void A::mostrar(){
        cout << numero << endl;
    }
};

class B: public Lectura {
    private:
    char letra;
    public:
    B::B(string titulo, double minutos, int anio, Escritor escritor, char letra) 
    : Lectura(titulo, minutos, anio, escritor){
        this->letra = letra;
    }
    void B::mostrar(){
        cout << letra << endl;
    }
};



int main(int argc, char const *argv[]){
    Escritor tomas("tomas", "amundarain", "argentino", 1234, 1235);
    Escritor juanito("juanito", "perez", "argentino", 1234, 1235);
   
   Lectura* a = new A("hola", 23.10, 2301, tomas, 4);
   
  
  //  B b("chau", 23.10, 2301, juanito, 'a');
  
    Nodo<Lectura*>* puntero = new Nodo(a);

    return 0;
}
