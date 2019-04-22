/*
  Archivo: DispositivoTerminal.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/20
  Versión: 0.6.2
  Licencia: GPL
*/

#include "h/DispositivoTerminal.h"
#include <ctype.h>

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
    
  //printf("%c[%dm", 0x1B, 5);  // Oculta el cursor  // hace parpadear todo el terminal @.@
/*
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
*/

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
  imprimirMensaje(0, 0, "Dime tu nombre: ▒▒▒");
  streambuf *teclado = cin.rdbuf();
  string nombre="";
  
  while(true)
  {
    char caracter = teclado->sbumpc();
    if(caracter == '\n' or caracter == '\r')
      break;
    caracter = toupper(caracter);
    nombre += string(1, caracter);
    
    if(nombre.length() < ancho_nombre)
      imprimirMensaje(fila_nombre, 17, nombre);
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
        if(caracter == 0x41) // arriba
          return 1;
        else if(caracter == 0x44) // izquierda
          return 2;
        else if(caracter == 0x42) // abajo
          return 3;
        else if(caracter == 0x43) // derecha
          return 4;
        else
          return 0;
      break;
    }
  }
}


bool DispositivoTerminal::leerSiVolverAJugar()
{
  imprimirSimbolo(fila_mensaje, columna_mensaje, "¿Quieres volver a jugar? (S/N): ");
  while(true)
  {
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
 /* if(fila<0 or fila>=alto_Tablero or columna<0 or columna>=ancho_Tablero)
    return;*/
  if(valor==0)
    imprimirSimbolo(/*fila_Tablero+*/fila, /*columna_Tablero+*/columna, " ");
  else
    imprimirSimbolo(/*fila_Tablero+*/fila, /*columna_Tablero+*/columna, to_string(valor));
}

/*
void DispositivoTerminal::imprimirFichaSiguiente(int fila, int columna, int valor)
{
  if(fila<0 or fila>=alto_FichaSiguiente or columna<0 or columna>=ancho_FichaSiguiente)
    return;
  if(valor==0)
    imprimirSimbolo(fila_FichaSiguiente+fila, columna_FichaSiguiente+columna, " ");
  else
    imprimirSimbolo(fila_FichaSiguiente+fila, columna_FichaSiguiente+columna, to_string(valor));
}
*/


void DispositivoTerminal::imprimirNombre(string nombre)
{
  // ToDo: truncar al ancho
  imprimirMensaje(fila_nombre, columna_nombre, "NOMBRE: " + nombre + "     ");
}


void DispositivoTerminal::imprimirPuntos(int puntos)
{
  imprimirMensaje(fila_puntos, columna_puntos, "PUNTOS: " + to_string(puntos) + "  ");
}

void DispositivoTerminal::imprimirTesoros(int tesoros)
{
  imprimirMensaje(fila_tesoros, columna_tesoros, "TESOROS: " + to_string(tesoros));
}

void DispositivoTerminal::imprimirGanadores(string ganadores)
{
  // ToDo: truncar al ancho
  imprimirMensaje(fila_ganadores, columna_ganadores, ganadores);
}

int DispositivoTerminal::menu() // Escoger acción
{
  imprimirMensaje(0,0,"\
╔══════════════════════════╗    Bienvenido a D&D espero que esto te ayude:\n\
║         DUNGEON          ║\n\
║           AND            ║  ♥ -> Este eres tú. Muévete con las flechas.\n\
║         DRAGONS          ║  ♦ -> Estos son tesoros. Cógelos para ganar puntos.\n\
║                          ║  ♣ -> Esto es un gnomo, no te dejará pasar\n\
║         1. Jugar         ║       hasta que contestes a sus preguntas,\n\
║    2. Hall de la fama    ║       pero te dará un tesoro a cambio.\n\
║         3. Salir         ║  ♠ -> Ten cuidado con los dragones,\n\
║                          ║       te pedirán tesoros para dejarte pasar.\n\
╚══════════════════════════╝    Si te quedas sin puntos perderás. ¡Divíertete!\n");
  imprimirMensaje(fila_mensaje,columna_mensaje, " ");

  while(true) // Jugar > Escoger dificultad
  {
    streambuf *teclado = cin.rdbuf();
    char caracter = teclado->sbumpc();
    if(caracter == '1')
    {
      system("clear");
      imprimirMensaje(0,0,"\
╔══════════════════════════╗\n\
║         DUNGEON          ║\n\
║           AND            ║\n\
║         DRAGONS          ║\n\
║                          ║\n\
║        1. Fácil          ║\n\
║        2. Normal         ║\n\
║        3. Difícil        ║\n\
║                          ║\n\
╚══════════════════════════╝");
      imprimirMensaje(fila_mensaje,columna_mensaje, " ");
      while(true)
      {
        streambuf *teclado = cin.rdbuf();
        char caracter = teclado->sbumpc();
        if(caracter == '1') // Jugar > Fácil
          return 1;
        if(caracter == '2') // Jugar > Medio
          return 2;
        if(caracter == '3') // Jugar > Difícil
          return 3;
      }
    }
    if(caracter == '2') // Hall de la fama
      return 4;
    if(caracter == '3') // Salir
      return 5;
  }
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





