#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

class Archivo
{
  public:
    Archivo();
    Archivo(string);
    ~Archivo();
    string cargarArchivo();
    void escribirArchivo();
    void escribirArchivo(string);
    friend ostream &operator<<(ostream &os, const string &n);
    friend istream &operator>>(istream &is, string &n);

  private:
    string nomArchivo;
};
