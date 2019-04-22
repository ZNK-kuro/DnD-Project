/*
  Archivo: Tesoro.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL
*/
#include <iostream>
#include <string>
#include "h/Tesoro.h"

Tesoro::Tesoro(Jugador *jugador) : Objeto(jugador)
{
}

Tesoro::~Tesoro()
{
}

void Tesoro::encontrar() //evento que ocurre cuando el jugador se encuentra con el objeto
{
  jugador->cogerTesoro();
  //Objeto::encontrar();
  //cout<<"un tesoro!!"<<endl;
}