#include <iostream>
#include <sstream>
#include <string>
#include "utils/TablesLoader.h"
#include "driver/AssemblerDriver.h"
#include "tables/InstructionTypeTable.h"
#include "Logger.h"


using namespace std;

int main(void)
{
    Logger::loggerOn = false;
    TablesLoader::loadTables();
    AssemblerDriver assembler = AssemblerDriver();
    assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example.txt");
    //assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Machine\\Exmpls\\aaa.txt");
    return 0;
}
