#include <iostream>
#include <cmath>

#include "../lib/eigen/Eigen/Dense"
#include "log_reg.h"

LogReg::LogReg(Eigen::MatrixXd a, Eigen::MatrixXd b):x_train(a), y_train(b) {}


Eigen::MatrixXd LogReg::sigmoid(Eigen::MatrixXd input_data)
{
    Eigen::MatrixXd output;
    output = 1/(1 + exp(-input_data.array()));
    return output;
}

