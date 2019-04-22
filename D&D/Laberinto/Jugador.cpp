/*
  Archivo: Jugador.cpp

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
#include "h/Jugador.h"

Jugador::Jugador(int fila_Jugador, int columna_Jugador)
{
  this-> fila_Jugador = fila_Jugador;
  this-> columna_Jugador = columna_Jugador;
}


Jugador::~Jugador()
{
  
}

void Jugador::cogerTesoro()
{
  tesoros++;
}

void Jugador::responderPregunta()
{
  
}

bool Jugador::darTesdoro(int numTesoros)
{
  if (tesoros >= numTesoros)
  {
    tesoros -= numTesoros;
    return true;
  }
  else
    return false;
}

void Jugador::dondeEstas(int *fila, int *columna)
{
  *fila = fila_Jugador;
  *columna = columna_Jugador;
}


void Jugador::nuevaPosicion(int fila, int columna)
{
  fila_Jugador = fila;
  columna_Jugador = columna;
}

int Jugador::tesorosJugador()
{
  return tesoros;
}