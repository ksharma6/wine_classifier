#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cmath>

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
    
    Eigen::MatrixXd train = dataset.topRows(train_rows);
    Eigen::MatrixXd test = dataset.bottomRows(test_rows);

    Eigen::MatrixXd x_train, x_test, y_train, y_test;

    x_train = train.rightCols(train.cols() -1);
    y_train = train.leftCols(1);

    

    x_test = test.rightCols(train.cols() -1);
    y_test = test.leftCols(1);

    
    return std::make_tuple(x_train, x_test, y_train, y_test);
}

std::vector <double> ETL::calculate_mean(Eigen::MatrixXd dataset)
{
    std::vector <double> means;
    for (int c=0; c < dataset.cols() ; c++)
    {
        means.push_back(dataset.col(c).mean());
    }
    return means;
}

std::vector <double> ETL::calculate_sd(Eigen::MatrixXd dataset) 
{
    std::vector <double> standard_deviations;

    for (int col = 0; col < dataset.cols(); col++)
    {
        Eigen::ArrayXd vec = dataset.col(col);
        double std_dev = std::sqrt((vec - vec.mean()).square().sum()/(vec.size()-1));
        
        standard_deviations.push_back(std_dev);
    }
    return standard_deviations;
}

Eigen::MatrixXd ETL::normalize_matrix(Eigen::MatrixXd dataset,
std::vector <double>  means, std::vector <double> standard_deviations)
{
    Eigen::MatrixXd norm_data(dataset.rows(), dataset.cols());

    for (int i=0; i< dataset.rows(); i++)
    {
        for (int j=0; j < dataset.cols(); j++)
        {
            norm_data(i, j) = (dataset.coeff(i,j) - means[j])/standard_deviations[j];
        }
    }
    return norm_data;
}

void ETL::write_to_csv(Eigen::MatrixXd dataset, std::string filename)
{
    std::ofstream file((opath + filename).c_str());
    for (int i = 0; i < dataset.rows(); i++)
    {
        for (int j=0; j < dataset.cols(); j++)
        {
            std::string str = std::to_string(dataset(i, j));
            if (j + 1 == dataset.cols())
            {
                file << str;
            }
            else
            {
               file << str << ',';
            }
        }
           file << '\n';
    }

    std::cout << "File writing completed" << std::endl;
}