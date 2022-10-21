#include "extoeigen.h"
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <boost/algorithm/string.hpp>

/* Primer funcion miembro: Lectura de fichero csv.
 * Se presenta como un vector de vectores del
 * tipo string.
 * La idea es leer linea por linea y almacenar
 * cada una en un vector de vectores del
 * tipo string. */

std::vector<std::vector<std::string>> Extraer::ReadCSV(){
    /* Abrir el fichero para lectura solamente */
    std::fstream Fichero(setDatos);

    /* Vector de vectores tipo string a entregar por
     * parte de la funcion */
    std::vector<std::vector<std::string>> datosString;

    /* Se itera a traves de cada linea, y se divide
     * el contenido dado por el separador( argumento
     * de entrada) provisto por el constructor */

    std::string linea = ""; // Almacenar cada linea
    while(getline(Fichero, linea)){
       /* Se crea un vector para almacenar la fila */
        std::vector<std::string> vectorFila;

       /* Se separa segun el delimitador */
        boost::algorithm::split(vectorFila,
                                linea,
                                boost::is_any_of(delimitador));
        datosString.push_back(vectorFila);
    }

    /* Se cierra el fichero .csv */
    Fichero.close();

    /* Se retorna el vector de
     * vectores del tipo string */
    return datosString;
}

/* Se implementa la segunda funcion miembro
 * la cual tiene como mision transformar el
 * vector de vectores del tipo String, en
 * una matrix Eigen. La idea es simular un
 * objeto DATAFRAME de pandas para poder
 * manipular los datos */

Eigen::MatrixXd Extraer::CSVToEigen(
        std::vector<std::vector<std::string>>  SETdatos,
        int filas, int columnas){
    /* Se hace la pregunta si tiene cabezera o no
     * el vector de vectores del tipo String.
     * Si tiene cabecera, se debe eliminar */
    if(header == true){
        filas = filas - 1;
    }

    /* Se itera sobre cada registro del fichero,
     * a la vez que se almacena en una matrixXd,
     * de dimension filas por columnas. Principalmente,
     * se almacenara Strings (porque llega un vector de
     * vectores del tipo String. La idea es
     * hacer un casting de String a float. */
    Eigen::MatrixXd MatrizDF(columnas, filas);
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            MatrizDF(j, i) = atof(SETdatos[i][j].c_str());
        }
    }
    //return MatrizDF;
    /* Se transpone la matriz, dado que viene
     * columnas por filas, para retornarla */
    return MatrizDF.transpose();
}


/* Funcion para calcular el promedio
 * En C++ la herencia del tipo de dato
 * no es directa (sobre todo si es a partir
 * de funciones dadas por otras interfaces/clases/
 * biblioteclas: EIGEN, shrkml, etc...). Entonces
 * se declara el tipo en una expresion "decltype"
 * con el fin de tener seguridad de que tipo de dato
 * retornara la funcion */
// En caso de no saber que dato encontrar usar auto y decltype (declarative type)
auto Extraer::Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean()){
    return datos.colwise().mean();
}
