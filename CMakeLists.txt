cmake_minimum_required(VERSION 3.26.3)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                src/main.cpp
                src/Servidor.cpp
                src/Sistema.cpp
                src/Usuario.cpp)