/*
  Archivo: Laberinto.h
  Autor: Ángel García Baños
         Michelle Gonzalez H.        1871074
         Nicolas Jaramillo M.        1840558
  Email: angel.garcia@correounivalle.edu.co
         michelle.hernandez@correounivalle.edu.co
         nicolas.jaramillo@correounivalle.edu.co
  Fecha creación: 2018/09/17
  Fecha última modificación: 2018/10/18
  Versión: 0.4
  Licencia: GPL
*/

/*
  Clase: Laberinto
  Responsabilidad:
    - Mantener los datos de un laberinto que son numero de filas, numero de olumnas, número de tesoros, gnomos y dragones, así como
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

#include<cstdlib>
#include<cmath>
#include<iostream>
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


  public:
    Laberinto(int numeroFilas, int numeroColumnas, int numeroTesoros, int numeroGnomos, int numeroDragones, double porcentajeCasillasVacias);
    ~Laberinto();
    void fabricarCamino();
    void imprimir();

  protected:
    /**
      Retorna el número de casillas que ocupó el camino trazado
    */
//    int trazaLineaRecta(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal);
    int caminoPrincipal(int filaInicial, int columnaInicial, int direccion);
    int trazaLineaRecta(int filaInicial, int columnaInicial, int direccion);
    void buscarCasillaAlAzar(int &fila, int &columna, int contenido);
    void ponerEnCasillaVaciaAlAzar(int contenido);
    int escogerDireccion();
};

#endif
