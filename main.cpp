#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Archivo.h"
#include <string>
#include <fstream>
//#include "Stack.h"

std::ostream& operator << (std::ostream &o,const std::string &p);

using namespace std;

int main(int argc, char const *argv[]){
    fstream file;
    char resp='s';
    while (resp=='s'||resp=='S'){
        std::cout << "▶︎︎︎︎▶︎︎︎︎▶︎︎︎︎▶︎︎︎︎Bienvenido a nuestro sistema de manejo de archivos◀︎◀︎◀︎◀︎" << '\n';
        //MenuPrincipal:
        char principal;
        std::cout << "➤ a) Crear nuevo archivo" << '\n';
        std::cout << "➤ b) Editar archivo ya existente" << '\n';
        std::cout << "➤ c) Exit" << '\n';
        cin >> principal;
        switch (principal){
        case  'a':{
            string nombre;
            std::cout << "Ingrese nombre que le dara al nuevo archivo" << '\n';
            cin>> nombre;
            nombre+".txt";
            file.open(nombre, std::fstream::in | std::fstream::out | std::fstream::app);
            std::cout << "✔︎ creado exitosamente" << '\n';
            char agregar;
            std::cout << "Desea agregar algo al archivo creado? [s/n] " << '\n';
            cin>>agregar;
            while(agregar=='s'||agregar=='S'){
                string nuevo;
                std::cout << "Ingrese lo que desea agregar" << '\n';
                getline(cin, nuevo);
                getline(cin, nuevo);
                file<<nuevo;
                file<<'\n';
                std::cout << "✔︎ agrego a: "+ nombre+ " exitosamente" << '\n';
                std::cout << "Desea agregar algo al archivo creado? [s/n] " << '\n';
                cin>>agregar;
            }
            //goto MenuPrincipal;
            file.close();
        }
            break;
            //fin case 'a'
        case  'b':{

        }
            break;
            //fin case 'b'
        case  'c':{
            resp='n';
        }
            break;
            //fin case c
        default:{
            std::cout << "✖︎ La accion que intento no esta contemplada en el menu" << '\n';
            //goto MenuPrincipal;
        }
            break;
        }
        


    }


    return 0;
}

std::ostream& operator << (ostream &o,const string &p)
{
    o <<p.c_str()<< "mundo" ;
    return o;
}