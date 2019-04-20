/*
  Archivo: Objeto.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL


  Clase: Objeto

  Responsabilidad: xdd

  Colaboración: ddx
*/

#include <iostream>
#include <string>
#include "h/Objeto.h"

Objeto::Objeto()
{
  
}
Objeto::Objeto (int fila_Objeto, int columna_Objeto)
{
  this-> fila_Objeto = fila_Objeto;
  this-> columna_Objeto = columna_Objeto;
}
Objeto::~Objeto()
{
  
}

void Objeto::condicionDePaso ()
{
  cout<<"Para pasar debes ";
}

void Objeto::encontrar()
{
  cout<<"¡¡Encontraste un ";
}

void Objeto::posicionActual()
{
  cout<<fila_Objeto<<", "<<columna_Objeto<<endl;
}
