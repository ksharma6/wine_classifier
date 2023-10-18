#ifndef ETL_H
#define ETL_H


#include <string>
#include <vector>

/**
 * ETL class extracts, transforms and loads dataset
 * 
 * Class params:
 *  - string path: path to data 
 *  - char sep: seperator in data file for parsing 
 *  - bool header: indicates whethere data contains a column header or not.
 * 
*/
class ETL
{
private:
    std::string opath = "/home/kishen/documents/c++_projects/wine_classifier/data/";

public:
    std::string path;
    char sep;
    bool header;
    int rows;
    int cols;

    ETL(std::string a, char b, bool c, int d, int e);
    /*
    load dataset into memory and return 2D vector
    */
    std::vector<std::vector <std::string>> read_csv();
    /*
    convert 2D vector into 2d eigen matrix
    */
    Eigen::MatrixXd csv_to_eigen(std::vector<std::vector <std::string>> dataset);
    
    /*
    split dataset into x_train, x_test, y_train, y_test
    */
    std::tuple <Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> train_test_split(Eigen::MatrixXd dataset, float train_size = .8);
    std::vector <double> calculate_mean(Eigen::MatrixXd dataset);
    std::vector <double>  calculate_sd(Eigen::MatrixXd dataset);
    Eigen::MatrixXd normalize_matrix(Eigen::MatrixXd dataset,std::vector <double>  means, std::vector <double> standard_deviations);
    void write_to_csv(Eigen::MatrixXd dataset, std::string filename);


};


#endif
