cmake_minimum_required(VERSION 3.27)
project(Gestion_Contactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gestion_Contactos main.cpp
        include/recursos/start.h
        src/start.cpp
        src/Terminal.cpp
        include/recursos/Terminal.h
        src/Importacion.cpp
        include/recursos/Importacion.h
        src/CrearGrupo.cpp
        include/utilidades/CrearCampo.h
        src/CrearCampo.cpp
        include/Nodos/NodoGraph.h
        include/utilidades/GeneradorDotFile.h
        src/GeneradorDotFile.cpp
        include/utilidades/ArbolAlv.h
        src/ArbolAlv.cpp
        include/utilidades/AgregarContactos.h
        src/AgregarContactos.cpp
        src/Graficas.cpp
)
