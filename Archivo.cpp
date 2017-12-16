 #include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Archivo.h"

using namespace std;

Archivo::Archivo(){}

Archivo::Archivo(string pNombre){
    nomArchivo=pNombre;

}

Archivo::~Archivo(){}

ostream& operator<<(ostream &os, const string& n)
{
    os<<n.c_str();
    return os;
}

  istream&  operator>>(istream &is, string& n)
{

    return is;
}

string Archivo::cargarArchivo(){
    string tempo;
    fstream file(nomArchivo);
    if (file.is_open()){
        getline(file,tempo);
    }else{
        std::cout << "✖︎ Error al abrir el archivo o no existe" << '\n';
    }

    //std::cout << "------------" << '\n';
    file.close();
    return tempo;
}//fin cargar archivo

void Archivo::escribirArchivo(){
   
    fstream file;
    file.open(nomArchivo, std::fstream::in | std::fstream::out | std::fstream::app);
    std::cout << "✔︎ creado exitosamente" << '\n';


    file.close();
}//fin escribir archivo

void Archivo::escribirArchivo(string nuevo){
   
    fstream file;
    file.open(nomArchivo, std::fstream::in | std::fstream::out | std::fstream::trunc);
    file<<nuevo;
    //file<<'\n';

    file.close();
}//fin escribir archivo

