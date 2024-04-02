#include <iostream>
#include "../include/recursos/Importacion.h"
#include "../include/recursos/Terminal.h"
#include <string>
#include <fstream>
using namespace std;

void Importacion::archivo(Reportes *reportes, Terminal *terminal) {
    ifstream archivo("../archivo");
    string texto;
    if (archivo.is_open()) {
        while (getline(archivo, texto)) {
            terminal->entrada(texto,reportes);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }
}

