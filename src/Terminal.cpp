#include <iostream>
#include "../include/recursos/Terminal.h"
#include "../include/utilidades/CrearGrupo.h"
#include "../include/utilidades/AgregarContactos.h"
#include "../include/utilidades/GeneradorDotFile.h"
#include "../include/utilidades/Buscar.h"
#include <string>
#include <regex>
using  namespace  std;
CrearGrupo *grupo= new CrearGrupo();
AgregarContactos *agregar= new AgregarContactos();
GeneradorDotFile *gd= new GeneradorDotFile();
Buscar *buscar= new Buscar();
void gramatica(string &texto, vector<NodoGrupo*> &lista, Reportes *reportes) {
    // Expresiones regulares
    regex regex_add_new_group("ADD\\s+NEW-GROUP\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regex_add_contact_in(R"(ADD CONTACT IN (\w+) FIELDS \(([\w, -]+)\);)");
    regex regex_find_contact_in(R"(FIND\s+CONTACT\s+IN\s+(\w+)\s+CONTACT-FIELD\s+(\w+)=(\w+);)");
    smatch matches;
        if (regex_match(texto, matches, regex_add_new_group)) {
            grupo->crear(matches[1],matches[2],lista);
            reportes->log(texto,"Creacion de Grupo");
        } else if (regex_match(texto, matches, regex_add_contact_in)) {
           agregar->buscargrupo(matches[1],lista);
            string campos = matches[2];
            regex campoRegex(R"([^,]+)");
            sregex_iterator campoIterator(campos.begin(), campos.end(), campoRegex);
            sregex_iterator endIterator;
            while (campoIterator != endIterator) {
                agregar->insertarCampos(campoIterator->str());
                ++campoIterator;
            }
            reportes->log(texto,"Inserción de Contactos");
        } else if (regex_match(texto, matches, regex_find_contact_in)) {
            buscar->contacto(matches[1],matches[2],matches[3],lista);
            reportes->log(texto,"Búsqueda de Contactos");
        } else {
            cout << "No se encontraron coincidencias para el texto: " << texto << endl;
        }
        cout <<endl;
    }


void Terminal::consola(Reportes *reportes) {
    cin.ignore();
    string comando;
    do {
        cout<< "Para salir de la terminal presione 'S'\n";
        cout << "TERMINAL INICIALIZADA\n";
        getline(cin, comando);
        gramatica(comando,Terminal::list,reportes);
    } while (comando != "S" && comando != "s");
    return;
}

void Terminal::entrada(string texto,Reportes *reportes) {
    gramatica(texto,Terminal::list,reportes);
}