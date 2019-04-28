/*
  Archivo: Dragon.h

  Autores:
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/04/04
  Última modificación:  2019/04/22
  Versión: 0.7
  Licencia: GPL


  Clase: Dragon
  
  Responsabilidad: 
  Mantiene la variable peaje que indica la cantidad de tesoros que tiene que dar el jugador para pasar.
  Permite el paso al jugador o se lo come si intenta pasar.
  
  Colaboración: Es un Objeto.
*/

#ifndef Dragon_HH
#define Dragon_HH

#include <string>
#include "Objeto.h"
#include "Jugador.h"
#include "../../Interfaz/h/DispositivoTerminal.h"
using namespace std;

class Dragon : public Objeto
{
  private:
    int peaje;
    bool pagar = true;
  
  public:
    Dragon(Jugador *jugador, DispositivoTerminal *dispositivo, int filaMensaje, int columnaMensaje);
    ~Dragon();

    void condicionDePaso(); // Escribe en pantalla la cantidad de tesoros necesarios para pasar.
    bool encontrar(); // Resta los tesoros al jugador y lo deja pasar o se lo come si no tiene suficientes.
  
};

#endif
