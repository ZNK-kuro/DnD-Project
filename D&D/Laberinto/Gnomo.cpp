/*
  Archivo: Gnomo.cpp

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
#include<stdlib.h>
#include "h/Gnomo.h"
using namespace std;

Gnomo::Gnomo(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje) :
       Objeto(jugador,dispositivo, filaMensaje, columnaMensaje)
{
}

Gnomo::~Gnomo()
{
}

void Gnomo::condicionDePaso() //evento que ocurre cuando el jugador se encuentra con el objeto
{
  dispositivo->imprimirMensaje(filaMensaje,columnaMensaje,"                                           ");
  int cualPregunta = 1 + (rand() % (6));   //Seleccion de pregunta al azar
  switch(cualPregunta)
  {
    case 1:
    dispositivo->imprimirMensaje(filaMensaje,1,
    "¿Cuál es la temperatura de ebullicíon del agua en grados celsius?\n\
    ♦(1) 50°C  ♦(2) 0°C  ♦(3) 4°C  ♦(4) 100°C");
    respuesta = dispositivo->leerTecla();
    while (respuesta != 4)
    {
      dispositivo->imprimirMensaje(filaMensaje+3,1, "¡INCORRECTO!");
      respuesta = dispositivo->leerTecla();
    }
    break;

    case 2:
    dispositivo->imprimirMensaje(filaMensaje,1,
    "¿Cuántas semanas tiene el año?\n\
    ♦(1) 52  ♦(2) 55  ♦(3) 50  ♦(4) 57");
    respuesta = dispositivo->leerTecla();
    while(respuesta != 1)
    {
      dispositivo->imprimirMensaje(filaMensaje+3,1, "¡INCORRECTO!");
      respuesta = dispositivo->leerTecla();
    }
    break;
    
    case 3:
    dispositivo->imprimirMensaje(filaMensaje,1,
    "¿Cuántos huesos tiene un humano adulto?\n\
    ♦(1) 184  ♦(2) 206  ♦(3) 211  ♦(4) 300");
    respuesta = dispositivo->leerTecla();
    while(respuesta != 2)
    {
      dispositivo->imprimirMensaje(filaMensaje+3,1, "¡INCORRECTO!");
      respuesta = dispositivo->leerTecla();
    }
    break;
    
    case 4:
    dispositivo->imprimirMensaje(filaMensaje,1,
    "¿Cuántos años tiene un lustro?\n\
    ♦(1) 7  ♦(2) 3  ♦(3) 10  ♦(4) 5");
    respuesta = dispositivo->leerTecla();
    while(respuesta != 4)
    {
      dispositivo->imprimirMensaje(filaMensaje+3,1, "¡INCORRECTO!");
      respuesta = dispositivo->leerTecla();
    }
    break;
    
    case 5:
    dispositivo->imprimirMensaje(filaMensaje,1,
    "¿Cuál es el país más grande del mundo?\n\
    ♦(1) Rusia  ♦(2) China  ♦(3) Canada  ♦(4) USA");
    respuesta = dispositivo->leerTecla();
    while(respuesta != 1)
    {
      dispositivo->imprimirMensaje(filaMensaje+3,1, "¡INCORRECTO!");
      respuesta = dispositivo->leerTecla();
    }
    break;
    
    case 6:
    dispositivo->imprimirMensaje(filaMensaje,1,
    "¿Cuántos dedos tengo escondidos detrás de mí?\n\
    ♦0    ♦1    ♦2    ♦3    ♦4    "); // esta pregunta No está mal, la quisimos así.
    respuesta = dispositivo->leerTecla();
    while(respuesta != 0)
    {
      dispositivo->imprimirMensaje(filaMensaje+3,1, "¡INCORRECTO!");
      respuesta = dispositivo->leerTecla();
    }
    break;
  }
  dispositivo->imprimirMensaje(filaMensaje,1,"¡Correcto! Toma un tesoro.                                         ");
  dispositivo->imprimirMensaje(filaMensaje+1,1,"                                                                 ");
  dispositivo->imprimirMensaje(filaMensaje+2,1,"                                                                 ");
  dispositivo->imprimirMensaje(filaMensaje+3,1,"                                                                 ");
  //Limpia la consola de los mensajes de las preguntas.
}

bool Gnomo::encontrar()
{
}

