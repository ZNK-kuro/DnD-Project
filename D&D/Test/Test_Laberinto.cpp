/*
  Archivo: Test_Laberinto.cpp
  Autor: Ángel García Baños
         Michelle Gonzalez H.        1871074
         Nicolas Jaramillo M.        1840558
  Email: angel.garcia@correounivalle.edu.co
         michelle.hernandez@correounivalle.edu.co
         nicolas.jaramillo@correounivalle.edu.co
  Fecha creación: 2018/09/17
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL
*/

/*
  Pruebas para el Laberinto
  Para compilar:
  g++ -std=c++11 ../Laberinto.cpp Test_Laberinto.cpp -o Test_Laberinto
*/

#include <cstdlib>
#include <iostream>
#include "../Laberinto/h/Laberinto.h"
#include "../Interfaz/h/DispositivoTerminal.h"
#include "../Interfaz/h/HallDeLaFama.h"
using namespace std;


int main()
{
  srand(time(0));
  bool volverAjugar=true;
  int fila_Laberinto;
  int columna_Laberinto;
  DispositivoTerminal dispositivo(1);
  HallDeLaFama hallDeLaFama("D&D-HallDeLaFama.txt"); //"D&D-HallDeLaFama.txt"
/*  hallDeLaFama.nuevoGanador("ZNK", 999);
  hallDeLaFama.nuevoGanador("CRH", 666);
  hallDeLaFama.nuevoGanador("AAA", 1000); */
  do
  {
    int accion = dispositivo.menu();  // Escoger acción.
    switch (accion)
    {
      case 1 : // Jugar
      case 2 :
      case 3 :
      {
        switch (accion) // Escoger dificultad
        {
          case 1: // Jugar > Fácil
          {
            fila_Laberinto = 10;
            columna_Laberinto = 40;
            break;
          }
          case 2: // Jugar > Medio
          {
            fila_Laberinto = 20;
            columna_Laberinto = 80;
            break;
          }
          case 3: // Jugar > Difícil
          {
            fila_Laberinto = 30;
            columna_Laberinto = 120;
            break;
          }
        }
        
        system("clear");
        Laberinto laberinto(fila_Laberinto,columna_Laberinto,5,3,2,35);
        laberinto.fabricarCamino();
        //cout << endl << "Laberinto terminado" << endl;
        laberinto.imprimir();
        //dispositivo.leerJugada();

        dispositivo.leerNombre();

        system("clear");
        dispositivo.imprimirGanadores("HALL DE LA FAMA\n" + hallDeLaFama.listaDeGanadores());
        volverAjugar = dispositivo.leerSiVolverAJugar();
        system("clear");
        break;
      }
      
      case 4 : // Hall de la fama
      {
        system("clear");
        dispositivo.imprimirGanadores("HALL DE LA FAMA\n" + hallDeLaFama.listaDeGanadores());
        break;
      }
      case 5 : // Salir
      {
        volverAjugar = false;
        break;
      }
    }
  }
  while (volverAjugar);
  return 0;
}
