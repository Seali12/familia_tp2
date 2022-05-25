#include "../header/novela.h"

Novela::Novela(char tipo_lectura, string titulo, double minutos, int anio, Escritor* escritor,  string genero_recibido) :
                Lectura(tipo_lectura, titulo, minutos, anio, escritor){

                    if(genero_recibido == "TERROR")
                        genero = TERROR;
                    
                    else if(genero_recibido == "HISTORICA")
                        genero = HISTORICA;
                        
                    else if(genero_recibido == "FICCION")
                        genero = FICCION;

                    else if(genero_recibido == "COMEDIA")
                        genero = COMEDIA;
                    
                    else if(genero_recibido == "ROMANTICA")
                        genero = ROMANTICA;

                    else if(genero_recibido == "DRAMA")
                        genero = DRAMA;
                    
                    else
                        genero = SUSPENSO;
}

void Novela::mostrar(){
    
    cout << "Novela" << endl;
    
    cout << "Titulo: " << titulo << endl;

    cout << "Minutos: " << minutos << endl;

    cout << "Año de la novela: " << anio << endl;

    mostrar_genero();

    cout << "Referencia al escritor: " << escritor->obtener_referencia() << endl;

    cout << "" << endl;

}


void Novela::mostrar_genero(){
    
    if(genero == TERROR)
        cout << "TERROR" << endl;
    
    else if(genero == HISTORICA)
        cout << "HISTORICA" << endl;
    
    else if(genero == FICCION)
        cout << "FICCION" << endl;
    
    else if(genero == COMEDIA)
        cout << "COMEDIA" << endl;
    
    else if(genero == ROMANTICA)
        cout << "ROMANTICA" << endl;
    
    else if(genero == DRAMA)
        cout << "DRAMA" << endl;
    
    else
        cout << "SUSPENSO" << endl;

}

string Novela::obtener_atributo_especial(){
    return to_string(genero);
}