/*
  Archivo: Tesoro.cpp
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
  Licencia: GPL
*/
#include <iostream>
#include <string>
#include <"Objeto.h">
#include "Tesoro.h"

Tesoro::Tesoro(int fila_Objeto, int columna_Objeto, string nombre) : Objeto(fila_Objeto, columna_Objeto, nombre)
{
  this-> fila_Objeto = fila_Objeto;
  this-> columna_Objeto = columna_Objeto;
  this-> nombre = nombre;
}

Tesoro::~Tesoro()

Tesoro::encontrar() //evento que ocurre cuando el jugador se encuentra con el objeto
{
  Objeto::encontrar();
  cout<<"un tesoro!!"<<endl;
}


