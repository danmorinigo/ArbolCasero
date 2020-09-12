#include "nodo.h"
Nodo::Nodo(Dato dato){
    //std::cout << "Constructor Nodo (" << this << ")" << std::endl;
    this->dato = dato;
    izq = 0;
    der = 0;
    padre = 0;
}
void Nodo::asignarDato(Dato ingreso){
    this->dato = ingreso;
}
void Nodo::asignarIzquierda(Nodo* izquierdo){
    this->izq = izquierdo;
}
void Nodo::asignarDerecha(Nodo* derecho){
    this->der = derecho;
}
Dato Nodo::obtenerDato(){
    return dato;
}
Nodo* Nodo::obtenerIzquierda(){
    return izq;
}
Nodo* Nodo::obtenerDerecha(){
    return der;
}
Nodo* Nodo::obtenerPadre(){
    return padre;
}
bool Nodo::esHoja(){
    return(izq == 0 && der == 0);
}
bool Nodo::hijoIzq(){
    return(izq != 0);
}
bool Nodo::hijoDer(){
    return(der != 0);
}
void Nodo::asignarPadre(Nodo* padre){
    this->padre = padre;
}
Nodo::~Nodo(){
    //std::cout << "Destructor Nodo (" << this << ")" << std::endl;
}
