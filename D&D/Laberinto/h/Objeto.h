/*
  Archivo: Objeto.h

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

  Responsabilidad: 
  Se encarga de guardar un puntero al jugador, un puntero al dispositivoTerminal (para imprimir mensajes)
  y la fila y columna en la que se imprimen mensajes, atributos que heredan dragon, gnomo y tesoro.
  
  Colaboración: Es una clase abstracta.
*/
#ifndef Objeto_HH
#define Objeto_HH

#include <string>
#include "Jugador.h"
#include "../../Interfaz/h/DispositivoTerminal.h"
using namespace std;

class Objeto
{
  protected:
    Jugador *jugador;
    DispositivoTerminal *dispositivo;
    int filaMensaje;
    int columnaMensaje;

  public:
    Objeto(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje);
    virtual ~Objeto();
    virtual void condicionDePaso() = 0; // Evento que ocurre cuando el jugador está al lado de un objeto.
    virtual bool encontrar() = 0; // Evento que ocurre cuando el jugador entra en la misma casilla de un objeto.
};

#endif
