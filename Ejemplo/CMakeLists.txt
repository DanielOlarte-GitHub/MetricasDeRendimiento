cmake_minimum_required(VERSION 3.5)

project(Ejemplo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Se crea una lista con todas las fuentes
set(project_sources
    main.cpp
    Extraccion/extoeigen.cpp)

set(project_headers
    Extraccion/extoeigen.h)

#Se crean los ejecutables con todos los archivos fuentes necesarios
add_executable(${PROJECT_NAME}
    ${project_sources}
    ${project_headers})
