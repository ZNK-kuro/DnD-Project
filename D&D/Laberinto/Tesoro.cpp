/*
  Archivo: Tesoro.cpp

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL
*/
#include <iostream>
#include <string>
#include "h/Tesoro.h"

Tesoro::Tesoro(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje) : 
        Objeto(jugador,dispositivo, filaMensaje, columnaMensaje)
{
}

Tesoro::~Tesoro()
{
}

void Tesoro::condicionDePaso() //condicion de paso que ocurre cuando el jugador se encuentra con el objeto
{
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje,"                                           ");
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje, "Hay un tesoro allí.");
}


bool Tesoro::encontrar() //evento que ocurre cuando el jugador se encuentra con el objeto
{
  jugador->cogerTesoro();
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje, "Encontraste un tesoro. + 100 puntos");
  return true;
}