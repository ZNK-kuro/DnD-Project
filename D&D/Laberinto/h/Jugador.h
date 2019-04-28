/*
  Archivo: Jugador.h

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL


  Clase: Jugador
  
  Responsabilidad: 
  Guarda los datos la fila, columna y el numero de tesoros del jugador.
  Puede moverse, coger tesoros, dar tesoros, decir en dónde está y decir el número de tesoros que tiene.
  
  Colaboración: Ninguna.
*/

#ifndef Jugador_HH 
#define Jugador_HH 

#include <string>
using namespace std;

class Jugador
{
    private:
      int fila_Jugador;
      int columna_Jugador;
      int tesoros = 0;
    
    public:
    /*
      Crea al jugador y lo pone en la entrada.
    */
    Jugador(int fila_Jugador, int columna_Jugador);
    ~Jugador();
    
    void cogerTesoro(); // Aumenta en 1 el número de tesoros.
    bool darTesdoro(int numTesoros); // Da la cantidad de tesoros que le piden (true) o retorna falso.
    void dondeEstas(int *fila, int *columna); // Devuelve su posición en el laberinto.
    void nuevaPosicion(int fila, int columna); // Cambia su posición en el laberinto.
    int tesorosJugador(); // Retorna la cantidad de tesoros que posee.
};

#endif
