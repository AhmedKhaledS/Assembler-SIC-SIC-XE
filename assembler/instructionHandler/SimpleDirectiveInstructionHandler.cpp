#include "SimpleDirectiveInstructionHandler.h"
#include <iostream>
#include "../logger/Logger.h"
#include "../logger/LoggerConstants.h"

using namespace std;


SimpleDirectiveInstructionHandler::SimpleDirectiveInstructionHandler(string inst)
{
    instruction = inst;
}

bool SimpleDirectiveInstructionHandler::handle(){
    if(instruction == "#"){
        return true;
    }
    Logger::log("ERROR: NON EMPTY", LoggerConstants::ERROR);
    return false;
}
