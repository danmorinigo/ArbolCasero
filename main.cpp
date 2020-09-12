#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "arbolA.h"

using namespace std;
void menu(ArbolA*);

int main()
{
    srand(time(0));
    ArbolA* primerArbol = new ArbolA;
    menu(primerArbol);
    delete primerArbol;
    return 0;
}
void menu(ArbolA* arbolito){
    int opcion, dato;
    do{
        cout << "\n1. Insertar\n";
        cout << "2. Mostrar arbol completo\n";
        cout << "3. Buscar dato\n";
        cout << "4. Recorrido en Profundidad: PreOrden\n";
        cout << "5. Recorrido en Profundidad: InOrden\n";
        cout << "6. Recorrido en Profundidad: PostOrden\n";
        cout << "7. Eliminar un dato\n";
        cout << "8. Recorrido en ancho\n";
        cout << "9. Altura del arbol\n";
        cout << "10. Valor mas grande\n";
        cout << "11. Valor mas chico\n";
        cout << "12. Insertar 20 valores al azar\n";
        cout << "13. Recorrido en ancho ver.2\n";
        cout << "14. Mostrar en que nivel esta un dato\n";
        cout << "15. Nivel con mas nodos\n";
        cout << "16. Balanceado?\n";
        cout << "0. Salir\n";
        cout << "\nOpcion: ";
        cin >> opcion;
        switch (opcion){
            case 1:
                cout << "Numero a ingresar: ";
                cin >> dato;
                arbolito->insertar(dato);
                break;
            case 2:
                cout << "\nMostrando arbol:\n";
                arbolito->mostrar();
                break;
            case 3:
                cout << "Numero a ingresar: ";
                cin >> dato;
                arbolito->buscar(dato);
                break;
            case 4:
                cout << "\nRecorrido en PROFUNDIDAD: PreOrden (Raiz-Lado Izquierdo-Lado Derecho)\n";
                arbolito->preOrden();
                cout << endl;
                break;
            case 5:
                cout << "\nRecorrido en PROFUNDIDAD: InOrden (Lado Izquierdo-Raiz-Lado Derecho)\n";
                arbolito->inOrden();
                cout << endl;
                break;
            case 6:
                cout << "\nRecorrido en PROFUNDIDAD: PostOrden (Lado Izquierdo-Lado Derecho-Raiz)\n";
                arbolito->postOrden();
                cout << endl;
                break;
            case 7:
                cout << "\nEliminando\n";
                cout << "\n\nNumero a eliminar: ";
                cin >> dato;
                arbolito->eliminar(dato);
                cout << endl;
                break;
            case 8:
                cout << "\nRecorrido en ANCHURA\n";
                arbolito->ancho();
                cout << endl;
                break;
            case 9:
                cout << "\nAltura del ARBOL\n";
                if(arbolito->obtenerAltura() > 0){
                    cout << "ALTURA: " << arbolito->obtenerAltura() << endl;
                }else{
                    cout << "ARBOL VACIO\n";
                }
                cout << endl;
                break;
            case 10:
                cout << "\nValor mas alto\n";
                arbolito->mayor();
                break;
            case 11:
                cout << "\nValor mas bajo\n";
                arbolito->minimo();
                break;
            case 12:
                cout << "\nInsertar valores al azar (0 - 1000)\n";
                int numero;
                for(int i = 0; i < 20; i++){
                    numero = rand() % 1000 - 0;
                    if(!arbolito->existe(numero)){
                        arbolito->insertar(numero);
                    }
                }
                break;
            case 13:
                cout << "\nRecorrido en ancho version 2\n";
                arbolito->ancho2();
                break;
            case 14:
                cout << "\nMostrar en que nivel....\n";
                int buscado, nivel;
                cout << "Numero a buscar: ";
                cin >> buscado;
                nivel = arbolito->enNivel(buscado);
                if(nivel == -1){
                    cout << "No se encuentra dicho numero" << endl;
                }else{
                    cout << "Encontrado en Nivel " << nivel << ".\n";
                }
                break;
            case 15:
                cout << "\nNivel con mas nodos\n";
                arbolito->nivelMasNodos();
                break;
            case 16:
                cout << "\nEsta balanceado?\n";
                arbolito->balanceado();
                break;
        }
    }while(opcion != 0);
}
