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
#include "LiteralData.h"


using namespace std;

int main()
{

    AssemblerDriver assembler = AssemblerDriver();
    cout << "Please Enter the .asm file path" << endl;
    string path;
      getline(cin,path);
    assembler.assemble(path);
//    LiteralData lt("ahmed", "empty", "XXXXX", 5);
//    cout << lt.getName() << endl;
    return 0;
}
