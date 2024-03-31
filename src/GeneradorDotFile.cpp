#include <iostream>
#include <fstream>
#include <functional>
#include "../include/utilidades/GeneradorDotFile.h"

void GeneradorDotFile::generateDotFile(NodoGraph *root, const std::string &filePath) {
    ofstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    file << "digraph G {\n";
    file << "    node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]; // Configuración de nodos\n";
    file << "    \n";

    // Recorre el árbol y escribe la definición de nodos y conexiones en el archivo DOT
    function<void(NodoGraph*)> writeNodesAndEdges = [&](NodoGraph* node) {
        if (node == nullptr) return;
        file << "    " << node->llave << " [label=\"" << node->dato << "\"];\n";
        if (node->izquierda != nullptr) {
            file << "    " << node->llave << " -> " << node->izquierda->llave << ";\n";
            writeNodesAndEdges(node->izquierda);
        }
        if (node->derecha != nullptr) {
            file << "    " << node->llave << " -> " << node->derecha->llave << ";\n";
            writeNodesAndEdges(node->derecha);
        }
    };

    writeNodesAndEdges(root);
    file << "}\n";
    file.close();
    // Ejecuta Graphviz para generar la imagen del gráfico
    string command = "dot -Tpng " + filePath + " -o " + filePath.substr(0, filePath.find_last_of('.')) + ".png";
    system(command.c_str());
    cout << "Gráfico generado correctamente." << endl;
}