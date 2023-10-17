#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

#include "../lib/eigen/Eigen/Dense"
#include "etl.h"

ETL::ETL(std::string a, char b, bool c, int d, int e):path(a),sep(b),header(c), rows(d), cols(e)
{}

std::vector<std::vector <std::string>> ETL::read_csv()
    {   
        std::string line;
        int r = 0;

        std::vector <std::vector <std::string>> csv;
        std::ifstream datafile(path);
        while (r < rows && getline(datafile, line))
        {
            std::vector<std::string> row;

            std::stringstream iss(line);
            int c= 0;
            std::string val;

            while (c < cols && getline(iss, val, sep))
            {
                row.push_back(val);
            }
            csv.push_back(row);
        }
        return csv;

    };

Eigen::MatrixXd ETL::csv_to_eigen(std::vector<std::vector <std::string>> dataset)
{
    rows =  dataset.size();
    cols = dataset[0].size();
    if (header == true)
    {
        rows = rows -1;
    }
    
    Eigen::MatrixXd matrix(rows, cols);

    for (int i =0; i < rows; i++)
    {
        for (int j =0; j < cols; j++)
        {
            matrix(i, j) = std::stod(dataset[i][j].c_str());
        }
    }
    return matrix;
}

std::tuple <Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> ETL::train_test_split(Eigen::MatrixXd dataset, float train_size)
{
    int train_rows = rows * train_size;
    int test_rows = rows - train_rows;

    Eigen::MatrixXd x_train, x_test, y_train, y_test;

    x_train = dataset.topRows(train_rows);
    x_test = dataset.bottomRows(test_rows);

    y_train = x_train.leftCols(1);
    y_test = x_test.leftCols(1);

    
    return std::make_tuple(x_train, x_test, y_train, y_test);
}

Eigen::ArrayXd calculate_mean(Eigen::MatrixXd dataset)
{
    Eigen::ArrayXd means = dataset.colwise().mean();
    std::cout << means << std::endl;
    return means;
}


Eigen::ArrayXd calculate_sd(Eigen::MatrixXd dataset, Eigen::ArrayXd means)
{
    Eigen::ArrayXd sd;

    return sd;
}