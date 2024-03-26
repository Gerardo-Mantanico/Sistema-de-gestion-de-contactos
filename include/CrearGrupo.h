//
// Created by HP on 25/03/2024.
//
#include <string>
#include <vector>
#include "NodoGrupo.h"

using namespace std;
#ifndef GESTION_CONTACTOS_CREARGRUPO_H
#define GESTION_CONTACTOS_CREARGRUPO_H


class CrearGrupo {
public:
    void crear(string nombre, string grupo, vector<NodoGrupo*> &lista);
};


#endif //GESTION_CONTACTOS_CREARGRUPO_H
