#include "../header/menu.h"
#include "stdlib.h"
#include <string>
#include "time.h"
#include <cstdlib>

using namespace std;

Menu::Menu(Lista_lectura lecturas, Lista_escritor escritores){
    this->lecturas = lecturas;
    this->escritores = escritores;
}

void Menu::desplegar_menu(){
    
    cout << NEGRITA_VERDE "####################################################################################" << endl;
    cout << "# 1. Agregar una nueva lectura a la lista                                          #" << endl;
    cout << "# 2. Quitar una lectura de la lista                                                #" << endl;
    cout << "# 3. Agregar un escritor                                                           #" << endl;
    cout << "# 4. Cambiar dato de un escritor (solo fecha de fallecimiento)                     #" << endl;
    cout << "# 5. Listar los escritores                                                         #" << endl;
    cout << "# 6. Sortear una lectura random para leer en una de las tertulias                  #" << endl;
    cout << "# 7. Listar todas las lecturas                                                     #" << endl;
    cout << "# 8. Listar las lecturas entre determinados años. Los años los ingresa el usuario. #" << endl;
    cout << "# 9. Listar las lecturas de un determinado escritor que ingresa el usuario.        #" << endl;
    cout << "# 10. Listar las novelas de determinado género.                                    #" << endl;
    cout << "# 11. Armar una cola ordenada por tiempo de lectura                                #" << endl;
    cout << "# 12. Salir                                                                        #" << endl;
    cout << "####################################################################################" << endl;

    int opcion;
    cout << BLANCO "Elije un número: " << CYAN;
    cin >> opcion;
    opciones(opcion);
}  

void Menu::opciones(int opcion){

    switch(opcion){
        case AGREGAR_LECTURA:
            agregar_nueva_lectura();
            break;
        case QUITAR_LECTURA:
            quitar_lectura();
            break;
        case AGREGAR_ESCRITOR:
            agregar_escritor();
            break;
        case CAMBIAR_DATO_ESCRITOR:
            cambiar_fecha_escritor();
            break;
        case LISTAR_ESCRITORES:
            listar_escritores();
            break;
        case SORTEAR_RANDOM:
            sortear_lectura();
            break;
        case LISTAR_LECTURAS:
            listar_todas_lecturas();
            break;
        case LISTAR_LECTURAS_ANIO:
            listar_lecturas_rango();
            break;
        case LISTAR_LECTURAS_ESCRITOR:
            listar_lecturas_escritor();
            break;
        case LISTAR_NOVELAS_GENERO:
            listar_novela_genero();
            break;
        /*case ARMAR_COLA:
            break;  */
        case SALIR:
            salir();
            break;
        default:
            cout << endl;
            desplegar_menu();
            break;
    }
}

void Menu::corroborar_tipo_lectura(char tipo_lectura, string titulo, double minutos, int anio, string escritor){
    switch(tipo_lectura){
        case 'N':{
            
            string genero;
            cout << BLANCO "Ingrese un genero: " CYAN;
            cin >> genero;
            genero = pasar_mayuscula(genero);
            
            if (genero == "HISTORICA"){
            
                    string tema;
                    cout << BLANCO "Ingrese el tema de la novela: " CYAN;
                    cin.ignore();
                    getline(cin, tema);

                    Lectura* nueva_historica = new Novela_historica(tipo_lectura, titulo, minutos, anio, 
                    escritores.consulta(escritor), genero, tema);

                    lecturas.alta(nueva_historica);              
            }else{
                
                Lectura* nueva_novela = new Novela(tipo_lectura, titulo, minutos, anio, 
                escritores.consulta(escritor), genero);

                lecturas.alta(nueva_novela); 
            }
        }
            break;
        
        case 'P':{
            
            int versos;
            cout << BLANCO "Ingrese un cantidad de versos: " CYAN;
            cin >> versos;
            
            Lectura* nuevo_poema = new Poema(tipo_lectura, titulo,minutos, anio,
            escritores.consulta(escritor),versos);
            lecturas.alta(nuevo_poema);
            
            break;
        }
            
        case 'C':{

            string titulo_cuento;
            cout << BLANCO "Ingrese el titulo del cuento: " CYAN;
            cin >> titulo_cuento;

            Lectura* nuevo_cuento = new Cuento(tipo_lectura, titulo, minutos, anio,
            escritores.consulta(escritor),titulo_cuento );
            lecturas.alta(nuevo_cuento);
            
            break;
        }
            
    }
    
}

