#include <iostream>
#include <string>
#include "vector"
#include "Grupo.h"
#include "CampoNodo.h"
#include "Campo.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#ifndef GESTION_CONTACTOS_HASH_H
#define GESTION_CONTACTOS_HASH_H

class hhash {
public:
    int porcentaje;
    int size_lista=5;
    CampoNodo *lista_campo[5];
    int function_hash(string name_groups, int size);
    void insertar_campo(int llave, Campo *campo);
    void insertar_grupo(int llave, Grupo, vector<Grupo> list_grupo);

    int getSize_lista(){
        return this->size_lista;
    }
    void setSize_lista(int nuevo){
        this->size_lista=nuevo;
    }
    void setLista_campo(CampoNodo *lista_campo[], int indice) {
           this->lista_campo[size_lista]=lista_campo[indice];
    }

};
#endif //GESTION_CONTACTOS_HASH_H
