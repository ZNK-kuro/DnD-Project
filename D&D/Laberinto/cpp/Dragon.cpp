/*
  Archivo: Dragon.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL
*/
#include <iostream>
#include "../Dragon.h"

Dragon::Dragon(int fila_Objeto, int columna_Objeto) : Objeto(fila_Objeto, columna_Objeto)
{
  this-> fila_Objeto = fila_Objeto;
  this-> columna_Objeto = columna_Objeto;
}


Dragon::~Dragon()
{
  
}


void Dragon::condicionDePaso() //condicion de paso que ocurre cuando el jugador se encuentra con el objeto
{
  Objeto::condicionDePaso();
  cout<<"traerme un tesoro"<<endl;
}

