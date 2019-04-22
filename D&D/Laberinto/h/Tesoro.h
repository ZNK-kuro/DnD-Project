/*
  Archivo: Tesoro.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
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
using namespace std;

class Tesoro : public Objeto
{

  public:
    Tesoro(Jugador *jugador);
    ~Tesoro();
    void encontrar(); //evento que ocurre cuando el jugador se encuentra con el objeto
};

#endif
