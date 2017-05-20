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
#include "tables/LiteralTable.h"
#include "instructionHandler/expressions.handler/ExpressionEvaluator.h"
#include "ExpressionDirectiveInstructionHandler.h"
#include <string>
using namespace std;

int main()
{

//    AssemblerDriver assembler = AssemblerDriver();
//    cout << "Please Enter the .asm file path" << endl;
//    string path;
//    getline(cin,path);
//    assembler.assemble(path);
    LiteralData lt("ahmed", "XXXXX", 5);
    LiteralTable::addLiteral("key", lt);
    LiteralTable::addLiteral("key", LiteralData("naggar", "axsxa", 2));
    vector<string> z;
    z = LiteralTable::getLiteralPool();
    cout << z[0] << z[1] << endl;
    return 0;
}
