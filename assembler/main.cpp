#include <iostream>
#include "driver/AssemblerDirective.h"
#include "string"

using namespace std;

int main(void)
{
    HandlerContext *handler = new HandlerContext();
    handler->handle("ahmed");
    handler->handle("khaled");
    handler->handle("ahmed");
    return 0;
}
