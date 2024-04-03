#include <lib/eigen/Eigen/Dense>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "etl/etl.h"
#include "modeling/log_reg.h"

#include <fstream>

int main(){ 
    //init ETL class
    std::string path = "/home/kishen/documents/c++_projects/wine_classifier/data/wine_data_shuffled.csv";
    char sep = ',';
    bool headers = false;
    int rows = 178;
    int cols = 14;
    
    // std::cout << "Input path to raw data\n";
    // std::cin >> path;

    // std::cout << "Does data contain headers (true/false)?\n";
    // std::cin >> headers;


    //create normalized train + test sets
    std::vector<std::vector<std::string>> csv;

    ETL etl(path, sep, headers, rows, cols);
    csv = etl.read_csv();
    
    Eigen::MatrixXd mat1;
    mat1 = etl.csv_to_eigen(csv);

    Eigen::MatrixXd x_train, x_test, y_train, y_test;

    std::tie(x_train, x_test, y_train, y_test) = etl.train_test_split(mat1);
    
    std::vector <double>  train_means = etl.calculate_mean(x_train);
    std::vector <double> train_sds = etl.calculate_sd(x_train);
    
    Eigen::MatrixXd x_train_norm = etl.normalize_matrix(x_train, train_means, train_sds);
    Eigen::MatrixXd x_test_norm = etl.normalize_matrix(x_test, train_means, train_sds);
    
    //train logreg model

    Eigen::MatrixXd scores;
    double m = 0; // max to subract from numerarot to prevent softmax from overflow
    //https://codereview.stackexchange.com/questions/180467/implementing-softmax-in-c
    //https://codereview.stackexchange.com/questions/180467/implementing-softmax-in-c
    return 0;





}