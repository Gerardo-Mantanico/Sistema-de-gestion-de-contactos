#include "../include/recursos/Graficas.h"
#include "../include/utilidades/GeneradorDotFile.h"
#include "../include/utilidades/ArbolAlv.h"
#include "../include/hash/FuncionHash.h"
#include <iostream>
#include <string>
using namespace std;
GeneradorDotFile *generador= new GeneradorDotFile();
ArbolAlv *arbolAl = new ArbolAlv();
NodoGraph *nodo=NULL;
FuncionHash *fhas= new FuncionHash();
void Graficas::menu(vector<NodoGrupo*>list) {
    int opcion;
    int Clave;
    NodoGrupo *g=NULL;
    CampoNodo *cp=NULL;
    string gr=" ";
    string campo;
    while(opcion!=4){
        cout<<"1) Graficar la estructura completa"<<endl;
        cout<<"2) Graficar por grupo"<<endl;
        cout<<"3) Graficar por campo"<<endl;
        cout<<"4) Salir"<<endl;
        cin>>opcion;
        switch (opcion) {
            case 1:
                nodo=NULL;
                for (int i = 0; i <list.size() ; ++i) {
                    if(list[i]!=0){
                        nodo=arbolAl->insert(nodo,list[i]->llave,list[i]->name_grupo);
                    }
                }
                generador->generateDotFile(nodo,"../Campos.dot");
                system("C:/Users/HP/CLionProjects/Gestion-Contactos/Sistema-de-gestion-de-contactos/Campos.png");
                break;
            case 2:
                nodo=NULL;
                cout<<"ingrese el nombre del Grupo"<<endl;
                cin>>gr;
                 Clave= fhas-> function_hash(gr,list.size());
                g= list[Clave];
                for (int i = 0; i <g->lista.size() ; ++i) {
                    if(g->lista[i]!=0 ){
                        nodo=arbolAl->insert(nodo,g->lista[i]->llave,g->lista[i]->name_campo);
                    }
                }
                generador->generateDotFile(nodo,"../Grupos.dot");
                system("C:/Users/HP/CLionProjects/Gestion-Contactos/Sistema-de-gestion-de-contactos/Grupos.png");
                break;
            case 3:
                nodo=NULL;
                cout<<"ingrese el nombre del Grupo"<<endl;
                cin>>gr;
                Clave= fhas-> function_hash(gr,list.size());
                g= list[Clave];
                cout<<endl<<"ingrese el nombre del Campo"<<endl;
                cin>>campo;
                Clave= fhas-> function_hash(campo,g->lista.size());
                cp=g->lista[Clave];
                for (auto it = cp->datos.begin(); it != cp->datos.end(); ++it) {
                    Clave= fhas-> function_hash(*it,100);
                    nodo=arbolAl->insert(nodo,Clave ,*it);

                }
                generador->generateDotFile(nodo,"../Grupo_campos.dot");
                system("C:/Users/HP/CLionProjects/Gestion-Contactos/Sistema-de-gestion-de-contactos/Grupo_campos.png");
                break;
        }

    }
}