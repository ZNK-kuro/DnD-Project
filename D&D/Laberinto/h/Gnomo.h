/*
  Archivo: Gnomo.h

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL


  Clase: Gnomo
  
  Responsabilidad:
  Se encarga de hacer preguntas al azar al jugador si este entra a una casilla adyacente
  
  Colaboración: Es un Objeto.
*/

#ifndef Gnomo_HH
#define Gnomo_HH

#include <string>
#include "Objeto.h"
#include "Jugador.h"
#include "../../Interfaz/h/DispositivoTerminal.h"
using namespace std;

class Gnomo : public Objeto
{
  private:
    int respuesta;
   
  public:
    Gnomo(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje);
    ~Gnomo();
    void condicionDePaso(); // Te hace una pregunta y no te deja irte hasta que respondas correctamente.
    bool encontrar();       // Función vacía / No se puede Pasar sobre un gnomo.
};

#endif
