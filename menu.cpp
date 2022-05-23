#include "menu.h"

using namespace std;
void Menu::desplegar_menu(){
    
    cout << "1. Agregar una nueva lectura a la lista" << endl;
    cout << "2. Quitar una lectura de la lista" << endl;
    cout << "3. Agregar un escritor" << endl;
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
  
  
    switch(tipo_lectura){
        
        case 'N':
            
            string genero;
            cout << "Ingrese un genero: " << endl;
            cin >> toUpper(genero);
            
            if (genero == "HISTORICA")
                Lectura* nueva_historica();
            
            break;
        
        case 'P':
            
            int versos;
            cout << "Ingrese un cantidad de versos: " << endl;
            cin >> versos;
            break;
        
        case 'C':
            
            string genero;
            cout << "Ingrese un genero: " << endl;
            cin >> genero;
            break;
            
        
    }

    
}


void Menu::quitar_lectura(){
    string titulo_ingresado;
    
    cout << "Ingrese el titulo de la lectura que desea quitar" << endl;

    cin >> titulo_ingresado;

    lecturas.baja(titulo_ingresado);
    
}

void Menu::agregar_escritor(){
    string nombre_y_apellido
    cout << "Ingrese nombre y apellido del escritor (por ejemplo: Stephen King)" << endl;
    cin >> nombre_y_apellido;
    
}





