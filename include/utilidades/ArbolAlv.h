//
// Created by HP on 26/03/2024.
#ifndef GESTION_CONTACTOS_ARBOLALV_H
#define GESTION_CONTACTOS_ARBOLALV_H

#include "../Nodos/NodoGraph.h"

class ArbolAlv {
public:
    NodoGraph* insert(NodoGraph* nodo, int llave,string campo);
};


#endif //GESTION_CONTACTOS_ARBOLALV_H
