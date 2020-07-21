#ifndef ARBOLA_H_INCLUDED
#define ARBOLA_H_INCLUDED

#include "nodo.h"
#include "cola.h"

class ArbolA{
private:
    Nodo* raiz;

public:
    ArbolA();
    ~ArbolA();
    void asignarRaiz(Nodo*);
    Nodo* obtenerRaiz();

    void eliminar(int);
    void eliminar(Nodo*);
    Nodo* minimo(Nodo*);

    void ancho();
    void mostrarCola(Cola*);
    void postOrden();
    void postOrden(Nodo*);
    void inOrden();
    void inOrden(Nodo*);
    void preOrden();
    void preOrden(Nodo*);
    void mostrar(Nodo*, int);
    void mostrar();
    void buscar(Dato);
    Nodo* buscar(Nodo*, Dato);
    void insertar(Dato);
    void insertar(Nodo*, Dato);
    void eliminarArbolA(Nodo*);
};

#endif // ARBOLA_H_INCLUDED
