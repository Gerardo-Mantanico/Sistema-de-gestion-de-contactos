#include "../include/recursos/start.h"
#include "../include/recursos/Terminal.h"
#include "../include/recursos/Importacion.h"
#include "../include/Nodos/NodoGraph.h"
#include "../include/utilidades/GeneradorDotFile.h"
#include "../include/recursos/Graficas.h"
#include "../include/recursos/Exportaciones.h"
#include <iostream>
using namespace std;
Terminal *terminal= new Terminal(5);
Importacion *importacion= new Importacion();
vector<NodoGrupo*>lista;
Graficas *graficas = new Graficas();
Exportaciones *exportacion= new Exportaciones();
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
                lista=terminal->list;
                break;
            case  2:
                for (int i = 0; i <lista.size(); ++i) {
                    if(lista[i]!=0){
                        cout<<i<<" "<<lista[i]->name_grupo<<endl;
                    }
                    else{
                        cout<<i<<" "<<lista[i]<<endl;
                    }
                }
                break;
            case  3:
                graficas->menu(lista);
                break;
            case  4:
                    exportacion->archivo(lista);
                break;
            case  5:
                lista=importacion->archivo();
                break;
            default:
                cout<<"Fuera de rango"<<endl;
        }
    }

}
