#include <lib/eigen/Eigen/Dense>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "etl/etl.h"


#include <fstream>

int main(){ 
    //init ETL class
    std::string path;
    char sep = ',';
    bool headers;
    int rows = 178;
    int cols = 14;
    
    std::cout << "Input path to raw data\n";
    std::cin >> path;

    std::cout << "Does data contain headers (true/false)?\n";
    std::cin >> headers;


    //create data_mat
    std::vector<std::vector<std::string>> csv;

    ETL etl(path, sep, headers, rows, cols);
    csv = etl.read_csv();
    
    Eigen::MatrixXd mat1;
    mat1 = etl.csv_to_eigen(csv);

    //create train + test sets
    Eigen::MatrixXd x_train, x_test, y_train, y_test;
    

    std::tie(x_train, x_test, y_train, y_test) = etl.train_test_split(mat1);
    
    // //normalize data
    std::vector <double>  means = etl.calculate_mean(x_train);
    std::vector <double> sds = etl.calculate_sd(x_train);
    
    Eigen::MatrixXd x_train_norm = etl.normalize_matrix(x_train, means, sds);
    etl.write_to_csv(x_train_norm, "test.csv");
    // //write file to path
    // std::string opath = "/home/kishen/documents/c++_projects/wine_classifier/data/test.csv";

    // std::ofstream file(opath.c_str());
    // for (int i = 0; i < x_train_norm.rows(); i++)
    // {
    //     for (int j=0; j < x_train_norm.cols(); j++)
    //     {
    //         std::string str = std::to_string(x_train_norm(i, j));
    //         if (j == x_train_norm.cols())
    //         {
    //             file << str;
    //         }
    //         else
    //         {
    //             file << str << ',';
    //         }

    //     }
    //     file << '\n';
    // }





}