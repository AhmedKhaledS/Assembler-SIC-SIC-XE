#include <iostream>
#include <sstream>
#include <string>
#include "TablesLoader.h"
#include "ObjectCodeGenerator/DirectiveObjectCodeGenerator.h"
#include "tables/SymbolTable.h"

using namespace std;

int main(void)
{
<<<<<<< HEAD
    string inst, oper;
    TablesLoader::loadTables();
    SymbolTable::add("limit", "00032F");
    while (true) {
        cin >> inst >> oper;
        DirectiveObjectCodeGenerator d = DirectiveObjectCodeGenerator(oper, inst);
        cout << d.parse() << endl;
    }
=======
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

//    string code = "HELLO         FROM THE other X'qw  ww'   ";
//    Normalizer n;
//    string output = n.normalizedInst(code);
//    cout << output << endl;

      MemoryObjectCodeGenerator m("ldx","BUFFER,X");
      string objectCode = m.parse();
      cout << "Object Code: " << objectCode;

>>>>>>> 068646d296a7ae8563ac4184548d449f919adbf9
    return 0;
}
