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






};


#endif
