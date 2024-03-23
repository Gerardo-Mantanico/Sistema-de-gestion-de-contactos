#include<iostream>
#include <string>
#include "Nodo.h"
#include "Campo.h"
#include "CampoNodo.h"
#include <vector>

using namespace  std;
#ifndef GESTION_CONTACTOS_GROUP_H
#define GESTION_CONTACTOS_GROUP_H
class Grupo{
public:
    string name_group;
    //vector<Campo> arreglo;
    CampoNodo *lista_campo[];
    CampoNodo* get(CampoNodo *lista_campo[], int indice) {
            return lista_campo[indice];
    }

};
#endif //GESTION_CONTACTOS_GROUP_H
