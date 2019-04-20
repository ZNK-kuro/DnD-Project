#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class prueba
{
  private:
    int numeroObjetos;
    int *objetos;
  
  public:
    prueba(int numero)
    {
      //objetos = new int*[1];
      this->numeroObjetos = numero;
      objetos = new int[numeroObjetos];
      for(int i=0; i<numeroObjetos; i++)
        objetos[i] = i;
      
    }
    void imprimirObjeto()
    {
      for (int i=0; i<numeroObjetos; i++)
      {
        cout<< objetos[i] <<endl;
      }
    };
  
};


int main()
{
  prueba A1(10);
  A1.imprimirObjeto();
  cout<< "ooooooooooooooFinalespero\ryavalisteverga" <<endl;
  
  
  
  cout<< "\
╔══════════════════════════╗\n\
║         DUNGEON          ║\n\
║           AND            ║\n\
║         DRAGONS          ║\n\
║                          ║\n\
║         1. Jugar         ║\n\
║    2. Hall de la fama    ║\n\
║         3. Salir         ║\n\
║                          ║\n\
╚══════════════════════════╝\n";
  return 0;
}

