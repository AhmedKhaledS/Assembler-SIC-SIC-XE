#include <iostream>
#include "driver/AssemblerDriver.h"
#include "SimpleDirectiveObjectCodeGenerator.h"
#include "MemoryObjectCodeGenerator.h"

using namespace std;

int main(void)
{

//    SimpleDirectiveObjectCodeGenerator s("sub");
//    cout << "Object Code is " << s.parse() << endl;
//    return 0;

//    MemoryObjectCodeGenerator s("ldch","BUFFER,X");
//    cout << "Object Code is " << s.parse() << endl;

    HandlerContext *handler = new HandlerContext();
    handler->handle("ahmed");
    handler->handle("khaled");
    handler->handle("ahmed");

    return 0;

}
