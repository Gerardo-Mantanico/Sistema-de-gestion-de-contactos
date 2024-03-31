#include <string>
using namespace std;
#ifndef GESTION_CONTACTOS_GENERADORDOTFILE_H
#define GESTION_CONTACTOS_GENERADORDOTFILE_H

#include "../Nodos/NodoGraph.h"

class GeneradorDotFile{
public:
    void generateDotFile(NodoGraph* root, const string& filePath);
};
#endif //GESTION_CONTACTOS_GENERADORDOTFILE_H
