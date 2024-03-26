#include "../include/CrearCampo.h"
#include "../include/FuncionHash.h"
using namespace std;

FuncionHash *f= new FuncionHash;
int porcentajeCampo=0;

void rehash_campos(int new_size, vector<CampoNodo*> &lis) {
    porcentajeCampo=0;
    vector<CampoNodo*> tem;
    tem.resize(lis.size()+6);
    for (int i = 0; i < lis.size(); ++i) {
        CampoNodo* cabeza= lis[i];
        while (cabeza!= nullptr){
            int nueva_llave=f->function_hash(cabeza->name_campo,tem.size());
            cabeza->llave=nueva_llave;
            tem[nueva_llave]=cabeza;
            cabeza=cabeza->siguiente;
            porcentajeCampo++;
        };
    }
    lis=tem;
}
void CrearCampo::crear(string nombre_campo, string tipo, vector<CampoNodo *> &lista) {
    int llave = f->function_hash(nombre_campo, lista.size());
     CampoNodo *nuevo_nodo=lista[llave];
    while (nuevo_nodo != NULL) {
        if (nuevo_nodo->llave == llave) {
            nuevo_nodo->name_campo=nombre_campo;
            nuevo_nodo->type=tipo;
            return;
        }
        nuevo_nodo =nuevo_nodo->siguiente;
    }
    CampoNodo *nuevo_grupo= new CampoNodo(llave, nombre_campo,tipo);
    nuevo_nodo=lista[llave];
    nuevo_grupo->siguiente=nuevo_nodo;
    lista[llave]=nuevo_grupo;

    porcentajeCampo++;
    double porcentaje_total = ((porcentajeCampo * 100) / lista.size());
    cout << "El porcentaje disponible es de : " << porcentaje_total << "%" << endl;
    if (porcentaje_total >= 60) {
        cout << "Realizar rehash" << endl;
        cout<<endl<<endl;
        rehash_campos(lista.size(),lista);
    }
}