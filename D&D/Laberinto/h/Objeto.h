/*
  Archivo: Objeto.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL


  Clase: Objeto

  Responsabilidad: Se encarga de guardar el puntero jugador de tipo jugador del cual heredan dragon, gnomo y tesoro

  Colaboración: Es una clase abstracta
*/


#ifndef Objeto_HH
#define Objeto_HH

#include <string>
#include "Jugador.h"
using namespace std;

class Objeto
{
  protected:
    Jugador *jugador;
    //int fila_Objeto;
    //int columna_Objeto;
    //string nombre;
    //virtual bool atributo;

  public:
    Objeto(Jugador *jugador);
    virtual ~Objeto();
/*
    //eventos que ocurren cuando el jugador se encuentra con el objeto
    virtual void condicionDePaso();
    virtual void encontrar();
    virtual void comoTeLLamas();
    */
};

#endif
