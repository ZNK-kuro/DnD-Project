/*
  Archivo: Jugador.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL


  Clase: Jugador
  
  Responsabilidad: 
  -Guarda los datos del jugador como son fila, columna y en numero de tesoros
  -Contiene todas las funciones que permiten al jugador moverse e interactuar con todo lo que hay dentro del laberinto
  
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
    /*
      Borra al jugador, al perder la partida o iniciar una nueva partida.
    */
    ~Jugador();
    /*
      Comprueba si el jugador está sobre un objeto e interactúa con él, 
      si está al lado del dragón le pregunta cuántos tesoros quiere y
      si está en la salida, gana el juego.
    */
    //void interactuar();
    void cogerTesoro();
    void responderPregunta();
    bool darTesdoro(int numTesoros);
    void dondeEstas(int *fila, int *columna);
    void nuevaPosicion(int fila, int columna);
    int tesorosJugador();
};

#endif
