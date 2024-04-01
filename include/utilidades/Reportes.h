#include <string>
#include <list>
#include <vector>
#include "../Nodos/NodoGrupo.h"

using namespace std;
#ifndef GESTION_CONTACTOS_REPORTES_H
#define GESTION_CONTACTOS_REPORTES_H


class Reportes {
private:
    list<string> historial;
public:
    void log(string comando, string accion);
    void  repotes_menu(vector<NodoGrupo*> &lista);
};


#endif //GESTION_CONTACTOS_REPORTES_H
