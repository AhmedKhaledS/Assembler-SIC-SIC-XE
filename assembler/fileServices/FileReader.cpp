#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

FileReader::FileReader()
{
}

vector<string> FileReader::read(string path)
{
    vector<string> code;
    string line;

    ifstream file;
    file.open(path, ios::in);

    while(getline(file,line)){
        code.push_back(line);
    }
    file.close();
    return code;
}

void FileReader::write(string path, string fileName, vector<string> objectCodes)
{

}

void FileReader::throwError()
{

}
