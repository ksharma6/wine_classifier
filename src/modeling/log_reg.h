#ifndef LOG_REG_H
#define LOG_REG_H


class LogReg 
{
public:
    Eigen::MatrixXd x_train;
    Eigen::MatrixXd y_train;

    LogReg(Eigen::MatrixXd a, Eigen::MatrixXd b);
    Eigen::MatrixXd sigmoid(Eigen::MatrixXd input_data);

};
#endif