#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include<iostream>
typedef int Dato;
class Nodo{
private:
    Dato dato;
    Nodo* izq;
    Nodo* der;
    Nodo* padre;
public:
    Nodo(Dato dato);
    void asignarDato(Dato ingreso);
    void asignarIzquierda(Nodo*);
    void asignarDerecha(Nodo*);
    void asignarPadre(Nodo*);

    Dato obtenerDato();
    Nodo* obtenerIzquierda();
    Nodo* obtenerDerecha();
    Nodo* obtenerPadre();

    bool esHoja();
    bool hijoIzq();
    bool hijoDer();
    ~Nodo();
};


#endif // NODO_H_INCLUDED
