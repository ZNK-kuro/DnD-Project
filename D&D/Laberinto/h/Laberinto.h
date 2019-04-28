/*
  Archivo: Laberinto.h
  
  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558
            Michelle Gonzalez H.     (del taller 3)

  Email: angel.garcia@correounivalle.edu.co
         nicolas.jaramillo@correounivalle.edu.co
         garcia.crhistian@correounivalle.edu.co
         michelle.hernandez@correounivalle.edu.co

  Fecha creación:       2018/09/17
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL

  Clase: Laberinto
  
  Responsabilidad:
    - Mantener los datos de un laberinto que son numero de filas, numero de columnas, número de tesoros, gnomos y dragones, así como
      el porcentaje de casillas que van a estar vacías, respecto al total de casillas (numero de filas * numero de columnas).
      En cada casilla puede haber:
        0 = vacía
        1 = pared
        2 = tesoro
        3 = gnomo
        4 = dragon
        5 = entrada (tiene que estar en la columna de más a la izquierda)
        6 = salida (tiene que estar en la columna de más a la derecha)
    - Construir al azar un laberinto que cumpla con los datos especificados.
    - Imprimir el laberinto en pantalla.
    
  Colaboración:
    - Contiene un array de dos dimensiones de enteros, implementado como un puntero doble (para que sea de tamaño variable).
*/


#ifndef LABERINTO_H
#define LABERINTO_H

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;


class Laberinto
{
  private:
    int numeroFilas;
    int numeroColumnas;
    int numeroTesoros;
    int numeroGnomos;
    int numeroDragones;
    double porcentajeCasillasVacias;
    int **tablero;
    int casillasVacias;
    int filaEntrada;
    int filaSalida;
    int intentosLineas = 0;


  public:
    Laberinto(int numeroFilas, int numeroColumnas, int numeroTesoros, int numeroGnomos, int numeroDragones, double porcentajeCasillasVacias);
    ~Laberinto();
    void fabricarCamino();
    void imprimir();
    int queHayAqui(int fila, int columna);
    void colocaAqui(int fila, int columna, int colocar);
    int dime_filaEntrada();

  protected:
    /**
      Retorna el número de casillas que ocupó el camino trazado
    */
    int caminoPrincipal(int filaInicial, int columnaInicial, int direccion);
    int trazaLineaRecta(int filaInicial, int columnaInicial, int direccion);
    void buscarCasillaAlAzar(int &fila, int &columna, int contenido);
    void ponerEnCasillaVaciaAlAzar(int contenido);
    int escogerDireccion();
};

#endif
