#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Archivo.h"
#include <string>
#include <fstream>
#include "ArrayStack.h"
#include "Stack.h"


using namespace std;

int main(int argc, char const *argv[]){
    
    //fstream file;
    char resp='s';
    while (resp=='s'||resp=='S'){
        std::cout << "▶︎︎︎︎▶︎︎︎︎▶︎︎︎︎▶︎︎︎︎Bienvenido a nuestro sistema de manejo de archivos◀︎◀︎◀︎◀︎" << '\n';
        MenuPrincipal:
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
            nombre+=".txt";
            //file.open(nombre, std::fstream::in | std::fstream::out | std::fstream::app);
            //std::cout << "✔︎ creado exitosamente" << '\n';
            Archivo* file= new Archivo(nombre);
            file->escribirArchivo();
            char agregar;
            std::cout << "Desea agregar algo al archivo creado? [s/n] " << '\n';
            cin>>agregar;
            //while(agregar=='s'||agregar=='S'){
                if(agregar=='s'||agregar=='S'){
                string nuevo;
                std::cout << "Ingrese lo que desea agregar" << '\n';
                getline(cin, nuevo);
                getline(cin, nuevo);
                file->escribirArchivo(nuevo);
                std::cout << "✔︎ agrego a: "+ nombre+ " exitosamente" << '\n';
                }
                //std::cout << "Desea agregar algo al archivo creado? [s/n] " << '\n';
                //cin>>agregar;   
            //}
            //goto MenuPrincipal;
            //file.close();
        }
            break;
            //fin case 'a'
        case  'b':{
            string nombre;
            std::cout << "Ingrese el nombre del archivo que desea editar" << '\n';
            std::cout << "seguido de la extension .txt" << '\n';
            cin>>nombre;
            Archivo* file= new Archivo(nombre);
            char hacer;
            std::cout << "a) Agregar al archivo" << '\n';
            std::cout << "b) Sobrescribir el archivo" << '\n';
            cin>> hacer;
            switch (hacer){
            case  'a':{
                int cont=0;
                Stack* stack = new ArrayStack(5);
                string existente;
                string* archivo=&existente;
                stack->push(archivo);
                existente=file->cargarArchivo();
                std::cout << "✒︎ El archivo contiene: " << '\n';
                cout << existente<<endl;
                std::cout << "☗ Dispone de 5 oportunidades de edicion al texto" << '\n';
                char res='s';
                char escribir='s';
                while(res=='s' || res=='S' || escribir!='s'){
                    existente=file->cargarArchivo();
                    string add;
                    std::cout << "➤ Ingrese lo que desea agregar al texto" << '\n';
                    getline(cin,add);
                    getline(cin,add);
                    existente+=add;
                    std::cout << "➤ Este seria el nuevo texto: " << '\n';
                    cout<<existente<<endl;
                    cont++; 
            
                    std::cout << "❍ Desea escribir en el archivo ['s'] o deshacer cambios?['x']" << '\n';
                    cin>> escribir;
                    if(escribir=='s'||escribir=='S'){
                        stack->push(archivo);
                        file->escribirArchivo(stack->pop()->c_str());
                        goto MenuPrincipal;
                    }
                    if(cont>5){
                        res='n';
                    }

                }

            }
                break;
                //fin case a
            case  'b':{
                int cont=0;
                Stack* stack = new ArrayStack(5);
                string existente;
                string* archivo=&existente;
                stack->push(archivo);
                existente="";
                std::cout << "☻ El archivo no contiene nada " << '\n';
                cout << existente<<endl;
                std::cout << "☗ Dispone de 5 oportunidades de edicion al texto" << '\n';
                char res='s';
                char escribir='s';
                while(res=='s' || res=='S' || escribir!='s'){
                    existente="";
                    string add;
                    std::cout << "➤ Ingrese lo que desea agregar al texto" << '\n';
                    getline(cin,add);
                    getline(cin,add);
                    existente+=add;
                    std::cout << "➤ Este seria el nuevo texto: " << '\n';
                    cout<<existente<<endl;
                    cont++; 
            
                    std::cout << "Desea escribir en el archivo ['s'] o deshacer cambios?['x']" << '\n';
                    cin>> escribir;
                    if(escribir=='s'||escribir=='S'){
                        stack->push(archivo);
                        file->escribirArchivo(stack->pop()->c_str());
                        goto MenuPrincipal;
                    }
                    if(cont>5){
                        res='n';
                    }

            }
            }
                break;
                //fin case b
            default:{
                std::cout << "✖︎ La accion que intento no esta contemplada en el menu" << '\n';
            }
                break;
            }//fin otro switch
            
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
