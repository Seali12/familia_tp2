#include "../header/lector.h"
#include <fstream>
#include <stdlib.h>

Lector::Lector(string archivo_lectura, string archivo_escritor, Lista_lectura lecturas, Lista_escritor escritores)
{
    this->archivo_lectura = archivo_lectura;
    this->archivo_escritor = archivo_escritor;
    this->lecturas = lecturas;
    this->escritores = escritores;
}

void Lector::procesar_archivo_escritores()
{

    ifstream archivo_escritores(archivo_escritor, ios::in);

    if (!archivo_escritores)
    {
        cout << "No se pudo abrir el archivo de escritores" << endl;
    }
    else{

        string referencia, nombre_escritor, nacionalidad, anio_nacimiento, anio_fallecimiento, espacio;
        while (getline(archivo_escritores, referencia)){
            bool hay_mas_datos = true;

            getline(archivo_escritores, nombre_escritor);
            getline(archivo_escritores, nacionalidad);

            if(!nacionalidad.empty()){
                getline(archivo_escritores, anio_nacimiento);
            }else{
                hay_mas_datos = false;
                nacionalidad = SIN_NACIONALIDAD;
                anio_nacimiento = NO_ENCONTRADO;
                anio_fallecimiento = NO_ENCONTRADO;
            }
            if (!anio_nacimiento.empty() and hay_mas_datos){
                getline(archivo_escritores, anio_fallecimiento);
            }
            else{
                hay_mas_datos = false;
                anio_nacimiento = NO_ENCONTRADO;
                anio_fallecimiento = NO_ENCONTRADO;
            }
            if (!anio_fallecimiento.empty() and hay_mas_datos){
                getline(archivo_escritores, espacio);
            }else{
                hay_mas_datos = false;
                anio_fallecimiento = NO_ENCONTRADO;
            }

            Escritor *nuevo_escritor = new Escritor(referencia, nombre_escritor, nacionalidad,
                                                    stoi(anio_nacimiento), stoi(anio_fallecimiento));

            escritores.alta(nuevo_escritor);
        }
    }

    archivo_escritores.close();
}

void Lector::procesar_archivo_lectura()
{

    ifstream archivo_lectores(archivo_lectura, ios::in);

    if (!archivo_lectores)
    {
        cout << "No se pudo abrir el archivo de lectores" << endl;
    }
    else
    {
        string tipo_lectura;

        while (getline(archivo_lectores, tipo_lectura))
        {

            string titulo, minutos, anio, referencia_escritor, espacio;

            getline(archivo_lectores, titulo);
            getline(archivo_lectores, minutos);
            getline(archivo_lectores, anio);

            switch (tipo_lectura[CHAR])
            {
            case NOVELA:
            {
                string genero;
                getline(archivo_lectores, genero);

                if (genero == "HISTORICA"){

                    string tema_historica;

                    getline(archivo_lectores, tema_historica);
                    getline(archivo_lectores, referencia_escritor);
                    getline(archivo_lectores, espacio);

                    Lectura *nueva_historica = new Novela_historica(tipo_lectura[CHAR], titulo, atof(minutos.c_str()), stoi(anio),
                                                                    escritores.consulta(referencia_escritor), genero, tema_historica );

                    lecturas.alta(nueva_historica);
                }
                else
                {

                    getline(archivo_lectores, referencia_escritor);
                    getline(archivo_lectores, espacio);

                    Lectura *nueva_novela = new Novela(tipo_lectura[CHAR],titulo, atof(minutos.c_str()), stoi(anio),
                                                       escritores.consulta(referencia_escritor), genero);

                    lecturas.alta(nueva_novela);
                }

                break;
            }
            case POEMA:
            {
                string versos;

                getline(archivo_lectores, versos);
                getline(archivo_lectores, referencia_escritor);
                getline(archivo_lectores, espacio);

                Lectura *nuevo_poema = new Poema(tipo_lectura[CHAR], titulo, atof(minutos.c_str()), stoi(anio),
                                                 escritores.consulta(referencia_escritor), stoi(versos));

                lecturas.alta(nuevo_poema);

                break;
            }
            case CUENTO:
            {
                string titulo_cuento;

                getline(archivo_lectores, titulo_cuento);
                getline(archivo_lectores, referencia_escritor);
                getline(archivo_lectores, espacio);

                Lectura *nuevo_cuento = new Cuento(tipo_lectura[CHAR], titulo, atof(minutos.c_str()), stoi(anio),
                                                   escritores.consulta(referencia_escritor), titulo_cuento);

                lecturas.alta(nuevo_cuento);

                break;
            }
            }
        }

        archivo_lectores.close();
    }
}

Lista_lectura Lector::devolver_lecturas(){
    return lecturas;
}

Lista_escritor Lector::devolver_escritores(){
    return escritores;
}