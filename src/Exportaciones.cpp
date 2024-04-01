#include <string>
#include <iostream>
#include "../include/recursos/Exportaciones.h"
#include "../include/hash/FuncionHash.h"
#include <fstream>
#include <filesystem>

#ifdef _WIN32
#include <direct.h> // Para Windows
#define mkdir _mkdir
#else
#include <sys/stat.h> // Para sistemas basados en Unix
#endif

using namespace std;
namespace fs = std::filesystem;
FuncionHash *fun=new FuncionHash();


void crear_exportacion(NodoGrupo *NG){
    // Crear una carpeta
    string folderName = "../"+NG->name_grupo;
    if (fs::exists(folderName) && fs::is_directory(folderName)) {
        cout << "La carpeta ya existe." << endl;
    } else {
        cout << "La carpeta no existe." << endl;
        //Creamos la carpeta.
    #ifdef _WIN32
        int folderCreated = mkdir(folderName.c_str());
    #else
        int folderCreated = mkdir(folderName.c_str(), 0777); // Permisos en sistemas Unix
    #endif
        if (folderCreated == 0) {
            cout << "Carpeta creada correctamente." << endl;
        } else {
            cout << "Error al crear la carpeta. Es posible que ya exista" << endl;
            return;
        }
    }

    // Crear un archivo de texto dentro de la carpeta
    string filePath = folderName +"/contactos.txt";
    ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        for (string estrucura :NG->list_estrucura) {
            outputFile <<"\n"+estrucura<<"\t";
            int llave= fun->function_hash(estrucura,NG->lista.size());
            for (string cam:NG->lista[llave]->datos) {
                outputFile << cam<<"\t";
            }

        }
        outputFile.close();
        cout << "Archivo de texto creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo de texto." << endl;
        return;
    }

}

void Exportaciones::archivo(vector<NodoGrupo*> &lista) {
    string name;
    cout<<"Ingrese el nombre del grupo que desa exportar"<<endl;
    cin>>name;
    int llave= fun->function_hash(name,lista.size());
    NodoGrupo *NG=lista[llave];
    crear_exportacion(NG);
}