//
// Created by HP on 25/03/2024.
//
//
#include <string>
#include <vector>
#include "CampoNodo.h"

using namespace std;

#ifndef GESTION_CONTACTOS_CREARCAMPO_H
#define GESTION_CONTACTOS_CREARCAMPO_H


class CrearCampo {
public:
    void crear(string nombre_campo, string tipo,vector<CampoNodo*> &lista);
};


#endif //GESTION_CONTACTOS_CREARCAMPO_H
