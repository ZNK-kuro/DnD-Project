/*
  Archivo: DispositivoTerminal.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL


  Clase: DispositivoTerminal
  Responsabilidad: manejar las entradas y salidas del juego Tetris sobre un terminal. Y ello implica leer la entrada (teclado) e imprimir
  en la salida (pantalla). De la entrada se pueden leer las órdenes que envíe el jugador y si quiere volver a jugar. A la salida se puede
  imprimir el tablero, la ficha siguiente y la lista de ganadores.
  (Para hacerlo, usa códigos de escape ANSI en el terminal, que están documentados aquí: https://en.wikipedia.org/wiki/ANSI_escape_code, por
  si alguien quiere saber más sobre ello).
  Colaboración: es un DispositivoDeEntradaSalida
*/

#ifndef DispositivoTerminal_HH
#define DispositivoTerminal_HH

#include "DispositivoEntradaSalida.h"
#include <termios.h>    // struct termios, tcgetattr(), tcsetattr()
#include <stdio.h>      // perror(), stderr, stdin, fileno()
#include <iostream>
#include <string>
using namespace std;


class DispositivoTerminal : public DispositivoEntradaSalida
{
  private:
    struct termios terminal_salvado;
    int grosorSimbolo;
    
  public:
    /**
        Construye un DispositivoTerminal, programándolo sin buffer y sin eco en pantalla.
        Antes de ello, salva el estado del terminal
    */
    DispositivoTerminal(int grosorSimbolo=2);
    
    /**
        Restaura el terminal a su estado inicial.
    */
    virtual ~DispositivoTerminal();
    
    /**
        Lee el nombre del jugador.
    */
    string leerNombre();
    
    /**
        Lee una única tecla del teclado, y la retorna con el siguiente convenio 
          return 1 si es la flecha hacia ARRIBA    ( 0x1b, 0x5b, 0x41 ) para girar en el sentido de las agujas del reloj
          return 2 si es la flecha hacia ABAJO     ( 0x1b, 0x5b, 0x42 )
          return 3 si es la flecha hacia DERECHA   ( 0x1b, 0x5b, 0x43 )
          return 4 si es la flecha hacia IZQUIERDA ( 0x1b, 0x5b, 0x44 )
    */
    int leerJugada();
    
    /**
        Lee si el jugador quiere volver a jugar (Si/No).
    */
    bool leerSiVolverAJugar();
    
    /**
        Imprime una única casilla del tablero dada por sus coordenadas (fila, columna) con un valor dado.
    */
    void imprimirTablero(int fila, int columna, int valor);
    
    /**
        Imprime una única casilla de la ficha siguiente dada por sus coordenadas (fila, columna) con un valor dado.
    */
    void imprimirFichaSiguiente(int fila, int columna, int valor);
    
    /**
        Imprime el nombre del jugador.
    */
    void imprimirNombre(string nombre);
    
    /**
        Imprime los puntos que ha logrado el jugador.
    */
    void imprimirPuntos(int puntos);
    
    /**
        Imprime la lista de ganadores.
    */
    void imprimirGanadores(string ganadores);
  
  protected:
    void imprimirSimbolo(int fila, int columna, string mensaje);
    void imprimirMensaje(int fila, int columna, string mensaje);
};

#endif




