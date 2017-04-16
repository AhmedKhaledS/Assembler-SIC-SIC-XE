#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

FileReader::FileReader(string fileName)
:fileName(fileName)
{
}

std::vector<std::string> FileReader::readInst(){

    vector<string> code;
    string line;

    ifstream file(fileName.c_str());

    while(getline(file,line)){
        code.push_back(line);
    }

    return code;
}
