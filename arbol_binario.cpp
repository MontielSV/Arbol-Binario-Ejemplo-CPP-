#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

// Recorrido Preorden
void preOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    cout << raiz->dato << " ";
    preOrden(raiz->izq);
    preOrden(raiz->der);
}

// Recorrido Inorden
void inOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    inOrden(raiz->izq);
    cout << raiz->dato << " ";
    inOrden(raiz->der);
}

// Recorrido Postorden
void postOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    postOrden(raiz->izq);
    postOrden(raiz->der);
    cout << raiz->dato << " ";
}

int main() {
    // Construir el arbol binario
    Nodo* raiz = crearNodo(1);

    raiz->izq = crearNodo(2);
    raiz->der = crearNodo(3);

    raiz->izq->izq = crearNodo(4);
    raiz->izq->der = crearNodo(5);

    raiz->der->izq = crearNodo(6);
    raiz->der->der = crearNodo(7);

    cout << "================================\n";
    cout << "          ARBOL BINARIO\n";
    cout << "================================\n\n";

    cout << "          1\n";
    cout << "        /   \\\\\n";
    cout << "       2     3\n";
    cout << "      / \\\\   / \\\\\n";
    cout << "     4   5 6   7\n\n";

    cout << "================================\n";
    cout << "           RECORRIDOS\n";
    cout << "================================\n\n";

    cout << "Preorden:  ";
    preOrden(raiz);

    cout << "\nInorden:   ";
    inOrden(raiz);

    cout << "\nPostorden: ";
    postOrden(raiz);

    cout << "\n\n================================\n";
    cout << "        FIN DEL PROGRAMA\n";
    cout << "================================\n";

    return 0;
}
