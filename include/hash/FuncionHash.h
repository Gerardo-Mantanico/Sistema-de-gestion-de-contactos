#include "iostream"
#include <string>
using namespace std;
#ifndef GESTION_CONTACTOS_FUNCIONHASH_H
#define GESTION_CONTACTOS_FUNCIONHASH_H
class FuncionHash{
public:
    int function_hash(string name_groups,int size) {
        int sum=0;
        for (int i = 0; i <name_groups.size() ; ++i) {
            char caractaer=name_groups[i];
            sum+=(caractaer*(i+1));
        }
        cout<<"Nombre del Grupo: "<<name_groups<<" "<<"\tLLave: "<<sum%size<<"\t  tamano de arreglo\t"<<size<<endl;
        return sum%size;
    }
};
#endif //GESTION_CONTACTOS_FUNCIONHASH_H
