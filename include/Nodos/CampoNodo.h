#include<iostream>
#include <string>
#include <list>

using namespace std;
#ifndef GESTION_CONTACTOS_CAMPONODO_H
#define GESTION_CONTACTOS_CAMPONODO_H
class  CampoNodo{
public:
    int llave;
    string  name_campo;
    string type;
    list<string> datos;
    CampoNodo* siguiente;
    CampoNodo(int llave, string name_campo, string type){
        this->llave=llave;
        this->name_campo=name_campo;
        this->type=type;
        this->siguiente=NULL;
    }


};
#endif //GESTION_CONTACTOS_CAMPONODO_H
