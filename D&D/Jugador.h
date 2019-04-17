/*
  Archivo: Jugador.h
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
  Licencia: GPL


  Clase: Jugador
  
  Responsabilidad: xdd
  
  Colaboración: ddx
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
    int tesoros;
    
    
    public:
    /*
      Crea al jugador y lo pone en la entrada.
    */
    Jugador();
    /*
      Borra al jugador, al perder la partida o iniciar una nueva partida.
    */
    ~Jugador();
    /*
      Comprueba si el jugador está sobre un objeto e interactúa con él, 
      si está al lado del dragón le pregunta cuántos tesoros quiere y
      si está en la salida, gana el juego.
    */
    void interactuar();
}

#endif
