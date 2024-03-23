#include "iostream"
#include <string>
#include "../include/hhash.h"
#include "../include/Grupo.h"
#include "../include/CampoNodo.h"

using namespace std;
double DEFAULT_LOAD_FACTOR = 0.75;
void insertar(int llave, Campo *campo, CampoNodo *lista_campo[]);
int hhash::function_hash(string name_groups,int size) {
    int sum=0;
    for (int i = 0; i <name_groups.size() ; ++i) {
        char caractaer=name_groups[i];
        sum+=(caractaer*(i+1));
    }
    return sum%size;
}

int porcentaje;
void rehash_campo(int size,CampoNodo *lista_campo[]){
     CampoNodo *temp[2*size];
     for (int i = 0; i < 2 * size; i++) {
         temp[i] = NULL;
     }
     for (int i = 0; i <10; i++) {
         CampoNodo* head = temp[i];
         while (head != NULL) {
             int key = head->llave;
             Campo *c = head->campos;
             insertar(key, c,lista_campo);
             head = head->siguiente;
         }
     }
}

void insertar(int llave, Campo *campo, CampoNodo *lista_campo[]){
    CampoNodo* nodo_campo = lista_campo[llave];
    while (nodo_campo != NULL) {
        if (nodo_campo->llave = llave) {
            nodo_campo->campos= campo;
            return;
        }
        nodo_campo = nodo_campo->siguiente;
    }
    CampoNodo *nuevo_campo = new CampoNodo(llave, campo);
    nodo_campo = lista_campo[llave];
    nuevo_campo->siguiente = nodo_campo;
    lista_campo[llave] = nuevo_campo;

    porcentaje++;
    // Load factor calculated
    double porcentaje_calcular = (100-porcentaje*100/5);
    cout<<"El porcentaje disponible es de : "<<porcentaje_calcular<<"%"<<endl;
    if(porcentaje_calcular==40){
        cout<<"Realizar rehash"<<endl;
        rehash_campo(5,lista_campo);
    }
    else{

    }

}

void hhash::insertar_campo(int llave, Campo *campo) {
    this->porcentaje=hhash::porcentaje;
    insertar(llave,campo,hhash::lista_campo);
}


