/*
  Archivo: Test_Laberinto.cpp
  Autor: Ángel García Baños
         Michelle Gonzalez H.        1871074
         Nicolas Jaramillo M.        1840558
  Email: angel.garcia@correounivalle.edu.co
         michelle.hernandez@correounivalle.edu.co
         nicolas.jaramillo@correounivalle.edu.co
  Fecha creación: 2018/09/17
  Última modificación:  2019/04/22
  Versión: 0.6.2
  Licencia: GPL
*/

/*
  Pruebas para el Laberinto
  Para compilar:
  g++ -std=c++11 ../Interfaz/*.cpp ../Laberinto/*.cpp *.cpp -o Test_Laberinto
*/

#include <cstdlib>
#include <iostream>
#include "../Interfaz/h/DispositivoTerminal.h"
#include "../Interfaz/h/HallDeLaFama.h"
#include "../Laberinto/h/Laberinto.h"
#include "../Laberinto/h/Jugador.h"
#include "../Laberinto/h/Tesoro.h"
#include "../Laberinto/h/Gnomo.h"
#include "../Laberinto/h/Dragon.h"
using namespace std;


int main()
{
  srand(time(0));
  bool volverAjugar=true;

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
        bool ganador = false;
        bool perdedor = false;
        int fila_Laberinto;
        int columna_Laberinto;
        int numTesoros;
        int numGnomos;
        int numDragones;
        int filaMensaje;
        int columnaMensaje;
        int filaJ = 0;
        int columnaJ = 0;
        int puntosJ;
        string nombre;
        
        switch (accion) // Escoger dificultad
        {
          case 1: // Jugar > Fácil
          {
            fila_Laberinto    = 10;
            columna_Laberinto = 40;
            numTesoros  = 4;
            numGnomos   = 2;
            numDragones = 1;
            filaMensaje = 12;
            columnaMensaje = 1;
            puntosJ = 50;
            break;
          }
          case 2: // Jugar > Medio
          {
            fila_Laberinto    = 20;
            columna_Laberinto = 80;
            numTesoros  = 5;
            numGnomos   = 4;
            numDragones = 3;
            filaMensaje = 22;
            columnaMensaje = 23;
            puntosJ = 100;
            break;
          }
          case 3: // Jugar > Difícil
          {
            fila_Laberinto    = 30;
            columna_Laberinto = 120;
            numTesoros  = 6;
            numGnomos   = 6;
            numDragones = 6;
            filaMensaje = 32;
            columnaMensaje = 43;
            puntosJ = 200;
            break;
          }
        }
        
        system("clear");
        nombre = dispositivo.leerNombre();
        dispositivo.imprimirNombre(nombre);
        //cout<< "?" <<endl; // debug purpose
        Laberinto laberinto(fila_Laberinto,columna_Laberinto,
                            numTesoros,numGnomos,numDragones,35);
        Jugador jugador(laberinto.dime_filaEntrada(), 1);
        Tesoro tesoro(&jugador,&dispositivo,filaMensaje,columnaMensaje);
        Gnomo gnomo(&jugador,&dispositivo,filaMensaje,columnaMensaje);
        Dragon dragon(&jugador,&dispositivo,filaMensaje,columnaMensaje);
        //cout<< "?" <<endl; // debug purpose
        laberinto.fabricarCamino();
        //cout << endl << "Laberinto terminado" << endl; // debug purpose
        laberinto.imprimir();
        
        do
        {
          jugador.dondeEstas(&filaJ, &columnaJ);
          dispositivo.imprimirMensaje(filaJ+2, columnaJ+1, "♥"); // Se imprime al jugador cada turno
          dispositivo.imprimirPuntos(puntosJ);                   // También se imprimen los puntos y los tesoros.
          dispositivo.imprimirTesoros(jugador.tesorosJugador());
          
          dispositivo.imprimirMensaje(36,0," ");
          int movimientoHor = 0;
          int movimientoVer = 0;
          // qué hay en la posición a moverse? / comprobar si hay un objeto al lado del jugador va aquí.
          int queHay = laberinto.queHayAqui(filaJ + movimientoVer, columnaJ + movimientoHor);
          if (not ganador and not perdedor) //revisa las casillas al lado de la nueva posición del jugador.
          {
            queHay = laberinto.queHayAqui(filaJ - 1, columnaJ); //arriba
            if (queHay == 2)
              tesoro.condicionDePaso();
            if (queHay == 3)
            {
              gnomo.condicionDePaso();
              laberinto.colocaAqui(filaJ -1, columnaJ, 2);
              dispositivo.imprimirMensaje(filaJ +1, columnaJ +1,"♦");
              dispositivo.imprimirMensaje(filaMensaje, columnaMensaje, " ");
            }
            if (queHay == 4)
              dragon.condicionDePaso();
            
            queHay = laberinto.queHayAqui(filaJ , columnaJ - 1); //izquierda
            if (queHay == 2)
              tesoro.condicionDePaso();
            if (queHay == 3)
            {
              gnomo.condicionDePaso();
              laberinto.colocaAqui(filaJ , columnaJ - 1, 2);
              dispositivo.imprimirMensaje(filaJ +2, columnaJ,"♦");
              dispositivo.imprimirMensaje(filaMensaje, columnaMensaje, " ");
            }
            if (queHay == 4)
              dragon.condicionDePaso();
            
            queHay = laberinto.queHayAqui(filaJ + 1, columnaJ); //abajo
            if (queHay == 2)
              tesoro.condicionDePaso();
            if (queHay == 3)
            {
              gnomo.condicionDePaso();
              laberinto.colocaAqui(filaJ +1, columnaJ, 2);
              dispositivo.imprimirMensaje(filaJ +3, columnaJ +1,"♦");
              dispositivo.imprimirMensaje(filaMensaje, columnaMensaje, " ");
            }
            if (queHay == 4)
              dragon.condicionDePaso();
            
            queHay = laberinto.queHayAqui(filaJ , columnaJ + 1); //derecha
            if (queHay == 2)
              tesoro.condicionDePaso();
            if (queHay == 3)
            {
              gnomo.condicionDePaso();
              laberinto.colocaAqui(filaJ, columnaJ + 1, 2);
              dispositivo.imprimirMensaje(filaJ +2, columnaJ +2,"♦");
              dispositivo.imprimirMensaje(filaMensaje, columnaMensaje, " ");
            }
            if (queHay == 4)
              dragon.condicionDePaso();
          }
          switch(dispositivo.leerJugada())
          {
            case 1: // arriba
            {
              movimientoVer = -1;
              break;
            }
            case 2: // izquierda
            {
              movimientoHor = -1;
              break;
            }
            case 3: // abajo
            {
              movimientoVer = 1;
              break;
            }
            case 4: // derecha
            {
              movimientoHor = 1;
              break;
            }
            default: 
            {
              // ?
              break;
            }
          }                                           // limpia el mensaje anterior
          dispositivo.imprimirMensaje(filaMensaje,columnaMensaje,"                                           ");
          queHay = laberinto.queHayAqui(filaJ + movimientoVer, columnaJ + movimientoHor);
          switch(queHay)
          {
            case 0: // Si no hay nada (y no es la casilla en la que está) el jugador se mueve
            {
              if (movimientoHor != movimientoVer)
              {
                dispositivo.imprimirMensaje(filaJ+2, columnaJ+1, " ");
                jugador.nuevaPosicion(filaJ + movimientoVer, columnaJ + movimientoHor);
                if (puntosJ == 0) // si los puntos llegan a cero, perdiste.
                {
                  perdedor = true;
                  dispositivo.imprimirMensaje(filaMensaje,columnaMensaje,
                  nombre + " Te has perdido en el laberinto. " + "\nPresiona una flecha para continuar.");
                  dispositivo.leerJugada();
                }
                else
                  puntosJ--;
              }
              break;
            }
            
            case 2: // Tesoro
            {
              puntosJ += 100;
              tesoro.encontrar();
              jugador.nuevaPosicion(filaJ + movimientoVer, columnaJ + movimientoHor);
              laberinto.colocaAqui(filaJ + movimientoVer, columnaJ + movimientoHor, 0);
              dispositivo.imprimirMensaje(filaJ+2, columnaJ+1, " ");
              
              
              break;
            }
            case 4: // Dragon
            {
              if (dragon.encontrar())
              {
                puntosJ += 200;
                laberinto.colocaAqui(filaJ + movimientoVer, columnaJ + movimientoHor, 0);
                dispositivo.imprimirMensaje(filaJ+2, columnaJ+1, " ");
                jugador.nuevaPosicion(filaJ + movimientoVer, columnaJ + movimientoHor);
                dispositivo.imprimirMensaje(filaMensaje,columnaMensaje,
                "Pasaste al dragón. + 200 puntos");
              }
              else
              {
                if (puntosJ < 200) // si el dragon te come pierdes 200 puntos.
                  puntosJ = 0;
                else
                  puntosJ -= 200;
                perdedor = true;
                dispositivo.imprimirPuntos(puntosJ);
                dispositivo.imprimirTesoros(jugador.tesorosJugador());
                dispositivo.imprimirMensaje(filaJ+2, columnaJ+1, " ");
                dispositivo.imprimirMensaje(filaMensaje,columnaMensaje-2,
                nombre + " te comieron... Tu puntaje fue: " + to_string(puntosJ)
                + "\nPresiona una flecha para continuar.");
                dispositivo.leerJugada();
              }
              break;
            }
            case 6: // Salida
            {
              ganador = true;
              dispositivo.imprimirMensaje(filaMensaje,columnaMensaje,
              "¡¡GANADOR!! " + nombre + " Tu puntaje fue: " + to_string(puntosJ)
              + "\nPresiona una flecha para continuar.");
              dispositivo.leerJugada();
              break;
            }
            default: // case 1, 3 y 5 (Pared, Gnomo Y entrada)
              break;
          }
          
        }
        while (not ganador and not perdedor);
        
        
        system("clear");
        dispositivo.imprimirMensaje(0,1, nombre + " Tu puntaje fue: " + to_string(puntosJ));
        hallDeLaFama.nuevoGanador(nombre, puntosJ);
        dispositivo.imprimirMensaje(3,4,
        "HALL DE LA FAMA\n" + hallDeLaFama.listaDeGanadores() + "\n Gracias por jugar :3");
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
