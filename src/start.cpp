#include "../include/start.h"
#include "../include/Terminal.h"
#include "../include/Importacion.h"
#include <iostream>
using namespace std;
Terminal *terminal= new Terminal(5);
Importacion *importacion= new Importacion();
vector<NodoGrupo*>list;


void start::Start() {
    int menu=0;
    while(menu!=6){
        cout <<"\t Gestion de contactos"<<endl;
        cout<<" 1) Terminal"<<endl;
        cout<<" 2) Reportes"<<endl;
        cout<<" 3) Gráficas de las Estructuras"<<endl;
        cout<<" 4) Exportación de Contactos"<<endl;
        cout<<" 5) Importar"<<endl;
        cout<<" 6) Salir "<<endl;
        cout<<"Ingrese en numero de la opcion:"<<endl;
        cin>>menu;
        switch (menu) {
            case  1:
                terminal->consola();
                list=terminal->list;
                break;
            case  2:
                for (int i = 0; i <list.size(); ++i) {
                    if(list[i]!=0){
                        cout<<i<<" "<<list[i]->name_grupo<<endl;
                    }
                    else{
                        cout<<i<<" "<<list[i]<<endl;
                    }
                }
                break;
            case  3:
                break;
            case  4:
                break;
            case  5:
                list=importacion->archivo();
                break;
            case  6:

                break;
            default:
                cout<<"Fuera de rango"<<endl;
        }
    }

}
