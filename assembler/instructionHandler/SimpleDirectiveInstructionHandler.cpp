#include "SimpleDirectiveInstructionHandler.h"
#include <iostream>
#include "Logger.h"
#include "LoggerConstants.h"

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
