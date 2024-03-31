#include <iostream>
#include "../include/utilidades/CrearGrupo.h"
#include "../include/hash/FuncionHash.h"
#include "../include/utilidades/CrearCampo.h"
#include <regex>

FuncionHash *funciong = new FuncionHash();
CrearGrupo *crearCampo= new CrearGrupo();
CrearCampo *crearCampo1= new CrearCampo();
void rehash_campo(int new_size, vector<NodoGrupo*> &lis);
int porcentajeg=0;

NodoGrupo* insertar(string  name_grupo, vector<NodoGrupo*> &list){
    int llave = funciong->function_hash(name_grupo, list.size());
    NodoGrupo *nuevo_nodo=list[llave];
    while (nuevo_nodo != NULL) {
        if (nuevo_nodo->llave == llave) {
            nuevo_nodo->name_grupo=name_grupo;
            return nuevo_nodo;
        }
        nuevo_nodo =nuevo_nodo->siguiente;
    }
    NodoGrupo *nuevo_grupo= new NodoGrupo(name_grupo,5);
    nuevo_nodo=list[llave];
    nuevo_grupo->siguiente=nuevo_nodo;
    list[llave]=nuevo_grupo;
    porcentajeg++;
    double porcentaje_total = ((porcentajeg * 100) / list.size());
    cout << "El porcentaje disponible es de : " << porcentaje_total << "%" << endl;
    if (porcentaje_total >= 60) {
        cout << "Realizar rehash" << endl;
        cout<<endl<<endl;
       rehash_campo(list.size(),list);
    }
    return nuevo_grupo;
}

void rehash_campo(int new_size, vector<NodoGrupo*> &lis) {
    porcentajeg=0;
    vector<NodoGrupo*> tem;
    tem.resize(lis.size()+6);
    for (int i = 0; i < lis.size(); ++i) {
        NodoGrupo* cabeza= lis[i];
        while (cabeza!= nullptr){
           int nueva_llave=funciong->function_hash(cabeza->name_grupo,tem.size());
           cabeza->llave=nueva_llave;
           tem[nueva_llave]=cabeza;
           cabeza=cabeza->siguiente;
           porcentajeg++;
        };
    }
    lis=tem;
}


void CrearGrupo::crear(std::string nombre, std::string campo, vector<NodoGrupo *> &lista) {
     NodoGrupo* nodoGrupo=insertar(nombre,lista);
     regex patron_campos("(\\w+)\\s+(\\w+)(?:\\s*,|$)");
     smatch match_campos;
     auto inicio = campo.cbegin();
     auto fin =campo.cend();
     while (regex_search(inicio, fin, match_campos, patron_campos)) {
        cout<<match_campos[1]<<"     "<<match_campos[2]<<endl;
        nodoGrupo->list_estrucura.push_back(match_campos[1]);
        crearCampo1->crear(match_campos[1],match_campos[2],nodoGrupo->lista);
        inicio = match_campos[0].second;
    }

}