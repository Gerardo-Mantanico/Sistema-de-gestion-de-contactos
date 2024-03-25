cmake_minimum_required(VERSION 3.27)
project(Gestion_Contactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gestion_Contactos main.cpp
        include/start.h
        src/start.cpp
        src/hhash.cpp
        include/hhash.h
        src/Terminal.cpp
        include/Terminal.h
        src/Importacion.cpp
        include/Importacion.h
        include/Campo.h
        src/Grupo.cpp
)
