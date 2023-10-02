#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>

#include "../lib/eigen/Eigen/Dense"
//#include "../lib/boost/include/boost/algorithm/string"
#include "../etl/etl.h"



ETL::ETL(std::string a, char b, bool c):path(a),sep(b),header(c)
{}


std::vector<std::vector <std::string>> ETL::load_data()
    {
        std::vector<std::vector <std::string>> datastring;
        
        std::fstream raw_data(path, std::ios::in);
        std::string line;
        
        if (raw_data.is_open())
        {
            while(getline(raw_data, line))
            {
                std::vector<std::string> vec;
                //boost::algorithm::split(vec, line, boost::is_any_of(sep));
                datastring.push_back(vec);
            }
        }
        raw_data.close();
        return datastring;
    };
