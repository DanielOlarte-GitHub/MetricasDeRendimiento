#ifndef EXTRACTION_H
#define EXTRACTION_H


#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <list>

/* La clase extraccion ser compone de las funciones
 * o metodos para manipular el dataset
 * Se presentan funciones para:
 * --lectura csv
 * --Promedios
 * --Normalizacion Datos
 * --Desviacion standart
 *
 * La clase recibe como parametros de entrada
 * -- El dataset (path del dataset ".csv"
 * -- El delimitador(separador entre columnas del dataset)
 * -- si el dataset tiene o no Cabecera (header)
 */

class Extraction
{
    /* Se presenta el constructor para los argumentos
     * de entreda a la clase: nombre_dataset,delimitador,header*/

    /* Nombre del dataset */
    std::string setDatos;
    /* Separador de columnas */
    std::string delimitador;
    /* Si el dataset tiene cabecera o no*/
    bool header;

public:
    Extraction(std::string datos,
               std::string separador,
               bool head):
                          setDatos(datos),
                          delimitador(separador),
                          header(head){}


    /******* Prototipo de funciones propias de la clase *********/
    std::vector<std::vector<std::string>> ReadCSV();

    /**Cabecera  de la función CSVToEigen**/
    Eigen::MatrixXd CSVToEigen(
            std::vector<std::vector<std::string>>  SETdatos,
            int filas, int columnas);
    /**Cabecera  de la función Promedio**/
    auto Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean());
    auto DesvSTD(Eigen::MatrixXd datos) ->decltype(((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt());
    Eigen:: MatrixXd  Normalizador(Eigen::MatrixXd datos,bool normalTarget);
    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd>TrainTestSplit(Eigen::MatrixXd data, float train_size);

    void vector_to_file (std::vector<float> vector, std::string nombre_file);
    void EigenToFile(Eigen::MatrixXd datos ,std::string nombre_file);

    void ListToFile(std::list<double> ,std::string nombre_file);
};

#endif // EXTRACTION_H
