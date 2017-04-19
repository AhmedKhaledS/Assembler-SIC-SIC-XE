#include "MemoryInstructionHandler.h"
#include "../tables/OperationCodeTable.h"
#include <iostream>

using namespace std;

MemoryInstructionHandler::MemoryInstructionHandler(string inst)
{
    instruction = inst;
}

bool MemoryInstructionHandler::handle(){

    // TO BE REMOVE : FOR TESTING ONLY
    cout << instruction << endl;
    OperationCodeTable::load();

    // Check if the instruction is empty
    if(instruction == ""){
        cout << "ERROR: Empty Instruction" << endl;
        return false;
    }

    // Check if the instruction starts with an alphabet ...
    if (!isalpha(instruction[0])){
        cout << "Instruction can't start with this" << endl;
        return false;
    }

    // Check if ",X" exists zero or 1 one time only ...
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

    // Check if the instruction is a RESERVED WORD ...
    bool isResreved = OperationCodeTable::searchOperation(instruction);
    if(isResreved){
        cout << "ERROR: Reserved Word" << endl;
        return false;
    }

    // Check if the sequence of the instruction is okay ...
    for(int i=1;i<instruction.length()-1;i++){
        if(!isalpha(instruction[i]) && !isdigit(instruction[i])){
            cout << "Character at " << i << " is invalid" << endl;
            return false;
        }
    }

    cout << "CORRECT INSTRUCTION" << endl;
    return true;
}
