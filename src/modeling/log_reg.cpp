#include <iostream>
#include <cmath>

#include "../lib/eigen/Eigen/Dense"
#include "log_reg.h"

LogReg::LogReg(Eigen::MatrixXd a, Eigen::MatrixXd b):x_train(a), y_train(b) {}


Eigen::MatrixXd LogReg::softmax(Eigen::MatrixXd input_data)
{
    Eigen::MatrixXd scores;
    scores = exp(input_data.array());
    return scores;
}


// std::tuple<Eigen::MatrixXd, double, double> LogReg::propogate(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd W, Eigen::MatrixXd b)
// {
//     //calculate sigmoid output
//     Eigen::MatrixXd Z = (X.transpose() * W.transpose()) + b;
//     Eigen::MatrixXd output = softmax(Z);

//     auto cross_entropy = 0;
//     //https://www.youtube.com/watch?v=bLb_Kp5Q9cw
//     //https://gombru.github.io/2018/05/23/cross_entropy_loss/
            
// }