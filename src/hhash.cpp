#include "iostream"
#include <string>
#include "../include/hhash.h"
#include "../include/Grupo.h"
#include "../include/CampoNodo.h"
#include "../include/FuncionHash.h"

using namespace std;
int porcentaje=0;
FuncionHash *funcion= new FuncionHash();
void insertar( Campo *campo,vector<CampoNodo*> &lis, int);
void rehash_campo(int new_size, vector<CampoNodo*> &lis) {
    porcentaje=0;
    vector<CampoNodo*> temp(new_size+6, nullptr); // Crear nueva tabla hash con el nuevo tamaño
    // Recorrer la tabla hash original y reinsertar todos los elementos en la nueva tabla
    for (int i = 0; i < lis.size(); i++) {
        CampoNodo* head = lis[i];
        while (head != nullptr) {
            Campo* c = head->campos;
            int new_key =funcion->function_hash(c->getNombre(), new_size+6); // Calcular nueva llave para el elemento
            CampoNodo* temp_head = temp[new_key]; // Obtener la cabeza de la lista en la nueva ubicación
            CampoNodo* new_node = new CampoNodo(new_key, c); // Crear un nuevo nodo con la nueva llave
            new_node->siguiente = temp_head; // Insertar el nuevo nodo al principio de la lista
            temp[new_key] = new_node; // Actualizar la cabeza de la lista en la nueva ubicación
            porcentaje++;
            double porcentaje_total = ((porcentaje * 100) / (new_size+6));
            cout << "El porcentaje disponible es de >---" << porcentaje_total << "%" << endl;
            head = head->siguiente; // Mover al siguiente nodo en la lista original
        }
    }
    lis = temp;
}

void insertar( Campo *campo, vector<CampoNodo*> &lis,int size) {
    int llave = funcion->function_hash(campo->getNombre(), lis.size());
    CampoNodo *nodo_campo = lis[llave];
    while (nodo_campo != NULL) {
        if (nodo_campo->llave == llave) {
            nodo_campo->campos = campo;
            return;
        }
        nodo_campo = nodo_campo->siguiente;
    }
    CampoNodo *nuevo_campo = new CampoNodo(llave, campo);
    nodo_campo = lis[llave];
    nuevo_campo->siguiente = nodo_campo;
    lis[llave] = nuevo_campo;
    porcentaje++;
    double porcentaje_total = ((porcentaje * 100) / lis.size());
    cout << "El porcentaje disponible es de : " << porcentaje_total << "%" << endl;
    if (porcentaje_total >= 60) {
        cout << "Realizar rehash" << endl;
        cout<<endl<<endl;
        rehash_campo(lis.size(), lis);
    }
}
void hhash::insertar_campo( Campo *campo) {
    insertar(campo,hhash::lis, hhash::size_lista);
}


