/*
  Archivo: Laberinto.cpp
  Autor: Ángel García Baños
         Michelle Gonzalez H.        1871074
         Nicolas Jaramillo M.        1840558
  Email: angel.garcia@correounivalle.edu.co
         michelle.hernandez@correounivalle.edu.co
         nicolas.jaramillo@correounivalle.edu.co
  Fecha creación: 2018/09/17
  Fecha última modificación: 2018/10/14
  Versión: 0.1.2
  Licencia: GPL
*/

#include "Laberinto.h"

Laberinto::Laberinto(int numeroFilas, int numeroColumnas, int numeroTesoros,
  int numeroGnomos, int numeroDragones, double porcentajeCasillasVacias)
{ // Constructor
  this->numeroFilas = numeroFilas;
  this->numeroColumnas = numeroColumnas;
  this->numeroTesoros = numeroTesoros;
  this->numeroGnomos = numeroGnomos;
  this->numeroDragones = numeroDragones;
  this->porcentajeCasillasVacias = porcentajeCasillasVacias;
  casillasVacias = 0;
  filaEntrada = rand()% numeroFilas;
  tablero = new int*[numeroFilas];

  for(int fila=0; fila<numeroFilas; fila++)
  { // Llena todo el laberinto con paredes
    tablero[fila] = new int[numeroColumnas];
    for(int columna=0; columna<numeroColumnas; columna++)
      tablero[fila][columna] = 1;
  }

  if (porcentajeCasillasVacias > 50)
  { // Limíta el porcentaje máximo de casillas vacías
    cout<< "El porcentaje de casillas vacías es muy alto, \
    se establecerá en el valor máximo de 50%." <<endl;
    this->porcentajeCasillasVacias = 50;
  }

  if (porcentajeCasillasVacias < 10)
  { // Limíta el porcentaje mínimo de casillas vacías
    cout<< "El porcentaje de casillas vacías es muy bajo, \
    se establecerá en el valor mínimo de 10%." <<endl;
    this->porcentajeCasillasVacias = 10;
  }
}


Laberinto::~Laberinto()
{ // Destructor
  for(int fila=0; fila<numeroFilas; fila++)
    delete tablero[fila];
  delete [] tablero;
}


void Laberinto::fabricarCamino()
{
  // Hacer el camino principal:
  casillasVacias += caminoPrincipal(filaEntrada, 0, 3);

  // Hacer caminos al azar:
/*  do
  {
    int filaInicial_Lineas;
    int columnaInicial_Lineas;
    int direccion = escogerDireccion();

    do
    { // Selecciona posiciones pertenecientes a puntos vacíos (la primera vez pertenece al camino principal)
      filaInicial_Lineas = rand() % numeroFilas;
      columnaInicial_Lineas = rand() % numeroColumnas;
    } // Esto evita la generación de caminos que no conectan de ninguna forma con el resto del laberinto
    while (tablero[filaInicial_Lineas][columnaInicial_Lineas] != 0);

    // Traza lineas cuyo punto inicial se encuentra vacío:
    casillasVacias += trazaLineaRecta(filaInicial_Lineas, columnaInicial_Lineas, direccion);
  } // Limita los espacios vacíos generados por las lineas rectas generadas
  while((((double)casillasVacias/((double)(numeroFilas*numeroColumnas)))*100) < porcentajeCasillasVacias);

  // Poner los Tesoros al azar:
  for (int tesoros=0; tesoros<numeroTesoros; tesoros++)
    ponerEnCasillaVaciaAlAzar(2);

  // Poner los Gnomos al azar:
  for(int gnomos=0; gnomos<numeroGnomos; gnomos++)
    ponerEnCasillaVaciaAlAzar(3);

  // Poner los Dragones al azar, cerca de la salida:
  for(int dragones=0; dragones<numeroDragones; dragones++)
    ponerEnCasillaVaciaAlAzar(4);*/
}


