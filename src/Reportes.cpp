#include "../include/utilidades/Reportes.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

void Reportes::log(std::string comando, string accion) {
    // Obtener el tiempo actual
    auto now = std::chrono::system_clock::now();

    // Convertir el tiempo actual a tiempo de calendario
    std::time_t tiempo_actual = std::chrono::system_clock::to_time_t(now);

    // Convertir el tiempo de calendario a estructura tm para formatear
    std::tm tiempo_info = *std::localtime(&tiempo_actual);

    // Formatear y mostrar la fecha y hora actual
    std::ostringstream oss;
    oss << std::put_time(&tiempo_info, "%Y-%m-%d %H:%M:%S");
    string time1 = "Comando realizado ["+comando+"] Accion ["+accion+"]  Fecha y hora actual ["+ oss.str()+"]";
    Reportes::historial.push_back(time1);
}

void imprimir_log(list<string>list1_historial) {
    for (string hist:list1_historial) {
        cout<<hist<<endl;
    }
}



void cantidad_contactos_grupo(vector<NodoGrupo*> &lista){
    for (int i = 0; i < lista.size(); ++i) {
        if(lista[i]!=0){
            int cantidad=0;
            NodoGrupo *nodoGrupo= lista[i];
            for (int j = 0; j < nodoGrupo->lista.size(); ++j) {
                if(nodoGrupo->lista[j]!=0){
                    cout<<"Grupo :"+nodoGrupo->name_grupo+" numero de contactos  "<<nodoGrupo->lista[j]->datos.size()<<endl;
                    break;
                }
            }

        }
    }
}
void cantidad_sistema(vector<NodoGrupo*> &lista){
    int total=0;
    for (int i = 0; i < lista.size(); ++i) {
        if(lista[i]!=NULL){
            int cantidad=0;
            NodoGrupo *nodoGrup= lista[i];
            for (int j = 0; j <nodoGrup->lista.size(); ++j) {
                if(nodoGrup->lista[j]!=NULL){
                    cantidad=cantidad+nodoGrup->lista[j]->datos.size();
                }
            }
            total=total+cantidad;

        }
    }
    cout<<"El total de datos del sistema es de "<<total<<endl;
}

void cantidad_grupos(vector<NodoGrupo*> &lista){
    for (int i = 0; i < lista.size(); ++i) {
        if(lista[i]!=NULL){
           int cantidad=0;
            NodoGrupo *nodoGrup= lista[i];

            for (int j = 0; j <nodoGrup->lista.size(); ++j) {
                if(nodoGrup->lista[j]!=NULL){
                    cantidad=cantidad+nodoGrup->lista[j]->datos.size();
                }
            }
            cout<<"En el grupo : "+nodoGrup->name_grupo+" hay una cantidad de "<<cantidad<<endl;

        }
    }
}


void Reportes::repotes_menu(vector<NodoGrupo*> &lista) {
    int menu;
    while(menu!=-1){
        cout<<"1) Cantidad de datos por Grupo \n";
        cout<<"2) Cantidad de datos de todo el sistema \n";
        cout<<"3) Cantidad de Contactos con el mismo tipo de dato del campo de criterio de ordenamiento \n";
        cout<<"4) Cantidad de Contactos por Grupo \n";
        cout<<"5) Archivo Log del sistema \n";
        cout<<"6) Salir \n";
        cin>>menu;
        switch (menu) {
            case 1:
                 cantidad_grupos(lista);
                break;
            case 2:
                cantidad_sistema(lista);
                break;
            case 3:

                break;
            case 4:
                cantidad_contactos_grupo(lista);
                break;
            case 5:
                imprimir_log(Reportes::historial);
                break;
            case 6:
                menu=-1;
                break;
            default:
                cout<<"fuera de rango"<<endl;
        }
    }

}