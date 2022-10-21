#include "extraction.h"
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <boost/algorithm/string.hpp>

/* Implementacion de los metodos de la clase Extraccion*/



/* Primer funcion miembro: Lectura de fichero csv.
 * Se presenta como un vector de vectores del
 * tipo string.
 * La idea es leer linea por linea y almacenar
 * cada una en un vector de vectores del
 * tipo string. */

std::vector<std::vector<std::string>> Extraction::ReadCSV(){
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

Eigen::MatrixXd Extraction::CSVToEigen(
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
auto Extraction::Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean()){
    return datos.colwise().mean();
}




/* Función de Desciación Standar:
* data = xi - x.promedio */
auto Extraction::DesvSTD(Eigen::MatrixXd datos) ->decltype(((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt()){
    return ((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt();
}

/* Acto seguido se procede a hacer el cálculo o la función de normalización: La idea
* es vitar los cambios en orden de magnitud. Lo anterior representa un deterioro para
* la prediccion sobre la base de cualquier modelo de machine laearning. Evita los outliers.
* Se hara la validacion si se quiere o no normalizar la variable target*/

Eigen:: MatrixXd Extraction:: Normalizador(Eigen::MatrixXd datos,bool normalTarget){
    Eigen::MatrixXd dataNorm;
    if(normalTarget==true){
        dataNorm=datos;

    }else{
        dataNorm= datos.leftCols(datos.cols()-1);

    }

    /* Normalización:
    * MatrixNorm = xi - x.mean() / desviacionEstandar */
    Eigen::MatrixXd DataEscalado = dataNorm.rowwise() - Promedio(dataNorm);
    Eigen::MatrixXd matrixNorm = DataEscalado.array().rowwise()/DesvSTD(DataEscalado);

    /* Si es falso se debe retornar la matriz entera con target incluido*/
    if(normalTarget==false){
        matrixNorm.conservativeResize(matrixNorm.rows(),matrixNorm.cols()+1);
        matrixNorm.col(matrixNorm.cols()-1)=datos.rightCols(1);
    }



    /* Se retorna cada dato escalado */
    return matrixNorm;
}

/* funcion para divir en conjunto de entrenamiento y de prueba:
 * Se crean 4 matrices que representan los cuatro conjuntos :
 *          variable independientes de entrenamiento
 *          variable dependiente de entrenamiento
 *          variable independiente de prueba
 *          vairable dependiente prueba
 * La función recibe como argumento la matriz normalizada, y el tamaño
 * a divir los conjuntos.
*/


std::tuple<Eigen::MatrixXd, Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd>Extraction::TrainTestSplit(Eigen::MatrixXd data, float train_size){

    // cantidad de filas totales de data
    int filas_totales= data.rows();

    // cantidad de filas para entremaniento
    int filas_train = round(filas_totales * train_size);

    // cantidad de filas para prueba

    int filas_test= filas_totales - filas_train;

    Eigen:: MatrixXd Train = data.topRows(filas_train);
    Eigen:: MatrixXd X_Train = Train.leftCols(data.cols()-1);
    Eigen:: MatrixXd y_Train = Train.rightCols(1);


    Eigen:: MatrixXd Test = data.bottomRows(filas_test);
    Eigen:: MatrixXd X_Test = Test.leftCols(data.cols()-1);
    Eigen:: MatrixXd y_Test = Test.rightCols(1);

    /* Se retorna la tupla comprimida*/

    return std:: make_tuple(X_Train,y_Train,X_Test,y_Test);

}

/* función para pasar de vector iostream a fichero plano, para
 * visualizar en graficas. La función recibe el vector y el
 * nombre del fichero a exportar*/

void  Extraction::vector_to_file (std::vector<float> vector, std::string nombre_file){
    // se nombra el fichero

    std::ofstream fichero_salida(nombre_file);

    // se itera por cada vector para imprimirlo en cada fichero
    std::ostream_iterator<float> salida_iterador(fichero_salida, "\n");
    // se entrega la copia a un fichero
    std::copy(vector.begin(), vector.end(), salida_iterador);




}
/* Función para pasar de matrix a fichero*/

void Extraction:: EigenToFile(Eigen::MatrixXd datos ,std::string nombre_file){
    // Se nombra el fichero
    std::ofstream fichero_salida(nombre_file);

    // si el fichero salida esta abierto, guarda datos
    if(fichero_salida.is_open()){
        fichero_salida << datos << "\n";
    }
}















