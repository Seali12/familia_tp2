#include "menu.h"
#include "stdlib.h"
#include "time.h"

using namespace std;
void Menu::desplegar_menu(){
    
    //cout << "1. Agregar una nueva lectura a la lista" << endl;
    //cout << "2. Quitar una lectura de la lista" << endl;
    //cout << "3. Agregar un escritor" << endl;
    cout << "4. Cambiar dato de un escritor (solo fecha de fallecimiento)" << endl;
    cout << "5. Listar los escritores" << endl;
    cout << "6. Sortear una lectura random para leer en una de las tertulias" << endl;
    cout << "7. Listar todas las lecturas" << endl;
    cout << "8. Listar las lecturas entre determinados años. Los años los ingresa el usuario." << endl;
    cout << "9. Listar las lecturas de un determinado escritor que ingresa el usuario. " << endl;
    cout << "10. Listar las novelas de determinado género." << endl;
    cout << "11. Armar una cola ordenada por tiempo de lectura" << endl;
    cout << "12. Salir" << endl;

    int opcion;
    cout << "Elije un número: " << endl;
    cin >> opcion;
}  

void Menu::corroborar_tipo_lectura(char tipo_lectura, string titulo, int duracion, int anio, string escritor){
    switch(tipo_lectura){
        case 'N':
            
            string genero;
            cout << "Ingrese un genero: " << endl;
            cin >> toUpper(genero);
            
            if (genero == "HISTORICA")
            
                string tema;
                cout << "Ingrese el tema de la novela: " << endl;
                cin << tema;
                
                Lectura* nueva_historica = new Novela_historica(titulo, atof(minutos.c_str()), atoi(anio), 
                escritores.consulta(escritor), genero, tema);

                lecturas.alta(nueva_historica);
                
            else{
                
                Lectura* nueva_novela = new Novela(titulo, atof(minutos.c_str()), atoi(anio), 
                escritores.consulta(escritor), genero);

                lecturas.alta(nueva_novela); 
            }
            
            break;
        
        case 'P':
            
            int versos;
            cout << "Ingrese un cantidad de versos: " << endl;
            cin >> versos;
            
            Lectura* nuevo_poema = new Poema(titulo,atof(minutos.c_str()), atoi(anio),
            escritores.consulta(escritor),versos);
            break;
        
        case 'C':
            
            string titulo_cuento;
            cout << "Ingrese el titulo del cuento: " << endl;
            cin >> titulo_cuento;

            Lectura* nuevo_cuento = new Cuento(titulo,atof(minutos.c_str()),atoi(anio),
            escritores.consulta(escritor),titulo_cuento );
            lecturas.alta(nuevo_cuento);
            
            break;
    }
    
}

void Menu::agregar_nueva_lectura(){
    char tipo_lectura;
    cout << "Que tipo de lectura es: " << endl;
    cin >> toUpper(tipo_lectura);
    
    string titulo;
    cout << "Titulo de la lectura a agregar: " << endl;
    cin >> titulo;    

    int duracion;
    cout << "Duracion de la lectura:  " << endl;
    cin >> duracion;  
    
    int anio;
    cout << "Anio: " << endl;
    cin >> anio;
    
    string escritor;
    cout << "Nombre del escritor: " << endl;
    cin >> escritor;
  
    corroborar_tipo_lectura(tipo_lectura, titulo, duracion, anio, escritor);
    
}


void Menu::quitar_lectura(){
    string titulo_ingresado;
    cout << "Ingrese el titulo de la lectura que desea quitar" << endl;
    cin >> titulo_ingresado;

    lecturas.baja(titulo_ingresado);
}

void Menu::agregar_escritor(){
    string referencia;
    cout << "Ingrese la referencia del escritor(por ejemplo: (1), (2), etc, segun corresponda)" << endl;
    cin >> referencia;
    
    bool repetida = false;
    if(escritores.referencia_repetida(refencia))
        repetida = true;
    
    while(repetida){
        cout << "Esa referencia ya se encuenta en la lista de escritores por favor ingrese otra(por ejemplo: (1), (2), etc, segun corresponda)"
       
        if(!escritores.referencia_repetida(refencia))
            repetida = false;
    }
    
    
    string nombre_y_apellido;
    cout << "Ingrese nombre y apellido del escritor (por ejemplo: Stephen King)" << endl;
    cin >> nombre_y_apellido;

    string nacionalidad;
    cout << "Ingrese la nacionalidad del escritor" << endl;
    cin >> nacionalidad;

    int anio_nacimiento;
    cout << "Ingrese el año de nacimiento del escritor " << endl;
    cin >> anio_nacimiento;

    int anio_fallecimineto;
    cout << "Ingrese el año de nacimiento del escritor " << endl;
    cin >> anio_nacimiento;

    Escritor* nuevo_escritor = new Escritor(referencia, nombre_y_apellido, nacionalidad, 
    anio_nacimiento, anio_fallecimineto);
    escritores.alta(nuevo_escritor);
   
}

void Menu::cambiar_escritor(){
    string nombre_escritor;
    cout << "Escriba el nombre del escrito que desea modificar: " << endl;
    cin >> nombre_escritor;

    int anio;
    cout << "Cuál es su año de fallecimiento? " << endl;
    cin >> anio;
    
    escritores.modificar_fallecimiento(nombre_escritor, anio);
}

void Menu::listar_escritores(){
    escritores.mostrar_lista_escritor();   
}

/*
void Menu::sortear_lectura(){
    srand(time(NULL));
    int num=1+rand()%lecturas.obtener_cantidad();  
}
*/
void Menu::listar_todas_lecturas(){
    lecturas.mostrar_lista_lectura();
}

void Menu::listar_lecturas_escritor(){

    int anio_min;
    int anio_max;
    cout << "Ingrese anio min" << endl;
    cin >> anio_min;
    
    cout << "Ingrese anio maximo" << endl;
    cin >> anio_max;
    
    lecturas.mostrar_rango(anio_min, anio_max);
    for(int i = 0; i < lecturas.obtener_cantidad(); i++){
        if(anio_min < lecturas and anio_max > lecturas){
            
        }

    }
}


