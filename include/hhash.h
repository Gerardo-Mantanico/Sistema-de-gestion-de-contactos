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
    int size_lista=5;
    vector<CampoNodo*> lis;
    hhash(int size) : lis(size, nullptr) {}
    void insertar_campo( Campo *campo);
    void insertar_grupo(int llave, Grupo, vector<Grupo> list_grupo);


};
#endif //GESTION_CONTACTOS_HASH_H
