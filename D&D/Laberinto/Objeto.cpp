/*
  Archivo: Objeto.cpp

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL


  Clase: Objeto

  Responsabilidad: xdd

  Colaboración: ddx
*/

#include <iostream>
#include <string>
#include "h/Objeto.h"

Objeto::Objeto(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje)
{
  this->jugador = jugador;
  this->dispositivo = dispositivo;
  this->filaMensaje = filaMensaje;
  this->columnaMensaje = columnaMensaje;
}

Objeto::~Objeto()
{
}