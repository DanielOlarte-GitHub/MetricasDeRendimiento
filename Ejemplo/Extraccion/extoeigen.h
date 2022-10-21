#ifndef EXTOEIGEN_H
#define EXTOEIGEN_H

#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>

#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>

// .csv Valores separados por comas
// Fila es un registro
// Columna es los datos en el registro

class Extraer{
    /* Se presenta el constructor de los argumentos
     * de entrada a la clase "Extraer" */

    /* Nombre del dataset */
    std::string setDatos;

    /* Separador de columnas */
    std::string delimitador;

    /* Si el dataset tiene cabecera o no*/
    bool header;

public:
    Extraer(std::string datos,
            std::string separador,
            bool head):
        setDatos(datos),
        delimitador(separador),
        header(head){}
    std::vector<std::vector<std::string>> ReadCSV();
    Eigen::MatrixXd CSVToEigen(
            std::vector<std::vector<std::string>>  SETdatos,
            int filas, int columnas);
    auto Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean());

};
#endif // EXTOEIGEN_H
