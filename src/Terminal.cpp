#include <iostream>
#include "../include/Terminal.h"
#include "../include/Grupo.h"
#include "../include/hhash.h"
#include <string>
#include <regex>
using  namespace  std;

void CrearGrupo( string nombre, string campo){
        hhash *hashs= new hhash();
        string nombre_grupo = nombre;
        cout << "Nombre del grupo: " << nombre_grupo << endl;
        cout << "Campos:"<<endl;
        regex patron_campos("(\\w+)\\s+(\\w+)(?:\\s*,|$)");
        smatch match_campos;
        auto inicio = campo.cbegin();
        auto fin =campo.cend();
        while (regex_search(inicio, fin, match_campos, patron_campos)) {
            Campo *nuevo_campo = new Campo(match_campos[1],match_campos[1]);
            int index= hashs->function_hash(nuevo_campo->getNombre(),5);
            cout<<"la llave es : "<<index<<endl;
            hashs->insertar_campo(index,nuevo_campo);
            cout<<"--------------------------------------------"<<endl;
        inicio = match_campos[0].second;
    }
    for (int i = 0; i <hashs->size_lista; ++i) {
     if(hashs->lista_campo[i]!=0){
         cout<<i<<" "<<hashs->lista_campo[i]->campos->getNombre()<<endl;
     }
     else{
         cout<<i<<" "<<hashs->lista_campo[i]<<endl;
     }
    }


}
void gramatrica(string &texto) {
    // Expresiones regulares
    regex regex_add_new_group("ADD\\s+NEW-GROUP\\s+(\\w+)\\s+FIELDS\\s+\\((.*?)\\);");
    regex regex_add_contact_in(R"(ADD\s+CONTACT\s+IN\s+(\w+)\s+FIELDS\s*\(\s*(\w+),\s*(\w+),\s*(\w+),\s*([\w-]+)\s*\);)");
    regex regex_find_contact_in(R"(FIND\s+CONTACT\s+IN\s+(\w+)\s+CONTACT-FIELD\s+(\w+)=(\w+);)");
    smatch matches;
        if (regex_match(texto, matches, regex_add_new_group)) {
            CrearGrupo(matches[1],matches[2]);

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
    string comando="NO";
    while(comando!="S"){
        cout<<endl<<"Para salir de la terminal precione S \n";
        cout<<"TERMINAL INICIALIZADA \n";
        getline(cin,comando);
        gramatrica(comando);
    }
}

void Terminal::entrada(string texto) {
    gramatrica(texto);
}