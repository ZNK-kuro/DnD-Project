/*
  Archivo: HallDeLaFama.cpp

  Autores:  Ángel García Baños
            Crhistian García Urbano        1832124
            Nicolas Jaramillo Mayor        1840558

  Email:  nicolas.jaramillo@correounivalle.edu.co
          garcia.crhistian@correounivalle.edu.co

  Fecha creación:       2018/02/28
  Última modificación:  2019/04/18
  Versión: 0.6
  Licencia: GPL
*/

#include "../HallDeLaFama.h"


HallDeLaFama::HallDeLaFama(string archivo)
{
  this->archivo = archivo;
  numeroDeGanadores = 0;
  
  ifstream flujo;
  flujo.open(archivo.c_str());
  if(not flujo.is_open())
    return;

  string linea;
  while(not flujo.eof())
  {
    getline(flujo, linea);
    int posicionTabulador = linea.find("\t");
    if(posicionTabulador != string::npos)
    {
      ganadores[numeroDeGanadores] = linea.substr(0, posicionTabulador);
      puntos[numeroDeGanadores] = stoi(linea.substr(posicionTabulador+1));
      numeroDeGanadores++;
      if(numeroDeGanadores>=10)
        break;
    }
  }
  ordenar();
  flujo.close();
}


HallDeLaFama::~HallDeLaFama()
{
  ofstream flujo;
  flujo.open(archivo.c_str());
  if(not flujo.is_open())
    cerr << "ERROR al tratar de abrir (para escribir) el archivo " << archivo << endl;
  else
  {
    flujo << listaDeGanadores();
    flujo.close();
  }
}


void HallDeLaFama::nuevoGanador(string nombre, int puntaje)
{
  // Buscarlo y si existe, actualizarlo
  bool existe = false;
  for(int cual=0; cual<numeroDeGanadores; cual++)
    if(ganadores[cual] == nombre)
    {
      existe = true;
      if(puntos[cual] < puntaje)
        puntos[cual] = puntaje;
    }
      
  if(not existe)
  {
    if(numeroDeGanadores == 10)
    {
      if(puntos[9] < puntaje)
      {
        puntos[9] = puntaje;
        ganadores[9] = nombre;
      }
    }
    else
    {
      puntos[numeroDeGanadores] = puntaje;
      ganadores[numeroDeGanadores] = nombre;
      numeroDeGanadores++;
    }
    ordenar();
  }
}


void HallDeLaFama::ordenar()
{
  for(int primero=0; primero<numeroDeGanadores-1; primero++)
    for(int despues=primero+1; despues<numeroDeGanadores; despues++)
      if(puntos[primero] < puntos[despues])
      {
        int aux = puntos[primero];
        puntos[primero] = puntos[despues];
        puntos[despues] = aux;

        string nombreAux = ganadores[primero];
        ganadores[primero] = ganadores[despues];
        ganadores[despues] = nombreAux;
      }
}


string HallDeLaFama::listaDeGanadores()
{
  string resultado = "";

  for(int cual=0; cual<numeroDeGanadores; cual++)
    resultado += ganadores[cual] + "\t" + to_string(puntos[cual]) + "\n";

  return resultado;
}




