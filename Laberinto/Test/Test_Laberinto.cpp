/*
  Archivo: Test_Laberinto.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-09-17
  Fecha última modificación: 2018-09-22
  Versión: 0.1
  Licencia: GPL
*/

/*
  Pruebas para el Laberinto
  Para compilar:
  g++ -std=c++11 ../Laberinto.cpp Test_Laberinto.cpp -o Test_Laberinto
*/

#include "../Laberinto.h"
#include<cstdlib>
#include <iostream>
using namespace std;


int main()
{
  srand(time(0));

  Laberinto laberinto(20,80,5,3,2,35);
  cout << endl << "Laberinto vacío" << endl;
  laberinto.imprimir();
  laberinto.fabricarCamino();
  cout << endl << "Laberinto terminado" << endl;
  laberinto.imprimir();

  return 0;
}
