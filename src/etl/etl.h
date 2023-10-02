#ifndef ETL_H
#define ETL_H


#include <string>
#include <vector>

class ETL
{
public:
    std::string path;
    char sep;
    bool header;
    
    ETL(std::string a, char b, bool c);
    std::vector<std::vector <std::string>> load_data();





};


#endif
