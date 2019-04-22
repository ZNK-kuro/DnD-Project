/*
  Archivo: Dragon.cpp

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
#include "h/Dragon.h"


Dragon::Dragon(Jugador *jugador) : Objeto(jugador)
{
  peaje = (1 + (rand() % 4));
}

Dragon::~Dragon()
{
}


void Dragon::condicionDePaso() //condicion de paso que ocurre cuando el jugador se encuentra con el objeto
{
  
}

bool Dragon::encontrar()
{
  return jugador->darTesdoro(peaje); 
}