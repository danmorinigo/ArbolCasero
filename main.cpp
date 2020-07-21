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
        cout << "9. Salir\n";
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

        }
    }while(opcion != 9);
}
