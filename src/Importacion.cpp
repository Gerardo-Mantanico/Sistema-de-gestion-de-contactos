#include <iostream>
#include "../include/recursos/Importacion.h"
#include "../include/recursos/Terminal.h"
#include <string>
#include <fstream>
using namespace std;

Terminal *terminal1= new Terminal(5);
vector<NodoGrupo*> Importacion::archivo() {
    ifstream archivo("C:/Users/HP/CLionProjects/Gestion-Contactos/Sistema-de-gestion-de-contactos/archivo");
    string texto;
    if (archivo.is_open()) {
        while (getline(archivo, texto)) {
            terminal1->entrada(texto);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }
    return terminal1->list;
}

