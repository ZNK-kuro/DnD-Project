/*
  Archivo: Dragon.cpp

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2019/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL
*/
#include <iostream>
#include <cstdlib>
#include "h/Dragon.h"

Dragon::Dragon(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje) : 
        Objeto(jugador,dispositivo, filaMensaje, columnaMensaje)
{
}

Dragon::~Dragon()
{
}


void Dragon::condicionDePaso() // Condicion de paso que ocurre cuando el jugador se encuentra con el objeto
{
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje,"                                           ");
  if (pagar)  // La primera vez que se encuentra con el dragón se escoge una multa de tesoros a pagar.
  {
    peaje = (1 + (rand() % 4));
    pagar = false;
  }
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje,
                "Para pasar debes darme " + to_string(peaje) + " tesoros"
                + "\nPresiona una flecha para continuar.");
  dispositivo->leerJugada();
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje,"                                               ");
  dispositivo->imprimirMensaje(filaMensaje+1,columnaMensaje,"                                               ");
}


bool Dragon::encontrar()
{
  pagar = true;
  return jugador->darTesdoro(peaje);
}
