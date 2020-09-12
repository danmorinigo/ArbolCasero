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

    void ancho2();
    void eliminar(int);
    void eliminar(Nodo*);
    Nodo* minimo(Nodo*);
    void minimo();
    int obtenerAltura(Nodo* node);
    Nodo* mayor(Nodo* nodo);
    int obtenerAltura();
    void mayor();
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
    bool existe(Dato buscado);
    int enNivel(Dato buscado);
    int enNivel(Dato buscado, Nodo* nodo, int nivel);
    void nivelMasNodos();
    int nivelConMasNodos();
    void balanceado();
    bool balance(Nodo* nodo);
    int alturaBalance(Nodo* nodo);
    int vAbsoluto(int numero);
    bool simetrico(const ArbolA& aComparar);
};

#endif // ARBOLA_H_INCLUDED
