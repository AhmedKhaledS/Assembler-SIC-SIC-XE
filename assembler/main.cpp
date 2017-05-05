#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include "utils/TablesLoader.h"
#include "driver/AssemblerDriver.h"
#include "tables/InstructionTypeTable.h"
#include "../logger/Logger.h"
#include "fileServices/FileWriter.h"


using namespace std;

int main()
{
    TablesLoader::loadTables();
    AssemblerDriver assembler = AssemblerDriver();
    cout << "Please Enter the .asm file path" << endl;
    string path;
    getline(cin,path);
    cout << path << endl;
    //replace(path.begin(), path.end(), '\\', '/');
    //cout << path << endl;
    //assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\tests\\SIC-test3'abii.txt");
    //assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example2.txt");
    assembler.assemble(path);
    assembler.generateListingCode();
    assembler.generateObjectCode();
    return 0;
}
