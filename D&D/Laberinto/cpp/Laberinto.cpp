/*
  Archivo: Laberinto.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558
            Michelle Gonzalez H.     (del taller 3)

  Email: angel.garcia@correounivalle.edu.co
         nicolas.jaramillo@correounivalle.edu.co
         garcia.crhistian@correounivalle.edu.co
         michelle.hernandez@correounivalle.edu.co

  Fecha creación:       2018/09/17
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL
*/

#include "../Laberinto.h"
#include "../Jugador.h"
#include "../Tesoro.h"
#include "../Gnomo.h"
#include "../Dragon.h"

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
  filaEntrada = 1 + (rand()% (numeroFilas-2));

  tablero = new int*[numeroFilas];
  for(int fila=0; fila<numeroFilas; fila++)
  { // Llena todo el laberinto con paredes
    tablero[fila] = new int[numeroColumnas];
    for(int columna=0; columna<numeroColumnas; columna++)
      tablero[fila][columna] = 1;
  }

  numObjetos = numeroTesoros + numeroGnomos + numeroDragones;
  objetos = new Objeto[numObjetos];
  


  if (porcentajeCasillasVacias > 35)
  { // Limíta el porcentaje máximo de casillas vacías
    cout<< "\
El porcentaje de casillas vacías es muy alto, \
se establecerá en el valor máximo de 35%." <<endl;
    this->porcentajeCasillasVacias = 35;
  }

  if (porcentajeCasillasVacias < 15)
  { // Limíta el porcentaje mínimo de casillas vacías
    cout<< "\
El porcentaje de casillas vacías es muy bajo, \
se establecerá en el valor mínimo de 15%." <<endl;
    this->porcentajeCasillasVacias = 15;
  }
}


Laberinto::~Laberinto()
{ // Destructor
  jugador.cogerTesoro();
  for(int fila=0; fila<numeroFilas; fila++)
    delete tablero[fila];
  delete [] tablero;
  delete [] objetos;
}


