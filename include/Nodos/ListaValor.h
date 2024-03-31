#include <string>
using namespace std;
#ifndef GESTION_CONTACTOS_NODOVALOR_H
#define GESTION_CONTACTOS_NODOVALOR_H
struct NodoValor {
    string dato;
    NodoValor* siguiente;
    NodoValor* anterior;
};

class ListaValor {
public:
    NodoValor *cabeza;
    ListaValor() : cabeza(nullptr) {}
    void insertarAlInicio(string dato) {
        NodoValor *nuevoNodo = new NodoValor;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = nullptr;
        if (cabeza != nullptr) {
            cabeza->anterior = nuevoNodo;
        }
        cabeza = nuevoNodo;
    }

};
#endif //GESTION_CONTACTOS_NODOVALOR_H
