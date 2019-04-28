/*
  Archivo: Tesoro.h

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL


  Clase: Tesoro

  Responsabilidad:
  -Si encuentra un tesoro aumenta la cantidad de tesorso del jugador

  Colaboración: parece un Objeto
*/

#ifndef Tesoro_HH
#define Tesoro_HH

#include <string>
#include "Objeto.h"
#include "Jugador.h"
#include "../../Interfaz/h/DispositivoTerminal.h"
using namespace std;

class Tesoro : public Objeto
{
  public:
    Tesoro(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje);
    ~Tesoro();
    void condicionDePaso();
    bool encontrar();
};

#endif