void Laberinto::fabricarCamino()
{
  // Hacer el camino principal:
  casillasVacias += caminoPrincipal(filaEntrada, 0, 3);

  // Ubica la Entrada y la Salida
  tablero[filaEntrada][0] = 5;
  tablero[filaSalida][numeroColumnas-1] = 6;
  cout<<endl; // debug purpose
  cout<< "Camino principal terminado" <<endl; // debug purpose
  imprimir(); // debug purpose
  // Hacer caminos al azar:
  do
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
  while((((double)casillasVacias/((double)(numeroFilas*numeroColumnas)))*100)
                                                  < porcentajeCasillasVacias);

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


int Laberinto::caminoPrincipal(int filaInicial, int columnaInicial, int direccion)
{ // Función recursiva que crea un camino que va desde el inicio hasta el final de manera ininterrumpida
//  cout<< "caminoPrincipal inicia" <<endl; // debug purpose
  int contarVacias = 0;
  int avanzar;

  if (columnaInicial == numeroColumnas)
  { // Condición para terminar la recursión
    filaSalida = filaInicial; // Guarda la fila de salida
//    cout<< "caminoPrincipal termina" <<endl; // debug purpose
    return 0; // Termina la recursión
  }


/*  if (direccion==1) // Izquierda
  {
    cout<< "izquierda" <<endl; // debug purpose
    avanzar = (-(numeroColumnas/15)+(rand()%4)-(rand()%4));
    if (columnaInicial+avanzar <= 0)
      avanzar = (-columnaInicial+1);

    for (int columna=columnaInicial; columna>columnaInicial+avanzar; columna--)
    {
      if (tablero[filaInicial][columna]!=0)
      {
        tablero[filaInicial][columna]=0;
        contarVacias++;
      }
    }
    contarVacias += caminoPrincipal(filaInicial, columnaInicial+avanzar, escogerDireccion());
    return contarVacias;
  } */

  if (direccion==3 || direccion==1) // Derecha (la matriz avanza hacia la derecha en vez de
  {                                 //  a la izquierda mientras hace el camino principal)
//    cout<< "derecha" <<endl; // debug purpose
    avanzar = (numeroColumnas/30+(rand()%(numeroColumnas/40))-(rand()%(numeroColumnas/30)));
    if (columnaInicial+avanzar >= numeroColumnas-1)
      avanzar = (numeroColumnas - columnaInicial);

    for (int columna=columnaInicial; columna<columnaInicial+avanzar; columna++)
    {
      if (tablero[filaInicial][columna]!=0)
      {
        tablero[filaInicial][columna]=0;
        contarVacias++;
      }
    }
    contarVacias += caminoPrincipal(filaInicial, columnaInicial+avanzar, escogerDireccion());
    return contarVacias;
  }

  else if (direccion==2) // Arriba
  {
//    cout<< "arriba" <<endl; // debug purpose
    avanzar = (-(numeroFilas/10)-(rand()%(numeroFilas/10))); // Selecciona un avance para la matriz,
    if (filaInicial+avanzar <= 0)                         // el avance no es siempre el mismo
    { // Evita que el avance se salga de la matriz
      avanzar = (-filaInicial+1);
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
    return contarVacias;
  }

  else if (direccion==0) // Abajo
  {
//    cout<< "abajo" <<endl; // debug purpose
    avanzar = (numeroFilas/10+(rand()%(numeroFilas/10)));
    if (filaInicial+avanzar >= numeroFilas-1)
      avanzar = (numeroFilas - filaInicial -2);

    for (int fila=filaInicial; fila<=filaInicial+avanzar; fila++)
    {
      if (tablero[fila][columnaInicial]!=0)
      {
        tablero[fila][columnaInicial]=0;
        contarVacias++;
      }
    }
    contarVacias += caminoPrincipal(filaInicial+avanzar, columnaInicial, escogerDireccion());
    return contarVacias;
  }
  return contarVacias;
}


int Laberinto::trazaLineaRecta(int filaInicial, int columnaInicial, int direccion)
{
  intentosLineas++;
  int contarVacias = 0;
  int avanzar;
  bool bordeInicial = 1; // Si la fila o columna inicial son == 0 este valor vale 0
  bool bordeFinal = 1; // Si la fila o columna inicial son la última posicion de fila o columna este valor vale 0
  bool espacioVacio =1; //se usa para comprobar si la fila se va a generar en un espacio vacío o en uno lleno
//  cout<< "trazaLineaRecta inicia" <<endl; // debug purpose

  if (direccion==1 && columnaInicial>0) // Izquierda
  {
//    cout<< "Izquierda" <<endl; // debug purpose
    avanzar = (-(numeroColumnas/15)+(rand()%(numeroColumnas/15))-(rand()%(numeroColumnas/20)));
    if (columnaInicial+avanzar <= 0)
      avanzar = (-columnaInicial);

    if (filaInicial == 0)
      bordeInicial = 0;
    if (filaInicial == numeroFilas-1)
      bordeFinal = 0;

    for (int i=-1; i>=avanzar-1; i--)
    {
      //cout<< " |i: " << i <<" menor igual a: " <<avanzar; //debug purpose
      if (tablero[filaInicial-bordeInicial][columnaInicial+i] != 1 ||
          tablero[filaInicial]             [columnaInicial+i] != 1 ||
          tablero[filaInicial+bordeFinal]  [columnaInicial+i] != 1)
        espacioVacio = 0;
    }
    if (espacioVacio == 1 and // Si el espacio en el que se va a poner el pasillo está vacío y
        ( // (Es una esquina o el final de un pasillo horizontal o 
          //está en medio de un pasillo vertical pero No crearía una intersección de 4 esquinas, entonces se crea el pasillo nuevo.)
          (tablero[filaInicial-bordeInicial][columnaInicial] != tablero[filaInicial+bordeFinal][columnaInicial]) or
          (tablero[filaInicial-bordeInicial][columnaInicial] == 1 and tablero[filaInicial+bordeFinal][columnaInicial] == 1) or
          (tablero[filaInicial][columnaInicial+1] == 1 and intentosLineas > 100000)
        )
       )
      {
        for (int columna=columnaInicial; columna>columnaInicial+avanzar; columna--)
        {
          if (tablero[filaInicial][columna]!=0)
          {
            tablero[filaInicial][columna]=0;
            contarVacias++;
          }
        }
      }

//    cout<< "trazaLineaRecta termina" <<endl; // debug purpose
    return contarVacias;
  }

  else if (direccion==3 && columnaInicial<numeroColumnas-1) // Derecha
  {
//    cout<< "Derecha" <<endl; // debug purpose
    avanzar = (numeroColumnas/15+(rand()%(numeroColumnas/20))-(rand()%(numeroColumnas/15)));
    if (columnaInicial+avanzar >= numeroColumnas)
      avanzar = (numeroColumnas - columnaInicial-2);

    if (filaInicial == 0)
      bordeInicial = 0;
    if (filaInicial == numeroFilas-1)
      bordeFinal = 0;

    for (int i=1; i<=avanzar+1; i++)
    {
      if (tablero[filaInicial-bordeInicial][columnaInicial+i] != 1 ||
          tablero[filaInicial]             [columnaInicial+i] != 1 ||
          tablero[filaInicial+bordeFinal]  [columnaInicial+i] != 1)
        espacioVacio = 0;
    }

    if (espacioVacio == 1 and
        (
          (tablero[filaInicial-bordeInicial][columnaInicial] != tablero[filaInicial+bordeFinal][columnaInicial]) or
          (tablero[filaInicial-bordeInicial][columnaInicial] == 1 and tablero[filaInicial+bordeFinal][columnaInicial] == 1) or
          (tablero[filaInicial][columnaInicial-1] == 1 and intentosLineas > 100000)
        )
       )
    {
      for (int columna=columnaInicial; columna<columnaInicial+avanzar; columna++)
      {
        if (tablero[filaInicial][columna]!=0)
        {
          tablero[filaInicial][columna]=0;
          contarVacias++;
        }
      }
    }

//    cout<< "trazaLineaRecta termina" <<endl; // debug purpose
    return contarVacias;
  }

  else if (direccion==2 && filaInicial>0 &&
      columnaInicial > 1 && columnaInicial < numeroColumnas-2) // Arriba
  {
//    cout<< "Arriba" <<endl; // debug purpose
    avanzar = (-(numeroFilas/10)-(rand()%(numeroFilas/10)));
    if (filaInicial+avanzar < 1)
      avanzar = (-filaInicial+1);

    if (columnaInicial == 0)
      bordeInicial = 0;
    if (columnaInicial == numeroColumnas-1)
      bordeFinal = 0;

    for (int i=-1; i>=avanzar-1; i--)
    {
      if (tablero[filaInicial+i][columnaInicial-bordeInicial] != 1 ||
          tablero[filaInicial+i][columnaInicial]              != 1 ||
          tablero[filaInicial+i][columnaInicial+bordeFinal]   != 1)
        espacioVacio = 0;
    }
    if (espacioVacio == 1 and
        (
          (tablero[filaInicial][columnaInicial-bordeInicial] != tablero[filaInicial][columnaInicial+bordeFinal]) or
          (tablero[filaInicial][columnaInicial-bordeInicial] == 1 and tablero[filaInicial][columnaInicial+bordeFinal] == 1) or
          (tablero[filaInicial+1][columnaInicial] == 1 and intentosLineas > 100000)
        )
       )
    {
      for (int fila=filaInicial; fila>=filaInicial+avanzar; fila--)
        {
          if (tablero[fila][columnaInicial]!=0)
          {
            tablero[fila][columnaInicial]=0;
            contarVacias++;
          }
        }
    }
//    cout<< "trazaLineaRecta termina" <<endl; // debug purpose
    return contarVacias;
  }

  else if (direccion==0 && filaInicial<numeroFilas &&
      columnaInicial > 1 && columnaInicial < numeroColumnas-2) // Abajo
  {
//    cout<< "Abajo" <<endl; // debug purpose
    avanzar = (numeroFilas/10+(rand()%(numeroFilas/10)));
    if (filaInicial+avanzar >= numeroFilas-1)
      avanzar = (numeroFilas - filaInicial -2);


    if (columnaInicial == 0)
      bordeInicial = 0;
    if (columnaInicial == numeroColumnas-1)
      bordeFinal = 0;

    for (int i=1; i<=avanzar+1; i++)
    {
      if (tablero[filaInicial+i][columnaInicial-bordeInicial] != 1 ||
          tablero[filaInicial+i][columnaInicial]              != 1 ||
          tablero[filaInicial+i][columnaInicial+bordeFinal]   != 1)
        espacioVacio = 0;
    }

    if (espacioVacio == 1 and
        (
          (tablero[filaInicial][columnaInicial-bordeInicial] != tablero[filaInicial][columnaInicial+bordeFinal]) or
          (tablero[filaInicial][columnaInicial-bordeInicial] == 1 and tablero[filaInicial][columnaInicial+bordeFinal] == 1) or
          (tablero[filaInicial-1][columnaInicial == 1] and intentosLineas > 100000)
        )
       )
    {
      for (int fila=filaInicial; fila<=filaInicial+avanzar; fila++)
      {
        if (tablero[fila][columnaInicial]!=0)
        {
          tablero[fila][columnaInicial]=0;
          contarVacias++;
        }
      }
    }
//    cout<< "trazaLineaRecta termina" <<endl; // debug purpose
    return contarVacias;
  }

  return contarVacias;
}


void Laberinto::imprimir()
{
  for(int fila=0; fila<numeroFilas; fila++)
  {
    for(int columna=0; columna<numeroColumnas; columna++)
    {
      if (fila == 0 and columna == 0)
        cout << "╔";
      else if (fila == 0 and columna == numeroColumnas-1)
        cout << "╗";
      else if (fila == numeroFilas-1 and columna == 0)
        cout << "╚";
      else if (fila == numeroFilas-1 and columna == numeroColumnas-1)
        cout << "╝";
      else if (fila == 0 and tablero[fila+1][columna] ==1)
        cout << "╦";
      else if (fila == numeroFilas-1 and tablero[fila-1][columna] ==1)
        cout << "╩";
      else if (fila == 0 or fila == numeroFilas-1)
        cout << "═";
      else if (columna == 0 and tablero[fila][columna] == 1 and tablero[fila][columna+1] == 1)
        cout << "╠";
      else if (columna == numeroColumnas-1 and tablero[fila][columna] == 1 and tablero[fila][columna-1] == 1)
        cout << "╣";
      else if ((columna == 0 or columna == numeroColumnas-1) and tablero[fila][columna] == 1)
        cout << "║";
      else if (tablero[fila][columna] == 0)
        cout << " ";
      else if (tablero[fila][columna] == 1) // tiene bloque: 1 = arriba, 2 = abajo, 3 = izquierda, 4 = derecha. 0 no tiene bloque
      {
        if (tablero[fila-1][columna] == 1) // 1?
        {
          if (tablero[fila+1][columna] == 1) // 1,2?
          {
            if (tablero[fila][columna-1] == 1) // 1,2,3?
            {
              if (tablero[fila][columna+1] == 1) // 1,2,3,4?
                cout<< "╬"; // 1,2,3,4
              else
                cout<< "╣"; // 1,2,3,0
            }
            else if (tablero[fila][columna+1] == 1) // 1,2,0,4?
              cout<< "╠"; // 1,2,0,4
            else
              cout<< "║"; // 1,2,0,0
          }
          else if (tablero[fila][columna-1] == 1) // 1,0,3?
          {
            if (tablero[fila][columna+1] == 1) // 1,0,3,4?
              cout<< "╩"; // 1,0,3,4
            else
              cout<< "╝"; // 1,0,3,0
          }
          else if (tablero[fila][columna+1] == 1) // 1,0,0,4?
            cout<< "╚"; // 1,0,0,4
          else
            cout<< "║"; // 1,0,0,0
        }
        else if (tablero[fila+1][columna] == 1) // 0,2?
        {
          if (tablero[fila][columna-1] == 1) // 0,2,3?
          {
            if (tablero[fila][columna+1] == 1) // 0,2,3,4?
              cout<< "╦"; // 0,2,3,4
            else
              cout<< "╗"; // 0,2,3,0
          }
          else if (tablero[fila][columna+1] == 1) // 0,2,0,4?
            cout<< "╔"; // 0,2,0,4
          else
            cout<< "║"; // 0,2,0,0
        }
        else
          cout<< "═"; // 0,0,x,x esta es especial, siempre que 1 y 2 sean 0, el resultado será las dos barras laterales.
      }
      else if (tablero[fila][columna] == 2)
        cout << "T";
      else if (tablero[fila][columna] == 3)
        cout << "G";
      else if (tablero[fila][columna] == 4)
        cout << "D";
      else if (tablero[fila][columna] == 5 or tablero[fila][columna] == 6)
        cout << " ";
      else
        cout << tablero[fila][columna];
    }
    cout << endl;
  }
  cout<< endl;
}


void Laberinto::buscarCasillaAlAzar(int &fila, int &columna, int contenido)
{
  if (contenido==4) // Se encarga del caso especial (dragones)
  {
    do
    {
      fila = rand() % numeroFilas;
      columna = (numeroColumnas * 3/4) + (rand() % (numeroColumnas/4));
    } // Restringe los valores de columna, esto sitúa al dragon cerca de la salida.
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
  if (contenido == 2)
  {
    objetos[objetosColocados] = Tesoro(fila, columna);
  }
  else if (contenido == 3)
  {
    objetos[objetosColocados] = Gnomo(fila, columna);
  }
  else if (contenido == 4)
  {
    objetos[objetosColocados] = Dragon(fila, columna);
  }
  objetosColocados++;
}


int Laberinto::escogerDireccion()
{ // 1 = Izquierda, 2 = Arriba, 3 = Derecha, 0 = Abajo
  int nuevaDireccion = rand() % 4;
  return nuevaDireccion;
}
