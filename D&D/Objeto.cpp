/*
  Archivo: Objeto.cpp
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
  Licencia: GPL


  Clase: Objeto
  
  Responsabilidad: xdd
  
  Colaboración: ddx
*/

#include <iostream>
#include <string>
#include <"Objeto.h">

Objeto::Objeto (int fila_Objeto, int columna_Objeto, string nombre)
{
  this-> fila_Objeto = fila_Objeto;
  this-> columna_Objeto = columna_Objeto;
  this-> nombre = nombre;
}

Objeto::~Objeto()

Objeto::condicionDePaso ()
{
  cout<<"Para pasar debes ";
}

Objeto::encontrar()
{
  cout<<"¡¡Encontraste un ";
}