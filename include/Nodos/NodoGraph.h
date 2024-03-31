#include <string>
using namespace std;
#ifndef GESTION_CONTACTOS_NODOGRAPH_H
#define GESTION_CONTACTOS_NODOGRAPH_H
class NodoGraph{
public:
    int llave;
    NodoGraph *izquierda, *derecha;
    int altura;
    string dato;
};
#endif //GESTION_CONTACTOS_NODOGRAPH_H
