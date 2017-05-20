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

    AssemblerDriver assembler = AssemblerDriver();
    cout << "Please Enter the .asm file path" << endl;
    string path;
    //getline(cin,path);
    path = "D:\\Collage\\Assembler Project GIT\\Assembler-SIC-SIC-XE-\\assembler\\TestCases\\literals.asm";
    assembler.assemble(path);
    return 0;
}
