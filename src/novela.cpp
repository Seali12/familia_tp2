#include "../header/novela.h"

Novela::Novela(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor,  string genero) :
                Lectura(tipo_lectura, titulo, minutos, anio, escritor){

    if(genero == "TERROR"){

        this -> genero = TERROR;

    }               
    else if(genero == "HISTORICA"){

        this -> genero = HISTORICA;

    }                   
    else if(genero == "FICCION"){

        this -> genero = FICCION;

    }
    else if(genero == "COMEDIA"){

        this -> genero = COMEDIA;

    }
    else if(genero == "ROMANCE"){

        this -> genero = ROMANCE;

    }
    else if(genero == "DRAMA"){

        this -> genero = DRAMA;

    }            
    else{

        this -> genero = SUSPENSO;

    }
}

void Novela::mostrar(){
    
    cout << "Novela" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    mostrar_genero();

    cout << "Referencia al escritor: " << escritor -> obtener_referencia() << endl;

    cout << "" << endl;

}

void Novela::mostrar_genero(){

    if(genero == TERROR){

        cout << "TERROR" << endl;

    }
    else if(genero == HISTORICA){

        cout << "HISTORICA" << endl;

    }
    else if(genero == FICCION){

        cout << "FICCION" << endl;

    }
    else if(genero == COMEDIA){

        cout << "COMEDIA" << endl;

    }
    else if(genero == ROMANCE){

        cout << "ROMANCE" << endl;

    }
    else if(genero == DRAMA){

        cout << "DRAMA" << endl;

    }   
    else{

        cout << "SUSPENSO" << endl;

    }
}

string Novela::obtener_atributo_especial(){
    string tipo;

    if(genero == TERROR){

        tipo = "TERROR";

    }
    else if(genero == HISTORICA){

        tipo = "HISTORICA";

    }
    else if(genero == FICCION){

        tipo = "FICCION";

    }
    else if(genero == COMEDIA){

        tipo = "COMEDIA";

    }
    else if(genero == ROMANCE){

        tipo = "ROMANCE";

    }
    else if(genero == DRAMA){

        tipo = "DRAMA";

    }   
    else{

        tipo = "SUSPENSO";

    }

    return tipo;
}