#include <iostream>
#include "../include/Importacion.h"
#include "../include/Terminal.h"
#include <string>
#include <fstream>
using namespace std;

Terminal *terminal1= new Terminal();
void Importacion::archivo() {
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
}

