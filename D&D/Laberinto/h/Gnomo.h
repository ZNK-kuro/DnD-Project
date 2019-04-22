/*
  Archivo: Gnomo.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL


  Clase: Gnomo
  
  Responsabilidad: xdd
  
  Colaboración: ddx
*/

#ifndef Gnomo_HH
#define Gnomo_HH

#include <string>
#include "Objeto.h"
#include "Jugador.h"
using namespace std;

class Gnomo : public Objeto
{
  private:
  
  
  public:
    Gnomo(Jugador *jugador);
    ~Gnomo();
    //void condicionDePaso();
};

#endif