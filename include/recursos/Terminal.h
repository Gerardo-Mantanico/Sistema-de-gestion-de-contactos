#include <iostream>
#include <string>
#include <vector>
#include "../Nodos/NodoGrupo.h"
#include "../utilidades/Reportes.h"

using namespace std;
#ifndef GESTION_CONTACTOS_TERMINAL_H
#define GESTION_CONTACTOS_TERMINAL_H


class Terminal {
public:
    vector<NodoGrupo*>list;
    void consola(Reportes *reportes);
    void entrada(string texto,Reportes *reportes);
    Terminal(int size){
        this->list.resize(size);
    }
};
#endif //GESTION_CONTACTOS_TERMINAL_H
