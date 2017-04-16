#include <iostream>
#include "AssemblerDirective.h"
#include "SimpleDirectiveObjectCodeGenerator.h"
#include "MemoryObjectCodeGenerator.h"


using namespace std;

int main(void)
{

//    SimpleDirectiveObjectCodeGenerator s("sub");
//    cout << "Object Code is " << s.parse() << endl;
//    return 0;

    MemoryObjectCodeGenerator s("or","XXXX,X");
    cout << "Object Code is " << s.parse() << endl;
    return 0;

}
