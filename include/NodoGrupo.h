#include <iostream>
#include <string>
#include <vector>
#include "CampoNodo.h"
using namespace std;
#ifndef GESTION_CONTACTOS_NODOGRUPO_H
#define GESTION_CONTACTOS_NODOGRUPO_H
class NodoGrupo {
public:
    int llave;
    string name_grupo;
    NodoGrupo *siguiente, *anterios;
    vector<CampoNodo*> lis;
    NodoGrupo(string nombre, int size){
        this->name_grupo=nombre;
        this->lis.resize(size);
        this->anterios=NULL;
        this->siguiente=NULL;
    }
};


#endif //GESTION_CONTACTOS_NODOGRUPO_H
