#include "regressionlogistic.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
/*
 * Primera función miembro : la función sigmoid
 */


Eigen::MatrixXd RegressionLogistic::Sigmoid(Eigen::MatrixXd Z)
{

    // función sigmoid que retorna la matriz con el calculo de la función:
    return 1/(1+(-Z.array()).exp());

}

/* Segunda función: la función de propagacion, la cual contiene el tratamiento
 * de la función de costo( cross entropia) , y sus correspondientes derivadas.
 */
std::tuple<Eigen::MatrixXd, double, double>RegressionLogistic::Propagation(Eigen::MatrixXd W,
                                                                           Eigen::MatrixXd X ,
                                                                           double b,
                                                                           Eigen:: MatrixXd y, double lambda){

    // sobre la base de la presentación de regresión logistiva

    int m = y.rows();

    // Se obtiene la matriz Eigen Z
    Eigen::MatrixXd Z = (W.transpose() * X.transpose()).array()+b;
    Eigen::MatrixXd A = Sigmoid(Z);

    /* Se crea la funcion para la entropia cruzada: No sabemos que valor se va a retornar
     */
    auto cross_entropy = -(y.transpose()*(Eigen::VectorXd)A.array().log().transpose()+((Eigen::VectorXd)(1-y.array())).transpose()*(Eigen::VectorXd)(1-A.array()).log().transpose())/m;

    /* Funcion para reducir la varianza del  modelo, usando
     * la regularizacion
     */
    double l2_reg_costo= W.array().pow(2).sum()*(lambda/(2*m));
    /* Función para el calculo del costo usando la entropia cruzada
     * con el ajuste de regularización:
     * Se hace uso de static_cast debido  a que la función debe retornar un
     * double pero va estar compuesta de tipo de datos definidos por
     * usuario(auto).*/
    double costo = static_cast<const double>((cross_entropy.array()[0]) + l2_reg_costo);

    /* Se calcula la derivada de las matrices en función de los pesos */
    Eigen:: MatrixXd dw  = ((Eigen::MatrixXd)(A-y.transpose())*X/m)+(Eigen::MatrixXd)(lambda/m*W).transpose();

    /* Se calcula la derivada en funció del bias(punto de corte)
     */
    double db= ((A-y.transpose()).array().sum())/m;

   /* Se retorna de la funcion de propagacion la derivada de los pesos(w)
    *la derivada del bias y retornamos el costo ;
    * el retorno es una tupla comprimida
    */
    return std::make_tuple(dw,db,costo);
}
    /*
     * Se crea la funcio de optimización:
     * Se crea una lista en donde se va almacenar cada uno de los
     * valores de la función de costo hasta converger. Esta actualización
     * se almacenara en un fichero, para posteriormente ser visualizado.
     * La actualización se observa en la presentación de regresion logistica.
     * Se pasa una bandera a la función para imprimir si se quiere el valor
     * del costo cada 100 iteraciones
     *
     */

std::tuple<Eigen::MatrixXd,double,Eigen::MatrixXd,double,std::list<double>> RegressionLogistic::Optimization(Eigen::MatrixXd W, double b, Eigen::MatrixXd X, Eigen::MatrixXd y, int num_iter, double learning_rate, double lamda, bool log_cost){
        // se crea la lista
        std::list<double> lista_costo;
        Eigen::MatrixXd dw;
        double db, costo;


        // Se hace la iteración
        for(int i=0; i<num_iter;i++){
            std::tuple<Eigen::MatrixXd,double,double>propagation = Propagation(W,X,b,y,lamda);
            std::tie(dw,db,costo)=propagation;

            /* Se actualizan los valores (W, b), que representan los weights y biases */
            W = W - (learning_rate * dw).transpose();
            b = b - (learning_rate * db);

            /* Segun la bandera se guarda cada 100 pasos el valor del costo */
            if(i % 100 == 0){
                lista_costo.push_back(costo);
            }

            /* Se imprime por pantalla segun la bandera */
            if(log_cost && i % 100 == 0){
                std::cout << "Costo despues de actualizar " << i << ": " << costo <<std::endl;
            }
        }

        return std::make_tuple(W, b, dw, db, lista_costo);

    }


/* Función de prediccion:
 * La funcion estimara (Prediccion) la etiqueta de salida si corresponde a 0 o 1
 * la idea es calcular ŷ (y estimado) usando los parametros de regresión (W y b)
 * aprendidos.
 * Se convierten las entradas a 0, si la funcion de activacion es inferior o igual a 0.5.
 * Se convierten las entradas a 1, si la funcion de activacion es superior a 0.5. */

Eigen::MatrixXd RegressionLogistic::Prediction(Eigen::MatrixXd W, double b, Eigen::MatrixXd X){
    /* Se calculan la cantidad de valores de registros (m) */
    int m = X.rows();
    /* Se crea una matriz con valores del vector de ceros del tamaño de la matriz de entrada (X) */
    Eigen::MatrixXd y_pred = Eigen::VectorXd::Zero(m).transpose();

    /* Se crea una matriz para almacenar los valores de Z (calculados) */
    Eigen::MatrixXd Z = (W.transpose() * X.transpose()).array() + b;

    /* Se calcula la función sigmoid en la matriz A */
    Eigen::MatrixXd A = Sigmoid(Z);

    /* Se calcula el valor estimado (Etiquetas 0 a 1), segun la funcion de activacion, para cada uno
     * de los registros (matrix X) */
    for (int i = 0; i < A.cols(); i++){
        if (A(0, i) <= 0.5){
            y_pred(0, i) = 0;
        }else{
            y_pred(0, i) = 1;
        }
    }

    return y_pred.transpose();
}
