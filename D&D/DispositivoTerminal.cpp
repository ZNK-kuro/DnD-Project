/*
  Archivo: DispositivoTerminal.cpp
  Autores:  Ángel García Baños
            Crhistian García Urbano
            Nicolás Jaramillo Mayor
  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co
  Fecha creación: 2018-02-28
  Fecha última modificación: 2019-03-23
  Versión: 0.1.1
  Licencia: GPL
*/

#include "DispositivoTerminal.h"


DispositivoTerminal::DispositivoTerminal(int grosorSimbolo) : DispositivoEntradaSalida()
{
  this->grosorSimbolo = grosorSimbolo;
  system("clear");
  // Programa el terminal en modo de un solo caracter:
  struct termios terminal; 
  tcgetattr(fileno(stdin), &terminal);
  terminal_salvado = terminal;
  terminal.c_lflag &= (~ICANON & ~ECHO);
  terminal.c_cc[VTIME] = 0;
  terminal.c_cc[VMIN] = 1;
  if(tcsetattr(fileno(stdin), TCSANOW, &terminal) < 0)
    perror("Imposible programar el terminal en modo de un solo caracter");
    
  printf("%c[%dm", 0x1B, 5);  // Oculta el cursor

  // Dibujar borde de tablero:
  int n=1;
  for(int columna=columna_Tablero-1; columna<=columna_Tablero+ancho_Tablero; columna++)
  {
    imprimirSimbolo(fila_Tablero-1, columna, "█");
    imprimirSimbolo(fila_Tablero+alto_Tablero, columna, "█");
  }
  n=1;
  for(int fila=fila_Tablero-1; fila<=fila_Tablero+alto_Tablero; fila++)
  {
    imprimirSimbolo(fila, columna_Tablero-1, "█");
    imprimirSimbolo(fila, columna_Tablero+ancho_Tablero, "█");
  }
}


DispositivoTerminal::~DispositivoTerminal()
{
  // Restaura el estado anterior del terminal:
  if(tcsetattr(fileno(stdin), TCSANOW, &terminal_salvado) < 0)
    perror("Imposible restaurar el estado anterior del terminal");
  imprimirSimbolo(fila_mensaje, columna_mensaje, "");
}


string DispositivoTerminal::leerNombre()
{
  imprimirSimbolo(fila_mensaje, columna_mensaje, "");
  printf("Dime tu nombre: ");
  streambuf *teclado = cin.rdbuf();
  string nombre="";
  
  while(true)
  {
    char caracter = teclado->sbumpc();
    if(caracter == '\n' or caracter == '\r')
      break;
    nombre += string(1, caracter);
    if(nombre.length() < ancho_nombre)
      imprimirMensaje(fila_nombre, columna_nombre, nombre);
    else
      break;
  }
  
  return nombre;
}


int DispositivoTerminal::leerJugada()
{
  streambuf *teclado = cin.rdbuf();
  int estado = 0;
  while(true)
  {
    char caracter = teclado->sbumpc();
    switch(estado)
    {
      case 0:
        if(caracter == 0x1b) 
          estado = 1;
      break;
      case 1:
        if(caracter == 0x5b) 
          estado = 2;
      break;
      case 2:
        if(caracter == 0x41) 
          return 1;
        if(caracter == 0x42) 
          return 2;
        if(caracter == 0x43) 
          return 3;
        if(caracter == 0x44) 
          return 4;        
      break;
    }
  }
}


bool DispositivoTerminal::leerSiVolverAJugar()
{
  while(true)
  {
    imprimirSimbolo(fila_mensaje, columna_mensaje, "¿Quieres volver a jugar? (S/N): ");
    streambuf *teclado = cin.rdbuf();
    char caracter = teclado->sbumpc();
    if(caracter == 's' or caracter == 'S')
      return true;
    if(caracter == 'n' or caracter == 'N')
      return false;
  }
}


void DispositivoTerminal::imprimirTablero(int fila, int columna, int valor)
{
  if(fila<0 or fila>=alto_Tablero or columna<0 or columna>=ancho_Tablero)
    return;
  if(valor==0)
    imprimirSimbolo(fila_Tablero+fila, columna_Tablero+columna, " ");
  else
    imprimirSimbolo(fila_Tablero+fila, columna_Tablero+columna, to_string(valor));
}


void DispositivoTerminal::imprimirFichaSiguiente(int fila, int columna, int valor)
{
  if(fila<0 or fila>=alto_FichaSiguiente or columna<0 or columna>=ancho_FichaSiguiente)
    return;
  if(valor==0)
    imprimirSimbolo(fila_FichaSiguiente+fila, columna_FichaSiguiente+columna, " ");
  else
    imprimirSimbolo(fila_FichaSiguiente+fila, columna_FichaSiguiente+columna, to_string(valor));
}


void DispositivoTerminal::imprimirNombre(string nombre)
{
  // ToDo: truncar al ancho
  imprimirMensaje(fila_nombre, columna_nombre, nombre);
}


void DispositivoTerminal::imprimirPuntos(int puntos)
{
  imprimirMensaje(fila_puntos, columna_puntos, to_string(puntos));
}


void DispositivoTerminal::imprimirGanadores(string ganadores)
{
  // ToDo: truncar al ancho
  imprimirMensaje(fila_ganadores, columna_ganadores, ganadores);
}


void DispositivoTerminal::imprimirSimbolo(int fila, int columna, string mensaje)
{
  for(int y=0; y<grosorSimbolo; y++)
    for(int x=0; x<grosorSimbolo; x++)
      printf("%c[%d;%dH%s", 0x1B, fila*grosorSimbolo+y, columna*grosorSimbolo+x, mensaje.c_str());
}


void DispositivoTerminal::imprimirMensaje(int fila, int columna, string mensaje)
{
  printf("%c[%d;%dH%s", 0x1B, fila*grosorSimbolo, columna*grosorSimbolo, mensaje.c_str());
}





