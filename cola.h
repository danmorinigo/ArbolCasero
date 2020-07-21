#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodoCola.h"

typedef int Dato;
class Cola{
private:
    NodoCola* primero;
    NodoCola* ultimo;
    int tamanio;
public:
    Cola();
    Cola(const Cola& copiado);
    void insertar(Nodo* aIngresar);
    Nodo* consultar();
    Nodo* eliminar();
    bool vacia();
    int obtenerTamanio();
    ~Cola();
private:
    NodoCola* anterior(int posicion);
};


#endif // COLA_H_INCLUDED
