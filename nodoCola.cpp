#include "nodoCola.h"
NodoCola::NodoCola (Nodo* dato){
    if(MEMORIA) std::cout << "Constructor NODOCOLA (" << this << ")\n";
    this->dato = dato;
    siguiente = 0;
}
Nodo* NodoCola::obtenerDato(){
    return this->dato;
}
void NodoCola::asignarSiguiente(NodoCola* alSiguiente){
    this->siguiente = alSiguiente;
}
NodoCola* NodoCola::obtenerSiguiente(){
    return this->siguiente;
}

NodoCola::~NodoCola(){
    if(MEMORIA) std::cout << "Destructor NODOCOLA (" << this << ")\n";
}
