#ifndef NODOCOLA_H_INCLUDED
#define NODOCOLA_H_INCLUDED
#include<iostream>
#include "nodo.h"
const bool MEMORIA = false;
//typedef Nodo Dato;
class NodoCola{
private:
    Nodo* dato;
    NodoCola* siguiente;
public:
    NodoCola (Nodo* dato);
    Nodo* obtenerDato();
    void asignarSiguiente(NodoCola* alSiguiente);
    NodoCola* obtenerSiguiente();

    ~NodoCola();
};


#endif // NODOCOLA_H_INCLUDED
