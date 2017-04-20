#include "MemoryInstructionHandler.h"
#include "../tables/InstructionTypeTable.h"
#include <iostream>

using namespace std;

MemoryInstructionHandler::MemoryInstructionHandler(string inst)
{
    instruction = inst;
}

bool MemoryInstructionHandler::checkEmptyInstruction(){
    // Check if the instruction is empty
    if(instruction == ""){
        cout << "ERROR: Empty Instruction" << endl;
        return false;
    }
    return true;
}

bool MemoryInstructionHandler::checkFirstCharacter(){
    // Check if the instruction starts with an alphabet
    if (!isalpha(instruction[0])){
        cout << "Instruction can't start with this" << endl;
        return false;
    }
    return true;
}

bool MemoryInstructionHandler::checkIndexedAddressing(){
    // Check if ",X" exists zero or 1 one time only in the correct position
    if(instruction.length()>2){
        int check =  instruction.find(",X",0,2);
        if(check == instruction.length()-2){
            instruction.replace(instruction.find(",X",0,2), 2, "");
            cout << "INDEXING OK" << endl;
            cout << "NEW INSTRUCTION : " << instruction << endl;
        }else if(check > -1){
            cout << "ERROR: INDEXING NOT OK" << endl;
            return false;
        }
    }
    return true;
}

bool MemoryInstructionHandler::checkReservedWord(){
    // Check if the instruction is a RESERVED WORD ...
    bool isResreved = InstructionTypeTable::searchOperation(instruction);
    if(isResreved){
        cout << "ERROR: Reserved Word" << endl;
        return false;
    }
    return true;
}

bool MemoryInstructionHandler::checkNamingConventions(){
    // Check if the sequence of the instruction is okay ...
    for(int i=1;i<instruction.length();i++){
        if(!isalpha(instruction[i]) && !isdigit(instruction[i])){
            cout << "Character at " << i << " is invalid" << endl;
            return false;
        }
    }
    return true;
}

bool MemoryInstructionHandler::handleStatement(){
    return checkEmptyInstruction() && checkFirstCharacter() &&
           checkIndexedAddressing() && checkReservedWord() &&
           checkNamingConventions();
}

bool MemoryInstructionHandler::handle(){

    // TO BE REMOVE : FOR TESTING ONLY
    cout << instruction << endl;
    InstructionTypeTable::load();

    return handleStatement();
}
