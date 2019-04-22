/*
  Archivo: Dragon.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL


  Clase: Dragon
  
  Responsabilidad: 
  -Mantiene la variable peaje la cual al compararse con el numero de tesoros que tenga el jugador en la funcion condcionDePaso da
  o niega el paso al jugador
  -Comprueba si el jugador encuentra un dragon y s 
  
  Colaboración: parece un Objeto
*/

#ifndef Dragon_HH
#define Dragon_HH

#include <string>
#include "Objeto.h"
#include "Jugador.h"
using namespace std;

class Dragon : public Objeto
{
  private:
    int peaje;
  
  public:
    Dragon(Jugador *jugador);
    ~Dragon();

    void condicionDePaso();
    bool encontrar();
  
};

#endif