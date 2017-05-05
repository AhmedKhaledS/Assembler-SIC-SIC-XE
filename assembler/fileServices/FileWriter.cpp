#include "FileWriter.h"
#include "../ObjectCodeGenerator/Constants.h"
#include <fstream>


using namespace std;

FileWriter::FileWriter()
{
    //ctor
}

void FileWriter::write(string path, string fileName, vector<string> objectCodes)
{
    ofstream file(path + fileName + Constants::TXT_EXTENSION);
    for (string line : objectCodes)
    {
        file << line + "\n";
    }
    file.close();
}

vector<string> FileWriter::read(string path)
{

}

void FileWriter::throwError()
{

}
