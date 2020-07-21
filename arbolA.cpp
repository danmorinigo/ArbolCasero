using namespace std;

#include "arbolA.h"
ArbolA::ArbolA(){
    raiz = 0;
}
ArbolA::~ArbolA(){
    if(raiz){
        eliminarArbolA(raiz);
    }
    std::cout << "Destructor Arbol ok!" << std::endl;
}
void ArbolA::asignarRaiz(Nodo* ptrRaiz){
    this->raiz = ptrRaiz;
}
Nodo* ArbolA::obtenerRaiz(){
    return this->raiz;
}

void ArbolA::mostrar(Nodo* arbol, int cont){
    if (!arbol){
        return;
    }else{
        mostrar(arbol->obtenerDerecha(), cont + 1);
        for(int i = 0; i < cont; i++){
            cout << "   ";
        }
        cout << arbol->obtenerDato() << endl;
        mostrar(arbol->obtenerIzquierda(), cont + 1);
    }
}
void ArbolA::mostrar(){
    mostrar(this->raiz, 0);
}
void ArbolA::insertar(Nodo* ptrRaiz, Dato aInsertar){
    if(!raiz){
        Nodo* auxAinsertar = new Nodo(aInsertar);
        this->raiz = auxAinsertar;
        //cout << "RAIZ!" << endl;
    }else{
        int datoEnNodo = ptrRaiz->obtenerDato();
        //cout << "|| " << aInsertar << " vs " << datoEnNodo << " ||" << endl;
        if(aInsertar < datoEnNodo){
            cout << "<---" << endl;
            if(ptrRaiz->hijoIzq()){
                cout << "<-" << endl;
                insertar(ptrRaiz->obtenerIzquierda(), aInsertar);
            }else{
                //cout << "no hijo, INSERTO!" << endl;
                Nodo* auxAinsertar = new Nodo(aInsertar);
                auxAinsertar->asignarPadre(ptrRaiz);
                ptrRaiz->asignarIzquierda(auxAinsertar);
            }
        }else if(aInsertar > datoEnNodo){
            cout << "--->" << endl;
            if(ptrRaiz->hijoDer()){
                cout << "->" << endl;
                insertar(ptrRaiz->obtenerDerecha(), aInsertar);
            }else{
                //cout << "no hijo, INSERTO!" << endl;
                Nodo* auxAinsertar = new Nodo(aInsertar);
                auxAinsertar->asignarPadre(ptrRaiz);
                ptrRaiz->asignarDerecha(auxAinsertar);
            }
        }else{
            cout << "Valor repetido\n" ;
        }
    }
}
void ArbolA::insertar(Dato aInsertar){
    insertar(this->raiz, aInsertar);
}
void ArbolA::buscar(Dato buscado){
    Nodo* aux;
    aux = buscar(this->raiz, buscado);
    if(aux){
        cout << "\nValor " << aux->obtenerDato() << " esta en el arbol.\n";
    }else{
        cout << "\nNo se encontro\n";
    }
}
Nodo* ArbolA::buscar(Nodo* ptrRaiz, Dato buscado){
    if(!ptrRaiz){
        return 0;
    }else if(ptrRaiz->obtenerDato() == buscado){
        return ptrRaiz;
    }else if(buscado < ptrRaiz->obtenerDato()){
        return buscar(ptrRaiz->obtenerIzquierda(), buscado);
    }else{
        return buscar(ptrRaiz->obtenerDerecha(), buscado);
    }
}

void ArbolA::preOrden(){
    preOrden(this->raiz);
}
void ArbolA::preOrden(Nodo* ptrRaiz){
    if(!ptrRaiz){
        return;
    }else{
        cout << ptrRaiz->obtenerDato() << " - ";
        preOrden(ptrRaiz->obtenerIzquierda());
        preOrden(ptrRaiz->obtenerDerecha());
    }
}

void ArbolA::inOrden(){
    inOrden(this->raiz);
}
void ArbolA::inOrden(Nodo* ptrRaiz){
    if(!ptrRaiz){
        return;
    }else{
        inOrden(ptrRaiz->obtenerIzquierda());
        cout << ptrRaiz->obtenerDato() << " - ";
        inOrden(ptrRaiz->obtenerDerecha());
    }
}

void ArbolA::postOrden(){
    postOrden(this->raiz);
}
void ArbolA::postOrden(Nodo* ptrRaiz){
    if(!ptrRaiz){
        return;
    }else{
        postOrden(ptrRaiz->obtenerIzquierda());
        postOrden(ptrRaiz->obtenerDerecha());
        cout << ptrRaiz->obtenerDato() << " - ";
    }
}

void ArbolA::eliminar(int aEliminar){
    Nodo* aux;
    aux = buscar(this->raiz, aEliminar);
    if(aux){
        eliminar(aux);
    }else{
        cout << "\nNo se encontro dato\n";
        return;
    }
}

