#include "MemoryInstructionHandler.h"
#include "../tables/InstructionTypeTable.h"
#include <iostream>
#include <../utils/LabelVerifier.h>
#include "../logger/Logger.h"
#include "../logger/LoggerConstants.h"

using namespace std;

MemoryInstructionHandler::MemoryInstructionHandler(string inst)
{
    instruction = inst;
}

bool MemoryInstructionHandler::checkEmptyInstruction() {
    // Check if the instruction is empty
    if(instruction == ""){
        Logger::log("Empty Instruction", LoggerConstants::ERROR);
        return false;
    }
    return true;
}

bool MemoryInstructionHandler::checkIndexedAddressing() {
    // Check if ",X" exists zero or 1 one time only in the correct position
    if(instruction.length() > 2){
        int check =  instruction.find(",X", 0, 2);
        if(check == instruction.length() - 2){
            instruction.replace(instruction.find(",X", 0, 2),2 ,"");
            Logger::log("INDEXING OK " + instruction, LoggerConstants::DEBUG);
        }else if(check > -1){
            Logger::log("INDEXING NOT OK", LoggerConstants::ERROR);
            return false;
        }
    }
    return true;
}

bool MemoryInstructionHandler::handleStatement() {
    return checkEmptyInstruction() && checkIndexedAddressing()
     && LabelVerifier::checkReservedWord(instruction)
     && LabelVerifier::checkNamingConvention(instruction);
}

bool MemoryInstructionHandler::handle() {

    // TO BE REMOVE : FOR TESTING ONLY
    //cout << instruction << endl;
    InstructionTypeTable::load();

    return handleStatement();
}