void Menu::agregar_nueva_lectura(){
    cout << endl;

    char tipo_lectura;
    cout << BLANCO "Que tipo de lectura es:(N para novela, C para cuento, P para poema): " CYAN;
    cin >> tipo_lectura;
    
    string titulo;
    cout << BLANCO "Titulo de la lectura a agregar: " CYAN;
    cin.ignore();
    getline(cin, titulo);
     

    int duracion;
    cout << BLANCO "Duracion de la lectura:  " CYAN;
    cin >> duracion;  
    
    int anio;
    cout << BLANCO "Anio: " CYAN;
    cin>>anio;

    string nombre_escritor;
    cout << BLANCO "Nombre del escritor: " CYAN;
    cin.ignore();
    getline(cin, nombre_escritor);

  
    corroborar_tipo_lectura( (char)toupper(tipo_lectura), titulo, duracion, anio, nombre_escritor);
    
}


void Menu::quitar_lectura(){
    cout << endl;

    string titulo_ingresado;
    cout << BLANCO "Ingrese el titulo de la lectura que desea quitar: " CYAN;
    cin >> titulo_ingresado;

    lecturas.baja(titulo_ingresado);
}

void Menu::agregar_escritor(){
    cout << endl;

    string referencia;
    cout << BLANCO "Ingrese la referencia del escritor(por ejemplo: (1), (2), etc, segun corresponda): " CYAN;
    cin >> referencia;
    
    bool repetida = false;
    if(escritores.referencia_repetida(referencia))
        repetida = true;
    
    while(repetida){
        cout << BLANCO "Esa referencia ya se encuenta en la lista de escritores por favor ingrese otra(por ejemplo: (1), (2), etc, segun corresponda): " CYAN;
        cin >> referencia;
       
        if(!escritores.referencia_repetida(referencia))
            repetida = false;
    }
    
    string nombre_y_apellido;
    cout << BLANCO "Ingrese nombre y apellido del escritor (por ejemplo: Stephen King): " CYAN;
    cin.ignore();
    getline(cin, nombre_y_apellido);

    string nacionalidad;
    cout << BLANCO "Ingrese la nacionalidad del escritor: " CYAN;
    cin >> nacionalidad;

    int anio_nacimiento;
    cout << BLANCO "Ingrese el año de nacimiento del escritor: " CYAN;
    cin >> anio_nacimiento;

    int anio_fallecimiento;
    cout << BLANCO "Ingrese el año de nacimiento del escritor: " CYAN;
    cin >> anio_fallecimiento;

    Escritor* nuevo_escritor = new Escritor(referencia, nombre_y_apellido, nacionalidad, 
                                                anio_nacimiento, anio_fallecimiento);
    escritores.alta(nuevo_escritor);
   
}

void Menu::cambiar_fecha_escritor(){
    cout << endl;

    string nombre_escritor;
    cout << BLANCO "Escriba el nombre del escrito que desea modificar: " CYAN;
    cin.ignore();
    getline(cin, nombre_escritor);

    int anio;
    cout << BLANCO "Cuál es su año de fallecimiento? " CYAN;
    cin >> anio;
    
    escritores.modificar_fallecimiento(nombre_escritor, anio);
}

void Menu::listar_escritores(){
    escritores.mostrar_lista_escritor();   
}


void Menu::sortear_lectura(){
   
    int numero_rand = 1 + rand() % lecturas.obtener_cantidad();

    lecturas.lectura_random(numero_rand);
  
}

void Menu::listar_todas_lecturas(){
    lecturas.mostrar_lista_lectura();
}

void Menu::listar_lecturas_rango(){
    cout << endl;

    int anio_min;
    int anio_max;
    cout << BLANCO "Ingrese anio min: " CYAN;
    cin >> anio_min;
    
    cout << BLANCO "Ingrese anio maximo: " CYAN;
    cin >> anio_max;
    
    lecturas.mostrar_rango(anio_min, anio_max);
}

void Menu::listar_novela_genero(){
    cout << endl;

    string genero_ingresado;
    cout << BLANCO "Ingresame un género de novela: " CYAN;
    cin >> genero_ingresado;
    
    lecturas.listar_por_genero(pasar_mayuscula(genero_ingresado));
}

void Menu::listar_lecturas_escritor(){
    cout << endl;
    
    string nombre_escritor;
    cout << BLANCO "Ingrese nombre de un escritor o su referencia: " CYAN;
    cin.ignore();
    getline(cin, nombre_escritor);

    lecturas.listar_por_escritor(nombre_escritor);
}


void Menu::salir(){
    seguir = false;
}

void Menu::eliminar_listas(){

    lecturas.liberar_lista();
    escritores.liberar_lista();
}


bool Menu::continuar(){
    return seguir;
}

string Menu::pasar_mayuscula(string cadena){
    for (int i = 0; i < (int)cadena.length(); i++) {
    cadena[i] = (char)toupper(cadena[i]);
  }
  return cadena;
}