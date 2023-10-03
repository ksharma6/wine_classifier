#include <lib/eigen/Eigen/Dense>
#include <iostream>
#include <string>

#include "etl/etl.h"

int main(){
    std::string path;
    char sep = ',';
    bool headers;
    
    
    
    std::cout << "Input path to raw data\n";
    std::cin >> path;

  

    std::cout << "Does data contain headers (true/false)?\n";
    std::cin >> headers;

    ETL test(path, sep, headers);
    test.load_data();
    

    return 0;
}