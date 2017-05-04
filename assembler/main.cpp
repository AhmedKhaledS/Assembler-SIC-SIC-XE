#include <iostream>
#include <sstream>
#include <string>
#include "utils/TablesLoader.h"
#include "driver/AssemblerDriver.h"
#include "tables/InstructionTypeTable.h"

using namespace std;

int main(void)
{
    TablesLoader::loadTables();
    AssemblerDriver assembler = AssemblerDriver();
    assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example.txt");
//    FileReader reader = FileReader();
//    reader.readInst("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example.txt");

//    string code = "JEQ	 ENDFIL";
//    Normalizer n;
//    vector<string> output = n.splittedInst(code);
//    for(int i=0;i<output.size();i++){
//        cout << output.at(i);
//   }

    return 0;
}
