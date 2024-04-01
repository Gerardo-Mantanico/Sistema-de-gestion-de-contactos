#include <string>
#include <vector>
#include "../Nodos/NodoGrupo.h"

using namespace std;
#ifndef GESTION_CONTACTOS_BUSCAR_H
#define GESTION_CONTACTOS_BUSCAR_H
class Buscar{
public:
    void contacto(string nombre_grupo,string nombre_campo,string dato, vector<NodoGrupo*> &lista);
};
#endif //GESTION_CONTACTOS_BUSCAR_H
