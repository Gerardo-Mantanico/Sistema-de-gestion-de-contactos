#include "../include/utilidades/AgregarContactos.h"
#include "../include/hash/FuncionHash.h"
#include "../include/Nodos/NodoGraph.h"
#include <iostream>
#include <vector>
using namespace std;

FuncionHash *fh= new FuncionHash();
NodoGrupo *grupo8=NULL;
int i=0;
void AgregarContactos::buscargrupo(std::string name_grupo,vector<NodoGrupo*> &lista) {
    int index=fh->function_hash(name_grupo,lista.size());
    grupo8=lista[index];
    i=0;
}

void AgregarContactos::insertarCampos(std::string campo) {
    int salir=0;
    if(i<grupo8->lista.size()){
        while (salir!=1){
            if(grupo8->lista[i]!=0){
                cout<<"en el campo: \n "<<grupo8->lista[i]->name_campo;
                grupo8->lista[i]->datos.push_back(campo);
                i++;
                salir=1;
            }
            else{ i++; }
        }
    }
}


