/*
  Archivo: Tesoro.cpp

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
#include <string>
#include "../Tesoro.h"

Tesoro::Tesoro(int fila_Objeto, int columna_Objeto) : Objeto(fila_Objeto, columna_Objeto)
{
  this-> fila_Objeto = fila_Objeto;
  this-> columna_Objeto = columna_Objeto;
}

Tesoro::~Tesoro()
{
  
}

void Tesoro::encontrar() //evento que ocurre cuando el jugador se encuentra con el objeto
{
  Objeto::encontrar();
  cout<<"un tesoro!!"<<endl;
}
