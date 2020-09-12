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
    }else{
        int datoEnNodo = ptrRaiz->obtenerDato();
        if(aInsertar < datoEnNodo){
            //cout << "<---" << endl;
            if(ptrRaiz->hijoIzq()){
                //cout << "<-" << endl;
                insertar(ptrRaiz->obtenerIzquierda(), aInsertar);
            }else{
                Nodo* auxAinsertar = new Nodo(aInsertar);
                auxAinsertar->asignarPadre(ptrRaiz);
                ptrRaiz->asignarIzquierda(auxAinsertar);
            }
        }else if(aInsertar > datoEnNodo){
            //cout << "--->" << endl;
            if(ptrRaiz->hijoDer()){
                //cout << "->" << endl;
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
bool ArbolA::existe(Dato buscado){
    Nodo* aux = buscar(this->raiz, buscado);;
    if(aux){
        return true;
    }
    return false;
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
void ArbolA::minimo(){
    Nodo* aux = this->minimo(this->raiz);
    if(aux){
        cout << "El valor mas chico es: " << aux->obtenerDato() << endl;
    }else{
        cout << "ARBOL ESTA VACIO\n";
    }
}

int ArbolA::obtenerAltura(Nodo* node) {
    if (node != NULL){
        int alturaLadoIzquierdo = obtenerAltura(node->obtenerIzquierda()) + 1;
        int alturaLadoDerecho = obtenerAltura(node->obtenerDerecha()) + 1;
        if (alturaLadoIzquierdo > alturaLadoDerecho){
            return alturaLadoIzquierdo;
        }
        return alturaLadoDerecho;
    }
    return 0;
}

int ArbolA::obtenerAltura() {
    return obtenerAltura(raiz);
    //return this->obtenerAltura(this->raiz);
}

void ArbolA::mayor(){
    if(this->mayor(this->raiz)){
        cout << "El valor mas grande es: " << this->mayor(this->raiz)->obtenerDato() << endl;
    }else{
        cout << "ARBOL ESTA VACIO\n";
    }
}
Nodo* ArbolA::mayor(Nodo* nodo){
    if(nodo){
        if(nodo->hijoDer()){
            return mayor(nodo->obtenerDerecha());
        }
        return nodo;
    }
    return 0;
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
void ArbolA::ancho2(){
    Cola cola;
    if(this->raiz){
        cola.insertar(this->raiz);
    }
    int tamActual, nivel = 0;
    Nodo* aux;
    while(!cola.vacia()){
        cout << "Nivel " << nivel << ": ";
        tamActual = cola.obtenerTamanio();
        for(int i = 0; i < tamActual; i++){
            aux = cola.eliminar();
            if(aux->hijoIzq()){
                cola.insertar(aux->obtenerIzquierda());
            }
            if(aux->hijoDer()){
                cola.insertar(aux->obtenerDerecha());
            }
            cout << aux->obtenerDato();
            if(i + 1 == tamActual){
                cout << endl;
            }else{
                cout << " - ";
            }
        }
        nivel++;
    }
}
void ArbolA::nivelMasNodos(){
    int nivel = nivelConMasNodos();
    if(nivel == -1){
        cout << "Arbol vacio\n";
    }else{
        cout << "Nivel con mas nodos: " << nivel << ".\n";
    }
}
int ArbolA::nivelConMasNodos(){
    int nivel = -1, tamActual, nodosMax = -1, nivelActual = 0;
    Cola cola;
    if(this->raiz){
        nivel = 0;
        cola.insertar(this->raiz);
    }
    Nodo* aux;
    while(!cola.vacia()){
        tamActual = cola.obtenerTamanio();
        if(tamActual > nodosMax){
            nodosMax = tamActual;
            nivel = nivelActual;
        }
        for(int i = 0; i < tamActual; i++){
            aux = cola.eliminar();
            if(aux->hijoDer()){
                cola.insertar(aux->obtenerDerecha());
            }
            if(aux->hijoIzq()){
                cola.insertar(aux->obtenerIzquierda());
            }
        }
        nivelActual++;
    }
    return nivel;
}
int ArbolA::enNivel(Dato buscado){
    return this->enNivel(buscado, this->raiz, 0);
}
int ArbolA::enNivel(Dato buscado, Nodo* nodo, int nivel){
    if(!nodo){
        return -1;
    }else if(buscado == nodo->obtenerDato()){
        return nivel;
    }else if(buscado > nodo->obtenerDato()){
        return enNivel(buscado, nodo->obtenerDerecha(), nivel + 1);
    }else{
        return enNivel(buscado, nodo->obtenerIzquierda(), nivel + 1);
    }
}
void ArbolA::balanceado(){
    if(balance(this->raiz)){
        cout << "SI\n";
    }else{
        cout << "NO\n";
    }
}
bool ArbolA::balance(Nodo* nodo){
    if(!nodo){
        return true;
    }
    cout << "CHEQUEO: " << nodo->obtenerDato();
    int altDer = 0, altIzq = 0;
    altDer = alturaBalance(nodo->obtenerDerecha());
    altIzq = alturaBalance(nodo->obtenerIzquierda());
    int diferencia = vAbsoluto(altDer - altIzq);
    if(diferencia > 1){
        cout << " Mal! (Diferencia " << diferencia <<")" << endl;
        return false;
    }
    cout << " Ok!" << endl;
    if(!balance(nodo->obtenerDerecha())){
        return false;
    }
    return balance(nodo->obtenerIzquierda());
}
int ArbolA::alturaBalance(Nodo* nodo){
    if(nodo){
        int altDer = alturaBalance(nodo->obtenerDerecha()) + 1;
        int altIzq = alturaBalance(nodo->obtenerIzquierda()) + 1;
        return max(altDer, altIzq);
    }
    return 0;
}
int ArbolA::vAbsoluto(int numero){
    if(numero < 0){
        numero *= -1;
    }
    return numero;
}
bool ArbolA::simetrico(const ArbolA& aComparar){
    int altComparar = aComparar.obtenerAltura();
    if(altComparar != this->obtenerAltura()){
        return false;
    }
}
