#include "Campo.h"
#include<iostream>
#ifndef GESTION_CONTACTOS_CAMPONODO_H
#define GESTION_CONTACTOS_CAMPONODO_H
class  CampoNodo{
public:
    int llave;
    Campo *campos;
    CampoNodo* siguiente;
    CampoNodo(int llave, Campo *campos){
        this->llave=llave;
        this->campos=campos;\
        this->siguiente=NULL;
    }

};
#endif //GESTION_CONTACTOS_CAMPONODO_H
