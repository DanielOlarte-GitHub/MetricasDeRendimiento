/*********************************************************
 * Fecha: 28-02-2022 / 02-03-2022
 * Autor: Pedro Cardenas
 * Materia: HPC-1
 * Tema: Implementacion del algoritmo de Regresion Lineal
 * Requerimientos:
 *      1.- Crear una clase que permita la manipulacion
 *          de kits de datos(extraccion, normalizacion,
 *          entre otros) con Eigen.
 *      2.- Crear una clase que permita implementar el
 *          modelo o algoritmo de Regresion Lineal con
 *          Eigen.
 * ******************************************************/

// EL interfaz representa el menu de funciones disponible en las clases/biblioteca

#include "Extraccion/extoeigen.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <string.h>

int main(int argc, char *argv[]){
    /* Se crea un objeto del tipo Extraer
     * para incluir los 3 argumentos que necesita
     * el objeto. */
    Extraer extraerData(argv[1], argv[2], argv[3]);

    /* Se requiere probar la lectura del fichero y
     * luego se requiere observar el dataset como
     * un objeto de matriz tipo dataframe. */
    std::vector<std::vector<std::string>> dataSET = extraerData.ReadCSV();
    int filas = dataSET.size()+1;
    int columnas = dataSET[0].size();
    Eigen::MatrixXd MatrizDataF = extraerData.CSVToEigen(
                dataSET, filas, columnas);

    /* Se imprime la matriz que tiene los datos del
     * dataset. */
    std::cout << "                      **** - Se imprime el Dataset - ****                     " << std::endl;
    std::cout << MatrizDataF << std::endl;
    std::cout << "Filas : " << filas << std::endl;
    std::cout << "Columnas: " << columnas << std::endl;

    std::cout << "Promedio: " << extraerData.Promedio(MatrizDataF) << std::endl;
}
