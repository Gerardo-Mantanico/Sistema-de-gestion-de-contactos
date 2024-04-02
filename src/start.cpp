#include "../include/recursos/start.h"
#include "../include/recursos/Terminal.h"
#include "../include/recursos/Importacion.h"
#include "../include/Nodos/NodoGraph.h"
#include "../include/utilidades/GeneradorDotFile.h"
#include "../include/recursos/Graficas.h"
#include "../include/recursos/Exportaciones.h"
#include "../include/utilidades/Reportes.h"
#include <iostream>
using namespace std;
Terminal *terminal= new Terminal(5);
Importacion *importacion= new Importacion();
vector<NodoGrupo*>lista;
Graficas *graficas = new Graficas();
Exportaciones *exportacion= new Exportaciones();
Reportes *reportes= new Reportes();

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
                terminal->consola(reportes);
                lista=terminal->list;
                break;
            case  2:
                reportes->repotes_menu(lista);
                break;
            case  3:
                graficas->menu(lista);
                break;
            case  4:
                exportacion->archivo(lista);
                break;
            case  5:
                importacion->archivo(reportes,terminal);
                lista=terminal->list;
                break;
            case 6:
                cout<<"Sistema Finalizado :D";
                delete terminal;
                delete reportes;
                delete graficas;
                delete exportacion;
                delete importacion;
                break;
            default:
                cout<<"Fuera de rango"<<endl;
        }

    }

}
