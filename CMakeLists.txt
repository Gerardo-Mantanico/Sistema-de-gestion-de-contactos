cmake_minimum_required(VERSION 3.27)
project(Gestion_Contactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gestion_Contactos main.cpp
        include/start.h
        src/start.cpp
        src/Terminal.cpp
        include/Terminal.h
        src/Importacion.cpp
        include/Importacion.h
        src/CrearGrupo.cpp
        include/CrearCampo.h
        src/CrearCampo.cpp
)
