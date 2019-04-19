/*
  Archivo: Gnomo.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL
*/

#include "../Gnomo.h"
#include <iostream>
#include<stdlib.h>
using namespace std;

Gnomo::Gnomo(int fila_Objeto, int columna_Objeto) : Objeto(fila_Objeto, columna_Objeto)
{
  this-> fila_Objeto = fila_Objeto;
  this-> columna_Objeto = columna_Objeto;
}

Gnomo::~Gnomo()
{
}
/*
void Gnomo::codicionDePaso() //evento que ocurre cuando el jugador se encuentra con el objeto
{
  Objeto::condicionDePaso();
  cualPregunta =1 + (rand() % (3))   //Seleccion de pregunta al zar
  switch(cualPregunta)
  {
    case 1:
    cout<<"decirme la temperatura de ebullicíon del agua en grados centigrados."; break;

    case 2:
    cout<<"decirme el numero de dias de la semana."; break;

    case 3:
    cout<<"decirme cuantos dedos tiene una mano humana."; break;
  }
  cout<<endl;

}
*/
