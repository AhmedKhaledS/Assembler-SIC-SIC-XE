#include <iostream>
#include <sstream>
#include <string>
#include "utils/TablesLoader.h"
#include "driver/AssemblerDriver.h"
#include "tables/InstructionTypeTable.h"
#include "../logger/Logger.h"
#include "fileServices/FileWriter.h"


using namespace std;

int main(void)
{
    Logger::loggerOn = false;
    TablesLoader::loadTables();
    AssemblerDriver assembler = AssemblerDriver();
    assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example.txt");
    assembler.generateObjectCode();
    return 0;
}
