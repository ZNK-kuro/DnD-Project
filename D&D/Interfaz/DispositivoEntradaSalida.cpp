/*
  Archivo: DispositivoEntradaSalida.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL
*/

#include "h/DispositivoEntradaSalida.h"


DispositivoEntradaSalida::DispositivoEntradaSalida
(
  int fila_nombre, 
  int columna_nombre, 
  int ancho_nombre,
  
  int fila_puntos, 
  int columna_puntos, 
  int ancho_puntos,
  
  int fila_tesoros,
  int columna_tesoros,
 
  int fila_ganadores, 
  int columna_ganadores, 
  int ancho_ganadores, 
  int alto_ganadores,
 
  int fila_mensaje, 
  int columna_mensaje
)
  
  : fila_nombre(fila_nombre),
    columna_nombre(columna_nombre),
    ancho_nombre(ancho_nombre),
    
    fila_puntos(fila_puntos),
    columna_puntos(columna_puntos),
    ancho_puntos(ancho_puntos),
    
    fila_tesoros(fila_tesoros),
    columna_tesoros(columna_tesoros),
    
    fila_ganadores(fila_ganadores),
    columna_ganadores(columna_ganadores),
    ancho_ganadores(ancho_ganadores),
    alto_ganadores(alto_ganadores),
    
    fila_mensaje(fila_mensaje), 
    columna_mensaje(columna_mensaje)
{
}


DispositivoEntradaSalida::~DispositivoEntradaSalida()
{
}
