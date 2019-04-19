/*
  Archivo: DispositivoQt.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL


  Clase: DispositivoQt
  Responsabilidad: manejar las entradas y salidas del juego Tetris sobre un ambiente gráfico de Qt. 
  Y ello implica leer la entrada (mouse) e imprimir en la salida (en una ventana).
  Colaboración: es un DispositivoDeEntradaSalida
*/

#ifndef DispositivoQt_HH
#define DispositivoQt_HH

#include "DispositivoEntradaSalida.h"


class DispositivoQt : public DispositivoEntradaSalida
{
  private:
    
  public:
    /**
        Construye un DispositivoQt
    */
    DispositivoQt();
    /**
        Cierra el ambiente gráfico de Qt.
    */
    virtual ~DispositivoQt();
    /**
        Lee el nombre del jugador.
    */
    string leerNombre();
    /**
        Lee una única acción del mouse, y la retorna con el siguiente convenio 
          return 1 si es hacia ARRIBA    para girar en el sentido de las agujas del reloj
          return 2 si es hacia ABAJO
          return 3 si es hacia DERECHA
          return 4 si es hacia IZQUIERDA
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
};

#endif




