cmake_minimum_required(VERSION 3.5)

project(logisticProyect LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Se crea una variable para las fuentes
set(project_sources
    main.cpp
    Extraccion/extraction.cpp
    ClaseLogistic/regressionlogistic.cpp)


#Se crea una variable para las <headers>
set(project_headers
    Extraccion/extraction.h
    ClaseLogistic/regressionlogistic.h)

# Se nombran los ejecutables
add_executable(${PROJECT_NAME}
    ${project_sources}
    ${project_headers})




