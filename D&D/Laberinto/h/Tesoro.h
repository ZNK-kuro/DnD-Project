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

  Responsabilidad: xdd

  Colaboración: ddx
*/

#ifndef Tesoro_HH
#define Tesoro_HH

#include "Objeto.h"
#include <string>

class Tesoro : public Objeto
{

  public:
    Tesoro(int fila_Objeto, int columna_Objeto);
    ~Tesoro();
    void encontrar(); //evento que ocurre cuando el jugador se encuentra con el objeto

};

#endif
