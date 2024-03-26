#include <iostream>
#include "../include/Terminal.h"
#include "../include/CrearGrupo.h"
#include <string>
#include <regex>
using  namespace  std;
CrearGrupo *grupo= new CrearGrupo();
void gramatica(string &texto, vector<NodoGrupo*> &lista) {
    // Expresiones regulares
    regex regex_add_new_group("ADD\\s+NEW-GROUP\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regex_add_contact_in(R"(ADD\s+CONTACT\s+IN\s+(\w+)\s+FIELDS\s*\(\s*(\w+),\s*(\w+),\s*(\w+),\s*([\w-]+)\s*\);)");
    regex regex_find_contact_in(R"(FIND\s+CONTACT\s+IN\s+(\w+)\s+CONTACT-FIELD\s+(\w+)=(\w+);)");
    smatch matches;
        if (regex_match(texto, matches, regex_add_new_group)) {
            grupo->crear(matches[1],matches[2],lista);

        } else if (regex_match(texto, matches, regex_add_contact_in)) {
            //crear contacto
            cout << "Grupo: " << matches[1] <<endl;
            cout << "Campos: " <<endl;
            for (int i = 0; i < matches.size(); ++i) {
                cout << matches[i] <<endl;
            }
        } else if (regex_match(texto, matches, regex_find_contact_in)) {
            //bucar contacto
            cout << "FIND CONTACT IN:" <<endl;
            cout << "Grupo: " << matches[1] <<endl;
            cout << "Campo de contacto: " << matches[2] << " = " << matches[3] << endl;
        } else {
            cout << "No se encontraron coincidencias para el texto: " << texto << endl;
        }
        cout <<endl;
    }


void Terminal::consola() {
    cin.ignore();
    string comando;
    do {
        cout<< "Para salir de la terminal presione 'S'\n";
        cout << "TERMINAL INICIALIZADA\n";
        getline(cin, comando);
        gramatica(comando,Terminal::list);
    } while (comando != "S" && comando != "s");
    return;
}

void Terminal::entrada(string texto) {
    gramatica(texto,Terminal::list);
}