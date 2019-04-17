// ##########################

/* 
Una Figura mide lado por lado, y tiene un area, que depende del tipo de figura.

El Cuadrado es una Figura.
El Circulo es una Figura.

La relación "es un" no añade funciones nuevas, pero puede reimplementar de otra forma las funciones ya existentes en la clase base.
*/


class Figura
{
    private:
        double lado;
    public:
        virtual double area()=0;
};

class Cuadrado : public Figura
{
  public:
    virtual double area() { return lado*lado; }
};

class Circulo : public Figura
{
  public:
    virtual double area() { return 3.14*(lado/2)*(lado/2); }
};

int main()
{
  Figura u;  // Error porque Figura es una clase abstracta, porque le falta la implementacion de la funcion area()
  
  Cuadrado w;
  w.area();
  
  Circulo z;
  z.area();
}

// ##########################
/*
Una Persona tiene un nombre.

Un Chofer es parecido a una Persona porque además, sabe manejar.

La relación "es parecido a un" incorpora las mismas funciones que la clase base y añade otras nuevas.

*/

class Persona
{
    private:
        string nombre;
    public:
        string comoTeLlamas() { return nombre; }
};

class Chofer : public Persona
{
    public:
        void manejar() { /* etc... */ }
};

int main()
{
  Persona u;
  u.comoTeLlamas();
  
  Chofer w;
  w.comoTeLlamas();
  w.manejar();
}

// ##########################
/*
Una Bicicleta contiene dos Ruedas.

Un objeto U contiene a otro Z si solo U puede dar órdenes a Z. Y ello se consigue típicamente poniéndo Z en la parte privad de U.
*/

class Rueda
{
};

class Bicicleta
{
     private:
         Rueda ruedas[2];
};

// ##########################
/*
Una Bicicleta conoce un Semaforo (para pasar cuando este verde).

Un objeto U conoce a otro Z si U puede dar ordenes a Z pero hay mas objetos que también pueden dar órdenes a Z. Y ello se consigue poniendo en la parte privada de U un puntero hacia Z.

Se emplea esta relación cuando vamos a compartir el uso de Z desde varios otros objetos.

Con esta relacion (U conoce Z) cada objeto es independiente, excepto si decidimos que U sea propietario de Z, en cuyo caso el destructor de U debe destruir a Z.
Pero cada objeto solo puede tener un propietario. Ello hay que ponerlo en comentarios.
*/

class Semaforo
{
    public:
      string color();
};

class Bicicleta
{
     private:
         Semaforo *semaforo; // Bicicleta ni es propietaria de Semaforo
         
     public:
         void pedalear() { if(semaforo->color() == "verde") avanzar(); }
};

// ##########################
/*
Varias Personas conocen un libro, pero solo uno de ellos es el propietario.

Tipicamente se requiere un booleano que indique quien es el propietario.
*/

class Libro
{
};


class Persona
{
    private:
        bool soyPropietario;
        Libro *libro;
        
    public:
        Persona(Libro *libro, bool soyPropietario) 
        {
            this->libro = libro;
            this->soyPropietario = soyPropietario;
        }
        ~Persona()
        {
            if(soyPropietario)
            {
                delete libro;
                libro=0;
            }
        }
};

int main()
{
    Libro *rayuela = new Libro;
    Persona Diana(rayuela, false);
    Persona Luisa(rayuela, true);
    Persona Felipe(rayuela, false);
}


