#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>

#include "../lib/eigen/Eigen/Dense"
#include "etl.h"




ETL::ETL(std::string a, char b, bool c):path(a),sep(b),header(c)
{}


std::vector<std::vector <char>> ETL::load_data()
    {
        std::vector<std::vector <char>> datastring;
        
        std::fstream raw_data(path, std::ios::in);
        std::string line;
        
        while(getline(raw_data, line, sep))
            {
                std::vector<char> row;
                
                for (char &c : line)
                {
                    if (c != sep)
                    {
                        row.push_back(c);
                    }
                }
                datastring.push_back(row);
            }
        

        for ( std::vector<char> &row : datastring)
        {
            for (char &c : row)
            {
                std::cout << c<< ' ';
            }
            std::cout << '\n';
        }

        return datastring;
    };
