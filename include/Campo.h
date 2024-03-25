#include <string>
using namespace std;
#ifndef GESTION_CONTACTOS_CAMPO_H
#define GESTION_CONTACTOS_CAMPO_H
class Campo{
private:
    string nombre;
    string tipo;
    Campo *siguiente;
public:
    Campo(string nombre, string tipo){
        this->nombre=nombre;
        this->tipo=tipo;
        this->siguiente=NULL;
    }
    Campo(){}
    string getNombre(){
        return this->nombre;
    }
    string getTipo(){
        return this->tipo;
    }
};
#endif //GESTION_CONTACTOS_CAMPO_H
