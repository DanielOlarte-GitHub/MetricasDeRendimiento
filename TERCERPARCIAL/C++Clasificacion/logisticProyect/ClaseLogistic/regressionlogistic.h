#ifndef REGRESSIONLOGISTIC_H
#define REGRESSIONLOGISTIC_H

#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <list>

class RegressionLogistic
{
public:
    Eigen::MatrixXd Sigmoid(Eigen::MatrixXd Z);
    std::tuple<Eigen::MatrixXd, double, double> Propagation(Eigen::MatrixXd W,
                                                                               Eigen::MatrixXd X ,
                                                                               double b,
                                                                               Eigen:: MatrixXd y, double lambda);

    std::tuple<Eigen::MatrixXd,double,Eigen::MatrixXd,double,std::list<double>> Optimization(Eigen::MatrixXd W, double b, Eigen::MatrixXd X, Eigen::MatrixXd y, int num_iter, double learning_rate, double lamda, bool log_cost);

    Eigen::MatrixXd Prediction(Eigen::MatrixXd W, double b, Eigen::MatrixXd X);


};

#endif // REGRESSIONLOGISTIC_H
