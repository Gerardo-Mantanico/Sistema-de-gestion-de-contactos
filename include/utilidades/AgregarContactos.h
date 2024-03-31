#include <string>
#include "../Nodos/NodoGrupo.h"
#include "../Nodos/NodoGraph.h"

using namespace std;
#ifndef GESTION_CONTACTOS_AGREGARCONTACTOS_H
#define GESTION_CONTACTOS_AGREGARCONTACTOS_H
class AgregarContactos {
public:
    void buscargrupo(string name_grupo,vector<NodoGrupo*> &lista);
    void insertarCampos(string campo);
};


#endif //GESTION_CONTACTOS_AGREGARCONTACTOS_H
