#include <iostream>
#include "driver/AssemblerDriver.h"
#include "ObjectCodeGenerator/SimpleDirectiveObjectCodeGenerator.h"
#include "ObjectCodeGenerator/MemoryObjectCodeGenerator.h"
#include "tables/InstructionTypeTable.h"

using namespace std;

int main(void)
{

//    SimpleDirectiveObjectCodeGenerator s("sub");
//    cout << "Object Code is " << s.parse() << endl;
//    return 0;

      MemoryObjectCodeGenerator s("or","XXXX,X");
      cout << "Object Code is " << s.parse() << endl;

//    HandlerContext *handler = new HandlerContext();
//    handler->handle("ahmed");
//    handler->handle("khaled");
//    handler->handle("ahmed");
      InstructionTypeTable::load();
      cout << InstructionTypeTable::getType("ldx");
    return 0;

}
