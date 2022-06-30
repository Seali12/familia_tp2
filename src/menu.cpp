#include "../header/menu.h"
#include "stdlib.h"
#include <string>
#include "time.h"
#include <cstdlib>

using namespace std;

Menu::Menu(Lista_lectura lecturas, Tabla_escritores escritores){
    
    this -> lecturas = lecturas;
    this -> escritores = escritores;

    seguir = true;

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
    cout << "# 12. Listar camino y tiempo mas corto para leer todas las lecturas                #" << endl;
    cout << "# 13. Quitar un escritor                                                           #" << endl;
    cout << "# 14. Salir                                                                        #" << endl;
    cout << "####################################################################################" << endl;

    int opcion;
    cout << BLANCO "Elije un número: " << CYAN;
    cin >> opcion;

    opciones(opcion);
}  

void Menu::opciones(int opcion){

    switch(opcion){

        case AGREGAR_LECTURA:
        
            limpiar_consola();
            agregar_nueva_lectura();
            break;
        
        case QUITAR_LECTURA:
        
            limpiar_consola();
            quitar_lectura();
            break;
        
        case AGREGAR_ESCRITOR:
        
            limpiar_consola();
            agregar_escritor();
            break;
        
        case CAMBIAR_DATO_ESCRITOR:
        
            limpiar_consola();
            cambiar_fecha_escritor();
            break;
        
        case LISTAR_ESCRITORES:
        
            limpiar_consola();
            listar_escritores();
            break;
        
        case SORTEAR_RANDOM:
        
            limpiar_consola();
            sortear_lectura();
            break;
        
        case LISTAR_LECTURAS:
        
            limpiar_consola();
            listar_todas_lecturas();
            break;
        
        case LISTAR_LECTURAS_ANIO:
        
            limpiar_consola();
            listar_lecturas_rango();
            break;
        
        case LISTAR_LECTURAS_ESCRITOR:
        
            limpiar_consola();
            listar_lecturas_escritor();
            break;
        
        case LISTAR_NOVELAS_GENERO:
        
            limpiar_consola();
            listar_novela_genero();
            break;
        
        case ARMAR_COLA:
        
            limpiar_consola();
            armar_cola();
            break;
        
        case LISTAR_MINIMO_CAMINO:
        
            listar_minimo_camino();
            break;              
       
        case QUITAR_ESCRITOR:
            
            quitar_escritor();
            break;
        
        case SALIR:
        
            salir();
            break;
        
        default:
        
            cout << endl;
            limpiar_consola();
            desplegar_menu();
            break;
    }
}

/* OPCIONES DEL MENÚ */

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
    cout << BLANCO "Año: " CYAN;
    cin >> anio;

    escritores.listar_isni_escritor();
    string clave;
    cout << BLANCO "Ingrese la clave ISNI del escritor (tiene que estar en la lista para que funcione): " CYAN;
    cin >> clave;
    
    string isni("(" + clave +")");

  
    corroborar_tipo_lectura( (char)toupper(tipo_lectura), titulo, duracion, anio, isni);
    
}

