/*
  Archivo: DispositivoEntradaSalida.h

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL


  Clase: DispositivoEntradaSalida
  
  Responsabilidad: 
  Manejar las entradas y salidas del juego D&D sobre un terminal. Y ello implica leer la entrada e imprimir
  en la salida. Es una clase abstracta que debe implementarse en las clases derivadas.
  
  Colaboración: ninguna
*/

#ifndef DispositivoEntradaSalida_HH
#define DispositivoEntradaSalida_HH

#include <string>
using namespace std;


class DispositivoEntradaSalida
{
  protected:
    int fila_nombre;
    int columna_nombre;
    int ancho_nombre;
    
    int fila_puntos;
    int columna_puntos;
    int ancho_puntos;
    
    int fila_tesoros;
    int columna_tesoros;
    
    int fila_ganadores;
    int columna_ganadores;
    int ancho_ganadores;
    int alto_ganadores;
    
    int fila_mensaje; 
    int columna_mensaje;
    
  public:
    DispositivoEntradaSalida(int fila_nombre=0,
                             int columna_nombre=0,
                             int ancho_nombre=3,
                             
                             int fila_puntos=0,
                             int columna_puntos=14,
                             int ancho_puntos=10,
                             
                             int fila_tesoros=0,
                             int columna_tesoros=28,
                             
                             int fila_ganadores=11,
                             int columna_ganadores=4,
                             int ancho_ganadores=10,
                             int alto_ganadores=10,
                             
                             int fila_mensaje=36, 
                             int columna_mensaje=2
                            );
    virtual ~DispositivoEntradaSalida();
    virtual string leerNombre() = 0;
    virtual int leerJugada() = 0;
    virtual bool leerSiVolverAJugar() = 0;
    virtual void imprimirNombre(string nombre) = 0;
    virtual void imprimirPuntos(int puntos) = 0;
    virtual void imprimirGanadores(string ganadores) = 0;
};

#endif
