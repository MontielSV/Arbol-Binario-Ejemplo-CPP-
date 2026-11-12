#include <iostream>
#include <string>

using namespace std;

// Estructura de un Nodo para el Árbol Binario
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Función para insertar nodos manteniendo la propiedad de Árbol Binario de Búsqueda (BST)
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return new Nodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }
    return raiz;
}

// Función recursiva para mostrar la relación Padre -> Hijos de cada nodo
void mostrarPadresEHijos(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }

    cout << "Nodo Padre: [" << nodo->valor << "] -> ";

    // Verificar hijo izquierdo
    if (nodo->izquierda != nullptr) {
        cout << "Hijo Izquierdo: " << nodo->izquierda->valor;
    } else {
        cout << "Hijo Izquierdo: Ninguno";
    }

    cout << " | ";

    // Verificar hijo derecho
    if (nodo->derecha != nullptr) {
        cout << "Hijo Derecho: " << nodo->derecha->valor;
    } else {
        cout << "Hijo Derecho: Ninguno";
    }

    cout << endl;

    // Recorrer recursivamente los subárboles izquierdo y derecho
    mostrarPadresEHijos(nodo->izquierda);
    mostrarPadresEHijos(nodo->derecha);
}

// Función para liberar la memoria dinámica del árbol
void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izquierda);
    liberarArbol(nodo->derecha);
    delete nodo;
}

int main() {
    Nodo* raiz = nullptr;

    // Construimos el árbol insertando valores
    //       50
    //      /  \
    //    30    70
    //   /  \  /  \
    //  20  40 60  80
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);

    cout << "--- ESTRUCTURA DEL ARBOL BINARIO (PADRES E HIJOS) ---" << endl;
    cout << "Raiz principal: " << raiz->valor << "\n" << endl;

    mostrarPadresEHijos(raiz);

    // Liberamos la memoria antes de salir
    liberarArbol(raiz);

    return 0;
}
