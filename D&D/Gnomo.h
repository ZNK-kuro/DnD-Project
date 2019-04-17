/*
  Archivo: Gnomo.h
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
  Licencia: GPL


  Clase: Gnomo
  
  Responsabilidad: xdd
  
  Colaboración: ddx
*/

#ifndef Gnomo_HH
#define Gnomo_HH

#include "Objeto.h"
#include <string>

class Gnomo : protected Objeto
{
  private:
  
  
  public:
    Gnomo(int fila_Objeto, int columna_Objeto, string nombre);
    ~Gnomo();
    
    
    void condicionDePaso();
  
}

#endif