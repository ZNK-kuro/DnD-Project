/*
  Archivo: Laberinto.cpp
  Autor: Ángel García Baños
         Nicolás Jaramillo M.
         Michelle...
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2018-09-17
  Fecha última modificación: 2018-10-08
  Versión: 0.1
  Licencia: GPL
*/

#include "Laberinto.h"

Laberinto::Laberinto(int numeroFilas, int numeroColumnas, int numeroTesoros, int numeroGnomos, int numeroDragones, double porcentajeCasillasVacias)
{
  this->numeroFilas = numeroFilas;
  this->numeroColumnas = numeroColumnas;
  this->numeroTesoros = numeroTesoros;
  this->numeroGnomos = numeroGnomos;
  this->numeroDragones = numeroDragones;
  this->porcentajeCasillasVacias = porcentajeCasillasVacias;
  tablero = new int*[numeroFilas];
  for(int fila=0; fila<numeroFilas; fila++)
  {
    tablero[fila] = new int[numeroColumnas];
    for(int columna=0; columna<numeroColumnas; columna++)
      tablero[fila][columna] = 1;  // Llena todo el laberinto con paredes
  }
  casillasVacias = 0;

  filaEntrada = rand()% numeroFilas;
  tablero[filaEntrada][0] = 5;  // Pone la entrada
  filaSalida = rand() % numeroFilas;
  tablero[filaSalida][numeroColumnas-1] = 6;  // Pone la salida
  if (porcentajeCasillasVacias > 50)
  {
    cout<< "El porcentaje de casillas vacías es muy alto, se establecerá en el valor máximo de 50%." <<endl;
    this->porcentajeCasillasVacias = 50;
  }
  if (porcentajeCasillasVacias < 10)
  {
    cout<< "El porcentaje de casillas vacías es muy bajo, se establecerá en el valor mínimo de 10%." <<endl;
    this->porcentajeCasillasVacias = 10;
  }
}


Laberinto::~Laberinto()
{
  for(int fila=0; fila<numeroFilas; fila++)
    delete tablero[fila];
  delete [] tablero;
}


void Laberinto::fabricarCamino()
{
  // Hacer el camino principal:
  
  casillasVacias += trazaLineaRecta(filaEntrada, 0, filaSalida, numeroColumnas-1);
  
  
  // Hacer caminos al azar:
  
  do
  {
    int filaInicial_Lineas;
    int columnaInicial_Lineas;
    if (porcentajeCasillasVacias<35) // Si el porcentaje es bajo se asegura que los caminos generados estén conectados
    {                                // esto evita la generación de caminos que no conectan de ninguna forma con el resto del laberinto
      do
      {
        // Selecciona posiciones pertenecientes a puntos vacíos (la primera vez pertenece al camino principal)
        filaInicial_Lineas = rand() % numeroFilas;  
        columnaInicial_Lineas = rand() % numeroColumnas;
      }
      while (tablero[filaInicial_Lineas][columnaInicial_Lineas] != 0);
    }
    else
    {
      filaInicial_Lineas = rand() % numeroFilas;  
      columnaInicial_Lineas = rand() % numeroColumnas;
    }
    

    int filaFinal_Lineas;
    int columnaFinal_Lineas;
    do
    {
      // Selecciona posiciones pertenecientes a puntos No vacíos 
      // esto evita que las lineas que se crean se superpongan completamente a otras ya existentes
      filaFinal_Lineas = rand() % numeroFilas;  
      columnaFinal_Lineas = rand() % numeroColumnas;
    } 
    while (tablero[filaFinal_Lineas][columnaFinal_Lineas] != 1);

    
    //Traza lineas cuyo punto inicial se encuentra vacío
    casillasVacias += trazaLineaRecta(filaInicial_Lineas, columnaInicial_Lineas, filaFinal_Lineas, columnaFinal_Lineas);
  }
  // Limita los espacios vacíos generados por las lineas rectas generadas
  while((((double)casillasVacias/((double)numeroFilas*(double)numeroColumnas))*100) < porcentajeCasillasVacias);
  


  // Poner los Tesoros al azar:
  
  for (int tesoros=0; tesoros<numeroTesoros; tesoros++)
    ponerEnCasillaVaciaAlAzar(2);


  // Poner los Gnomos al azar:
  
  for(int gnomos=0; gnomos<numeroGnomos; gnomos++)
    ponerEnCasillaVaciaAlAzar(3);


  // Poner los Dragones al azar, cerca de la salida:
  
  for(int dragones=0; dragones<numeroDragones; dragones++)
    ponerEnCasillaVaciaAlAzar(4);

}


int Laberinto::trazaLineaRecta(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal)
{
  int contarVacias = 0;
  
  double pendiente = ((double)filaFinal-(double)filaInicial)/((double)(columnaFinal-columnaInicial));
  int fila= filaInicial;
  double sumarPendiente = 0;
  
  for (int columna=columnaInicial+1; columna<columnaFinal; columna++)
  {
    sumarPendiente += pendiente;
    if (((int)(filaInicial+sumarPendiente)) != fila)
    {
      if (tablero[fila][columna]!=0)
      {
        tablero[fila][columna]=0;
        contarVacias++;
      }
      
      if (tablero[fila][columna+1]!=0)
      {
        tablero[fila][columna+1]=0;
        contarVacias++;
      }
      
    }
    
    
    fila = filaInicial+sumarPendiente;
    if (tablero[fila][columna]!=0)
    {  
      tablero[fila][columna]=0;
      contarVacias++;
    }
    
    
    if ((filaInicial<filaFinal) && (columna==columnaFinal-1))
    {
      if(tablero[fila+1][columna-1]!=0)
      {
        tablero[fila+1][columna-1]=0;
        contarVacias++;
      }
        
      if(tablero[fila+1][columna]!=0)
      {
        tablero[fila+1][columna]=0;
        contarVacias++;
      }
      
    }

  }


  return contarVacias;
}





void Laberinto::imprimir()
{
  for(int columna=0; columna<numeroColumnas+2; columna++)
    cout << "X";
  cout << endl;
  for(int fila=0; fila<numeroFilas; fila++)
  {
    cout << "X";
    for(int columna=0; columna<numeroColumnas; columna++)
      if(tablero[fila][columna] == 0)
        cout << " ";
      else
        cout << tablero[fila][columna];
    cout << "X" << endl;
  }
  for(int columna=0; columna<numeroColumnas+2; columna++)
    cout << "X";
  cout << endl;
}
    

void Laberinto::buscarCasillaAlAzar(int &fila, int &columna, int contenido)
{
  //Se encarga del caso especial (dragones)
  if (contenido==4)
  {
    do
    {
      fila = rand() % numeroFilas;
      //Restringe los valores de columna,esto permite que el dragon se situe cerca a la salida.
      columna = (numeroColumnas * 3/4) + (rand() % (numeroColumnas/4));
    }
    while(tablero[fila][columna] != 0);
  }
  else
  {
    do
    {
      fila = rand() % numeroFilas;
      columna = rand() % numeroColumnas;
    }
    while(tablero[fila][columna] != 0);
  }
}


void Laberinto::ponerEnCasillaVaciaAlAzar(int contenido)
{
  int fila, columna;
 
  buscarCasillaAlAzar(fila, columna, contenido);
  tablero[fila][columna] = contenido;
  
}

