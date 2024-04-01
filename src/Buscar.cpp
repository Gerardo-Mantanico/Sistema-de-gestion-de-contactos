
#include "../include/utilidades/Buscar.h"
#include "../include/hash/FuncionHash.h"

FuncionHash *fi= new FuncionHash();
void Buscar::contacto(string nombre_grupo,string nombre_campo,string dato, vector<NodoGrupo *> &lista) {
    int llave =fi->function_hash(nombre_grupo,lista.size());
    NodoGrupo *nodoGrupo=lista[llave];
    int llave2 =fi->function_hash(nombre_campo,nodoGrupo->lista.size());
    CampoNodo *campoNodo=nodoGrupo->lista[llave2];
    int indice = 0;
    bool encontrado = false;
    for (auto it = campoNodo->datos.begin(); it != campoNodo->datos.end(); ++it) {
        if (*it == dato) {
            cout<<"Busqueda encontrada-> \t";
            encontrado = true;
            for (int i = 0; i <nodoGrupo->lista.size() ; ++i) {
                if(nodoGrupo->lista[i]!=0){
                    auto it = nodoGrupo->lista[i]->datos.begin();
                    // Avanzar al segundo elemento (índice 1)
                    if (std::distance(lista.begin(), lista.end()) > indice) {
                        std::advance(it, indice); // Avanzar el iterador al siguiente elemento
                        std::cout << " " << *it <<"\t"; // Imprimir el elemento
                    } else {
                        std::cout << "No hay suficientes elementos en la lista." << std::endl;
                    }
                }
            }
            cout<<endl;
        }
        indice++;
    }

}