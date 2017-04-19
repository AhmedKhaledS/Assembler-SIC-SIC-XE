#include "SimpleDirectiveInstructionHandler.h"
#include <iostream>

using namespace std;


SimpleDirectiveInstructionHandler::SimpleDirectiveInstructionHandler(string inst)
{
    instruction = inst;
}

bool SimpleDirectiveInstructionHandler::handle(){
    if(instruction == ""){
        return true;
    }
    cout << "ERROR: NON EMPTY" << endl;
    return false;
}
