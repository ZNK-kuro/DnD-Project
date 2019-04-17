/*
  Archivo: Tesoro.h
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
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
    Tesoro(int fila_Objeto, int columna_Objeto, string nombre);
    ~Tesoro();
    void encontrar(); //evento que ocurre cuando el jugador se encuentra con el objeto
    
}

#endif