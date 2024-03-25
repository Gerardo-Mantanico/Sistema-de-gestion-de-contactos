#include "../include/start.h"
#include "../include/Terminal.h"
#include "../include/Importacion.h"
#include <iostream>
using namespace std;
Terminal *terminal= new Terminal();
Importacion *importacion= new Importacion();



void start::Start() {
    int menu;
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
            break;
        case  2:
            break;
        case  3:
            break;
        case  4:
            break;
        case  5:
            importacion->archivo();
            break;
        case  6:

            break;
        default:
            cout<<"Fuera de rango"<<endl;
    }
}