void Menu::corroborar_tipo_lectura(char tipo_lectura, string titulo, double minutos, int anio, string escritor){
    switch(tipo_lectura){

        case 'N':{
            
            string genero;
            cout << BLANCO "Ingrese un genero: " CYAN;
            cin >> genero;
            genero = pasar_mayuscula(genero);
            
            if (genero == "HISTORICA"){
            
                    string* tema = new string;
                    cout << BLANCO "Ingrese el tema de la novela: " CYAN;
                    cin.ignore();
                    getline(cin, *tema);

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

void Menu::quitar_lectura(){
    cout << endl;

    cout << NEGRITA_VERDE "Lecturas activas:" NEGRITA_ROJO;
    lecturas.mostrar_titulos();
    
    int numero;
    cout << BLANCO "Ingrese el número del título: " CYAN;
    cin >> numero;

    lecturas.baja(numero);
}

void Menu::agregar_escritor(){
    cout << endl;

    string clave;    
    cout << BLANCO "Ingrese clave ISNI: " CYAN;
    cin >> clave;
    string isni("(" + clave +")");

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
    cout << BLANCO "Ingrese el año de fallecimiento del escritor: " CYAN;
    cin >> anio_fallecimiento;

    Escritor* nuevo_escritor = new Escritor(isni, nombre_y_apellido, nacionalidad, 
                                                anio_nacimiento, anio_fallecimiento);
    escritores.alta(nuevo_escritor);
}

void Menu::cambiar_fecha_escritor(){
    cout << endl;

    string clave;
    escritores.listar_isni_escritor();
    cout << BLANCO "Escriba el nombre o isni del escritor que desea modificar: " CYAN;
    cin >> clave;
    string isni("(" + clave +")");

    int anio;
    cout << BLANCO "Cuál es su año de fallecimiento? " CYAN;
    cin >> anio;
    
    Escritor* escritor_modificar = escritores.consulta(isni);
    escritor_modificar -> modificar_anio_fallecimiento(anio);
}


void Menu::listar_escritores(){
    
    escritores.mostrar();   
}


void Menu::sortear_lectura(){
   
    int numero_aleatorio = 1 + rand() % lecturas.obtener_cantidad();
    lecturas.lectura_random(numero_aleatorio);
  
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

void Menu::listar_lecturas_escritor(){
    cout << endl;
    escritores.listar_isni_escritor();
    string clave;
    cout << BLANCO "Ingrese Isni de un escritor: " CYAN;
    cin >> clave;
    string isni("(" + clave +")");

    lecturas.listar_por_escritor(isni);
}

void Menu::listar_novela_genero(){
    cout << endl;

    string genero_ingresado;
    cout << BLANCO "Ingresame un género de novela: " CYAN;
    cin >> genero_ingresado;
    
    lecturas.listar_por_genero(pasar_mayuscula(genero_ingresado));
}

void Menu::armar_cola(){
    
    double minimo = 0;
    
    for (int iterador = 0; iterador < lecturas.obtener_cantidad(); iterador++){
        
        cola_lecturas.alta (lecturas.consulta(minimo));
    }
    
    cout << NEGRITA_ROJO << endl;
    cola_lecturas.mostrar();

    char rta;
    cout << BLANCO "Si la lectura ya esta leída (precione E para dar de baja) o S para volver al menú: " CYAN;
    cin >> rta;

    while((char)toupper(rta) != 'S' and !cola_lecturas.vacia()){

        if ((char)toupper(rta) == 'E'){

            cout << NEGRITA_ROJO << endl;
            cola_lecturas.baja();
            cola_lecturas.mostrar();

        }
        if(!cola_lecturas.vacia()){

            cout << BLANCO "Si la lectura ya esta leída (presione E para dar de baja) o S para salir al menú: " CYAN;
            cin >> rta;
            
        }
    }
    
    cola_lecturas.eliminar_cola(); 
    cout << BLANCO "No hay más lecturas para leer" << endl;
}

void Menu::listar_minimo_camino(){
    
    this -> kruskal.cargar(lecturas);

    this -> kruskal.ejecutar_kruskal();

}


void Menu::quitar_escritor(){
     
    escritores.listar_isni_escritor();
    
    string clave;
    cout << BLANCO "Ingrese Isni de un escritor: " CYAN;
    cin >> clave;
    string isni("(" + clave +")");

    lecturas.actualizar_escritor(isni);
    
    escritores.baja_tabla(isni);

}

void Menu::salir(){
    
    seguir = false;
}

/* FIN DE LAS OPCIONES DEL MENÚ */

void Menu::eliminar_listas(){

    lecturas.liberar_lista();
    escritores.eliminar_tabla();
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

void Menu::limpiar_consola(){

    system("clear");
}

void Menu::sid(){
cout<<endl;
cout<<endl;

cout<< NEGRITA_ROJO".########" << NEGRITA_AMARILLO"....###..." << NEGRITA_MAGENTA".##.....##" << NEGRITA_VERDE".####" << NEGRITA_BLANCO".##......." << NEGRITA_AZUL"####" << NEGRITA_ROJO"....###...." << NEGRITA_AMARILLO"...########" << NEGRITA_MAGENTA".########..." << NEGRITA_VERDE"...#######."<<endl;
cout<< NEGRITA_ROJO".##......" << NEGRITA_AMARILLO"...##.##.." << NEGRITA_MAGENTA".###...###" << NEGRITA_VERDE"..##." << NEGRITA_BLANCO".##......." << NEGRITA_AZUL".##." << NEGRITA_ROJO"...##.##..." << NEGRITA_AMARILLO"......##..." << NEGRITA_MAGENTA".##.....##.." << NEGRITA_VERDE"..##.....##"<<endl;
cout<< NEGRITA_ROJO".##......" << NEGRITA_AMARILLO"..##...##." << NEGRITA_MAGENTA".####.####" << NEGRITA_VERDE"..##." << NEGRITA_BLANCO".##......." << NEGRITA_AZUL".##." << NEGRITA_ROJO"..##...##.." << NEGRITA_AMARILLO"......##..." << NEGRITA_MAGENTA".##.....##.." << NEGRITA_VERDE".........##"<<endl;
cout<< NEGRITA_ROJO".######.." << NEGRITA_AMARILLO".##.....##" << NEGRITA_MAGENTA".##.###.##" << NEGRITA_VERDE"..##." << NEGRITA_BLANCO".##......." << NEGRITA_AZUL".##." << NEGRITA_ROJO".##.....##." << NEGRITA_AMARILLO"......##..." << NEGRITA_MAGENTA".########..." << NEGRITA_VERDE"...#######."<<endl;
cout<< NEGRITA_ROJO".##......" << NEGRITA_AMARILLO".#########" << NEGRITA_MAGENTA".##.....##" << NEGRITA_VERDE"..##." << NEGRITA_BLANCO".##......." << NEGRITA_AZUL".##." << NEGRITA_ROJO".#########." << NEGRITA_AMARILLO"......##..." << NEGRITA_MAGENTA".##........." << NEGRITA_VERDE"..##......."<<endl;
cout<< NEGRITA_ROJO".##......" << NEGRITA_AMARILLO".##.....##" << NEGRITA_MAGENTA".##.....##" << NEGRITA_VERDE"..##." << NEGRITA_BLANCO".##......." << NEGRITA_AZUL".##." << NEGRITA_ROJO".##.....##." << NEGRITA_AMARILLO"......##..." << NEGRITA_MAGENTA".##........." << NEGRITA_VERDE"..##......."<<endl;
cout<< NEGRITA_ROJO".##......" << NEGRITA_AMARILLO".##.....##" << NEGRITA_MAGENTA".##.....##" << NEGRITA_VERDE".####" << NEGRITA_BLANCO".########." << NEGRITA_AZUL"####" << NEGRITA_ROJO".##.....##." << NEGRITA_AMARILLO"......##..." << NEGRITA_MAGENTA".##........." << NEGRITA_VERDE"..#########"<<endl;                                                                                                                                                                           

cout<<endl;
cout<<endl;

cout<<BLANCO"&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<BLANCO"%%%%%%%%%%%%%%%%%%"<<AMARILLO"###%%%/#("<<BLANCO"%%%%%%%%%%%%"<<AMARILLO"####%%%%#"<<BLANCO"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<BLANCO"%%%%%%%%%%%%%%%%%%"<<AMARILLO"(//////**/("<<BLANCO"%%%%"<<AMARILLO"&@##((((//////(#"<<BLANCO"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<BLANCO"&%%%%%%%%%%%%%%%%"<<AMARILLO"%("<<BLANCO"@*"<<NEGRO",."<<BLANCO"##/"<<AMARILLO"*,**/(/((((((((///***///(((#&"<<BLANCO"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<BLANCO"&%%%%%%%%%%%%%%%%"<<AMARILLO"%#&"<<BLANCO"@(/%%"<<AMARILLO"(*(%%%%##(##((//"<<ROJO"((*,****,"<<AMARILLO"**/(###%&&"<<BLANCO"%%%%%%"<<AMARILLO"(%("<<BLANCO"%%%%%%%%%%%%%%%"<<endl;
cout<<BLANCO"&%&%%%%%%%%%%%&%&%"<<AMARILLO"&(,,***,#&&&&&&%%%#(#"<<ROJO"((**********,,"<<AMARILLO",,*%#%%(/*((((//(#&"<<BLANCO"%%%%%%%%%%%%"<<endl;
cout<<BLANCO"&&&&&&&&&&&&&&&&&&&"<<AMARILLO"%%%%/,/#%"<<ROJO"(."<<AMARILLO"(%&&&&%%%#"<<ROJO"/*,,********,,,"<<AMARILLO",,/(%#(((/"<<BLANCO"#&"<<NEGRO"/."<<BLANCO"/&"<<AMARILLO"/%"<<BLANCO"&&&&&&&&&&&"<<endl;
cout<<BLANCO"&&&&&&&&&&&&&&&&&&&&&&&"<<AMARILLO"##(##("<<ROJO"(.  "<<AMARILLO"#%&&%%#"<<ROJO"/*,********,,,,"<<AMARILLO",,,,*((#(#//"<<BLANCO"%&%"<<AMARILLO"%"<<BLANCO"&&&&&&&&&&&&&"<<endl;
cout<<BLANCO"&&&&&&&&&&&&&&&&&&&&&&&&&"<<AMARILLO"&#(%#"<<ROJO"#(.  "<<AMARILLO"(#%%#("<<ROJO"****,.*/*****"<<AMARILLO",,,,,*/(#(##%%%&"<<BLANCO"&&&&&&&&&&&&&&"<<endl;
cout<<BLANCO"&&&&&&&&&&&&&&&&&&&&&&&&&&"<<AMARILLO"&#(#%##"<<ROJO"("<<BLANCO"*#%"<<AMARILLO"(##(("<<ROJO"//////**/*,."<<AMARILLO"/*,,*"<<ROJO"//"<<AMARILLO"((/%"<<BLANCO"&&&&&&&&&&&&&&&&&&&"<<endl;
cout<<BLANCO"&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<AMARILLO"&%(#%%"<<ROJO"((("<<BLANCO"//("<<AMARILLO"**/(((#(/*,***///"<<ROJO"////"<<AMARILLO",*%"<<BLANCO"&&&&&&&&&&&&&&&&&&&&&"<<endl;
cout<<BLANCO"@&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<AMARILLO"&&##%%%"<<ROJO"(#%("<<BLANCO"*((%%%#(////("<<ROJO",* .."<<AMARILLO",*("<<BLANCO"&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
cout<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@&"<<AMARILLO"@&&#%%%%%"<<ROJO"#(#(@"<<BLANCO"#&&&%(#("<<ROJO" ,,**"<<AMARILLO"/(#@"<<BLANCO"&@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
cout<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<AMARILLO"&@&&%%%%%%%%&%"<<ROJO"(////////**"<<AMARILLO"//(#"<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
cout<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@"<<AMARILLO"&#%#%%&#%%%%%%%&%%%%###(((/(&"<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
cout<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@"<<AMARILLO"#((((#%&&%%%%%%%%%%%##((///,,*#"<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
cout<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@@"<<AMARILLO"&#((#(#%&&&&%##%#####(((//,,..,,,/%"<<BLANCO"@@@@@&&%%&@@@@@@@@@@@@@@@@"<<endl;
cout<<BLANCO"@@@@@@@@@@@@@@@@@@@@@@"<<AMARILLO"%(#/(((#%%%%&%##%##(((//*.....,,,,,,,*****,...//(&"<<BLANCO"@@@@@@@@@@@@"<<endl;
cout<<BLANCO"@&&&&&&&&&&"<<AMARILLO"((/*(%@@@&((((/((//%#%#####((///*,..,..,,,,,********,,..***/*(#"<<BLANCO"&&&&&&&&&&"<<endl;

cout<<endl;
cout<<endl;

}



                                                                                                                        
                                                                                                                                                                                                                                            
                                                                                                                                                                            