int Laberinto::caminoPrincipal(int filaInicial, int columnaInicial, int direccion)
{ // Función recursiva que crea un camino que va desde el inicio hasta el final de manera ininterrumpida
  int contarVacias = 0;
  int avanzar;

  if (columnaInicial == numeroColumnas)
  { // Condición para terminar la recursión
    filaSalida = filaInicial; // Guarda la fila de salida
    return 0; // Termina la recursión
  }

  if (direccion==2) // Arriba
  {
    avanzar = (-(numeroFilas/10)+(rand()%4)-(rand()%4)); // Selecciona un avance para la matriz,
    if (filaInicial+avanzar < 0)                         // el avance no es siempre el mismo
    { // Evita que el avance se salga de la matriz
      avanzar = (-filaInicial);
    }
    for (int fila=filaInicial; fila>=filaInicial+avanzar; fila--)
    { // Vacía las casillas de la matriz correspondientes al camino trazado
      if (tablero[fila][columnaInicial]!=0)
      { //Si la casilla No estaba vacía cuenta +1 a las casillas que se vaciaron
        tablero[fila][columnaInicial]=0;
        contarVacias++;
      }
    } // Continúa la construcción del camino llamandose a si misma otra vez pero con diferentes argumentos
    contarVacias += caminoPrincipal(filaInicial+avanzar, columnaInicial, escogerDireccion());
  }
  if (direccion==3 || direccion==1) // El camino principal nunca va hacia la izquierda, en vez de eso va a la derecha
  {                                 // Así evita bucles muy largos por devolverse aleatoriamente a la izquierda muchas veces
    avanzar = (numeroColumnas/10+(rand()%4)-(rand()%4));
    if (columnaInicial+avanzar > numeroColumnas)
      avanzar = (numeroColumnas - columnaInicial);

    for (int columna=columnaInicial; columna<=columnaInicial+avanzar; columna++)
    {
      if (tablero[filaInicial][columna]!=0)
      {
        tablero[filaInicial][columna]=0;
        contarVacias++;
      }
    }
    contarVacias += caminoPrincipal(filaInicial, columnaInicial+avanzar, escogerDireccion());
  }
  if (direccion==0) // Abajo
  {
    avanzar = (numeroFilas/10+(rand()%4)-(rand()%4));
    if (filaInicial+avanzar > numeroFilas)
      avanzar = (numeroFilas - filaInicial);
    for (int fila=filaInicial; fila<=filaInicial+avanzar; fila++)
    {
      if (tablero[fila][columnaInicial]!=0)
      {
        tablero[fila][columnaInicial]=0;
        contarVacias++;
      }
    }
    contarVacias += caminoPrincipal(filaInicial+avanzar, columnaInicial, escogerDireccion());
  }
  return contarVacias;
}


/*
int Laberinto::trazaLineaRecta(int filaInicial, int columnaInicial, int direccion)
{
  int contarVacias = 0;
Lineas Rectas
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
} */


void Laberinto::imprimir()
{
  for(int columna=0; columna<numeroColumnas+2; columna++)
    cout << "X";
  cout << endl;
  for(int fila=0; fila<numeroFilas; fila++)
  {
    cout << "X";
    for(int columna=0; columna<numeroColumnas; columna++)
    {
      if(tablero[fila][columna] == 0)
        cout << " ";
      else
      {
        if(tablero[fila][columna] == 1)
          cout << "X";
        else
          cout << tablero[fila][columna];
      }

    }
    cout << "X" << endl;
  }
  for(int columna=0; columna<numeroColumnas+2; columna++)
    cout << "X";
  cout << endl;
}


void Laberinto::buscarCasillaAlAzar(int &fila, int &columna, int contenido)
{
  if (contenido==4) // Se encarga del caso especial (dragones)
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


int Laberinto::escogerDireccion()
{ // 1 = Izquierda, 2 = Arriba, 3 = Derecha, 0 = Abajo
  int nuevaDireccion = rand() % 4;
  return nuevaDireccion;
}
