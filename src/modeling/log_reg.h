#ifndef LOG_REG_H
#define LOG_REG_H


class LogReg 
{
public:
    Eigen::MatrixXd x_train;
    Eigen::MatrixXd y_train;

    LogReg(Eigen::MatrixXd a, Eigen::MatrixXd b);
    Eigen::MatrixXd softmax(Eigen::MatrixXd input_data);
    // std::tuple<Eigen::MatrixXd, double, double> propogate(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd W, Eigen::MatrixXd b);

    
};
#endif