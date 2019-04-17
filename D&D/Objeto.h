/*
  Archivo: Objeto.h
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
  Licencia: GPL


  Clase: Objeto
  
  Responsabilidad: xdd
  
  Colaboración: ddx
*/


#ifndef Objeto_HH
#define Objeto_HH

#include<string>
using namespace std;

class Objeto
{
  protected:
    int fila_Objeto;
    int columna_Objeto;
    string nombre;
  
  public:
    Objeto(int fila_Objeto, int columna_Objeto, string nombre);
    virtual ~Objeto();
    virtual void evento()=0; //evento que ocurre cuando el jugador se encuentra con el objeto
    
}

#endif
