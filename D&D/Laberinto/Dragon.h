/*
  Archivo: Dragon.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL


  Clase: Dragon
  
  Responsabilidad: xdd
  
  Colaboración: ddx
*/

#ifndef Dragon_HH
#define Dragon_HH

#include "Objeto.h"
#include <string>

class Dragon : public Objeto
{
  private:
  
  public:
    Dragon(int fila_Objeto, int columna_Objeto);
    ~Dragon();

    void condicionDePaso();
  
};

#endif