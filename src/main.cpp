//#include <lib/eigen/Eigen/Dense>
#include <iostream>
#include <string>

#include "../etl/etl.h"

int main(){
    ETL test1;
    std::string somestring = "some string";
    test1.load_data(somestring);

    return 0;
}