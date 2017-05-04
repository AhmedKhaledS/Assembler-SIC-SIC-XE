#include <iostream>
#include <sstream>
#include <string>
#include "utils/TablesLoader.h"
#include "driver/AssemblerDriver.h"
#include "tables/InstructionTypeTable.h"

using namespace std;

int main(void)
{
/*
//    SimpleDirectiveObjectCodeGenerator s("sub");
//    cout << "Object Code is " << s.parse() << endl;

//      MemoryObjectCodeGenerator s("or","XXXX,X");
//      cout << "Object Code is " << s.parse() << endl;

//        HandlerContext *handler = new HandlerContext();
//        handler->handle("ahmed");
//        handler->handle("khaled");
//        handler->handle("ahmed");

//    vector<string> x;
//    x.push_back("ahmed");
//    x.push_back("hee");
//    x.push_back("naggar");
//    StatementParser parser;
//    parser.parse(x);

//    InstructionTypeTable::load();
//    cout << InstructionTypeTable::getType("ldx");
    InstructionTypeTable::load();
    HandlerContext* h = new HandlerContext();
    InstructionHandlerState i(h);
    i.handle("resb");
    OperandHandlerState o(h);
    o.handle("anything");

//    MemoryInstructionHandler d("HELLO!,X");
//    d.handle();

//    SymbolTable::add("game222","0000");
//
//    HandlerContext *handler = new HandlerContext();
//    LabelHandlerState l(handler);
//    l.handle("game222");

//    string code("HELLO         FROM THE OTHER C'SI      DE'    ");
//    cout << code << endl << endl;
//
//    Normalizer n;
//    cout << n.normalizedInst(code) << endl;

*/
    TablesLoader::loadTables();
    AssemblerDriver assembler = AssemblerDriver();
//    assembler.assemble("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example.txt");
    FileHandler* reader;
    FileReader rd;
    reader = &rd;
    //reader->
    //reader = new FileReader();
//    reader.readInst("D:\\College\\2ndYear\\2ndTerm\\Systems Programming\\SIC Assignment\\Assembler-SIC-SIC-XE-\\assembler\\fileServices\\SIC-Example.txt");

//    string code = "JEQ	 ENDFIL";
//    Normalizer n;
//    vector<string> output = n.splittedInst(code);
//    for(int i=0;i<output.size();i++){
//        cout << output.at(i);
//   }

    return 0;
}