void ArbolA::ancho(){
    if(!raiz){
        cout << "\nArbol vacio\n";
        return;
    }
    Cola conForma, paraMostrar;
    conForma.insertar(raiz);
    Nodo* visitado;
    int largoLista, nivel = 0;
    while(!conForma.vacia()){
        largoLista = conForma.obtenerTamanio();
        for(int i = 0; i < largoLista; i++){
            Nodo* aLista = conForma.eliminar();
            paraMostrar.insertar(aLista);
        }
        Cola aux(paraMostrar);
        cout << "Nivel " << nivel++ << ": ";
        mostrarCola(&aux);
        largoLista = paraMostrar.obtenerTamanio();
        for(int f = 0; f < largoLista; f++){
            visitado = paraMostrar.eliminar();
            if(visitado->hijoIzq()){
                conForma.insertar(visitado->obtenerIzquierda());
            }
            if(visitado->hijoDer()){
                conForma.insertar(visitado->obtenerDerecha());
            }
        }
    }
}
void ArbolA::mostrarCola(Cola* mostrando){
    int tamanio = mostrando->obtenerTamanio();
    for (int i = 0; i < tamanio; i++){
        cout << mostrando->eliminar()->obtenerDato();
        if(i < tamanio - 1) cout << " * ";
    }
    cout << endl;
}

void ArbolA::eliminar(Nodo* ptrRaiz){
    if(ptrRaiz->hijoIzq() && ptrRaiz->hijoDer()){//tiene dos hijos
        Nodo* aux;
        aux = minimo(ptrRaiz->obtenerDerecha());
        ptrRaiz->obtenerIzquierda()->asignarPadre(aux);
        if(aux->obtenerPadre() != ptrRaiz){
            aux->obtenerPadre()->asignarIzquierda(aux->obtenerDerecha());
            aux->asignarDerecha(ptrRaiz->obtenerDerecha());
            ptrRaiz->obtenerDerecha()->asignarPadre(aux);
        }
        aux->asignarIzquierda(ptrRaiz->obtenerIzquierda());
        aux->asignarPadre(ptrRaiz->obtenerPadre());
        if(ptrRaiz->obtenerPadre()){
            if(ptrRaiz->obtenerPadre()->obtenerIzquierda()->obtenerDato() == ptrRaiz->obtenerDato()){
                ptrRaiz->obtenerPadre()->asignarIzquierda(aux);
            }else{
                ptrRaiz->obtenerPadre()->asignarDerecha(aux);
            }
        }else{
            this->raiz = aux;
        }
        delete ptrRaiz;
    }else if(ptrRaiz->hijoIzq() || ptrRaiz->hijoDer()){
        Nodo* aux;
        if(ptrRaiz->hijoIzq()){
            aux = ptrRaiz->obtenerIzquierda();
        }else{
            aux = ptrRaiz->obtenerDerecha();
        }
        aux->asignarPadre(ptrRaiz->obtenerPadre());
        if(ptrRaiz->obtenerPadre()){
            if(ptrRaiz->obtenerPadre()->hijoIzq()){
                if(ptrRaiz->obtenerPadre()->obtenerIzquierda()->obtenerDato() == ptrRaiz->obtenerDato()){
                    ptrRaiz->obtenerPadre()->asignarIzquierda(aux);
                    delete ptrRaiz;
                    return;
                }
            }
            ptrRaiz->obtenerPadre()->asignarDerecha(aux);
        }else{
            this->raiz = aux;
        }
        delete ptrRaiz;
    }else{
        if(ptrRaiz->obtenerPadre()){
            if(ptrRaiz->obtenerPadre()->obtenerIzquierda() == ptrRaiz){
                ptrRaiz->obtenerPadre()->asignarIzquierda(0);
            }else{
                ptrRaiz->obtenerPadre()->asignarDerecha(0);
            }
        }else{
            this->raiz = 0;
        }
        delete ptrRaiz;
    }
}

Nodo* ArbolA::minimo(Nodo* ptrRaiz){
    if(!ptrRaiz){
        return 0;
    }
    if(ptrRaiz->hijoIzq()){
        return minimo(ptrRaiz->obtenerIzquierda());
    }else{
        return ptrRaiz;
    }
}

void ArbolA::eliminarArbolA(Nodo* ptrRaiz){
    if(ptrRaiz->esHoja()){
        cout << "Eliminando: " << ptrRaiz->obtenerDato() << endl;
        delete ptrRaiz;
        return;
    }
    if(ptrRaiz->hijoDer()){
        eliminarArbolA(ptrRaiz->obtenerDerecha());
    }
    if(ptrRaiz->hijoIzq()){
        eliminarArbolA(ptrRaiz->obtenerIzquierda());
    }
    cout << "Eliminando Raiz: " << ptrRaiz->obtenerDato() << endl;
    delete ptrRaiz;
}
