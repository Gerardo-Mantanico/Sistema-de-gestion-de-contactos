#include "../include/utilidades/AgregarContactos.h"
#include "../include/hash/FuncionHash.h"
#include "../include/Nodos/NodoGraph.h"
#include <iostream>
#include <vector>
using namespace std;

FuncionHash *fh= new FuncionHash();
NodoGrupo *grupo8=NULL;
int index;
void AgregarContactos::buscargrupo(std::string name_grupo,vector<NodoGrupo*> &lista) {
    int llave=fh->function_hash(name_grupo,lista.size());
    grupo8=lista[llave];
    index=0;
}

void AgregarContactos::insertarCampos(std::string campo) {
    if(grupo8!=NULL){
        if (index >= 0 && index < grupo8->list_estrucura.size()) {
            auto it = next(grupo8->list_estrucura.begin(), index);
            int llave =fh->function_hash(*it,grupo8->lista.size());
            grupo8->lista[llave]->datos.push_back(campo);
            index++;
        } else {
            std::cout << "Índice fuera de rango." << std::endl;
        }
    }
    else{
        cout<<"El grupo no existes"<<endl;
        return;
    }


}


