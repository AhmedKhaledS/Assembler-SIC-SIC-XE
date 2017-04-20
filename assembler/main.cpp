#include <iostream>
#include "driver/AssemblerDriver.h"
#include "ObjectCodeGenerator/SimpleDirectiveObjectCodeGenerator.h"
#include "ObjectCodeGenerator/MemoryObjectCodeGenerator.h"
#include "tables/InstructionTypeTable.h"
#include "ObjectCodeGenerator/DirectiveObjectCodeGenerator.h"
#include "MemoryInstructionHandler.h"
#include "driver/StatementParser.h"
#include "handlers/OperandHandlerState.h"
#include <sstream>
#include "tables/SymbolTable.h"
#include "utils/Normalizer.h"

using namespace std;

int main(void)
{
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

//    InstructionTypeTable::load();
//    HandlerContext* h = new HandlerContext();
//    InstructionHandlerState i(h);
//    i.handle("resb");
//    OperandHandlerState o(h);
//    o.handle("anything");

//    MemoryInstructionHandler d("HELLO!,X");
//    d.handle();

//    SymbolTable::add("game222","0000");
//
//    HandlerContext *handler = new HandlerContext();
//    LabelHandlerState l(handler);
//    l.handle("game222");

    string code = "HELLO         FROM THE other X'qw  ww'   ";
    Normalizer n;
    string output = n.normalizedInst(code);
    cout << output << endl;


    return 0;
}
