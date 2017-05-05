#include "MemoryObjectCodeGenerator.h"
#include "../tables/OperationCodeTable.h"
#include "../tables/SymbolTable.h"
#include "Constants.h"
#include "../NumberConverters/NumberConverter.h"
#include "../logger/Logger.h"
#include "../logger/LoggerConstants.h"

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;

MemoryObjectCodeGenerator::MemoryObjectCodeGenerator(string inst,string oper)
{
    instruction = inst;
    operand = oper;
}

string MemoryObjectCodeGenerator::parse(){

    // TO BE REMOVE
    OperationCodeTable::load();

    string objectCode = parseInstruction(instruction);

    string addressCode = parseOperand(operand);

    objectCode += addressCode;

    return objectCode;

 }

string MemoryObjectCodeGenerator::indexingAddressing(string address){
    unsigned int addressCode = NumberConverter::convertHexToDec(address);
    addressCode += Constants::MAX_ADDRESS;
    return NumberConverter::convertDecToHex(addressCode);
}

string MemoryObjectCodeGenerator::parseInstruction(string instruction){

    // Grabbing instruction object code in binary
    string binInstructionCode;
    binInstructionCode = OperationCodeTable::getCode(instruction);

    // Converting object code to hexadecimal
    string instructionCode = NumberConverter::convertBinToHex(binInstructionCode);

    // Normalizing the first part object code form
    if(instructionCode.size() != Constants::OP_CODE_SIZE){
        instructionCode = Constants::ZERO + instructionCode;
    }
    return instructionCode;
}

string MemoryObjectCodeGenerator::parseOperand(string operand){

    // Check Mode of addressing
    bool indexing;
    if(operand.find(Constants::INDEXING_PREFIX) != Constants::NOT_A_POSITION){
        operand.replace(operand.find(Constants::INDEXING_PREFIX), 2, "");
        indexing = true;
    }else{
        indexing = false;
    }

    // Check if the operand available
    if(!SymbolTable::searchSymbol(operand)){
        Logger::log("Operand label does not exist", LoggerConstants::ERROR);
        return "";
    }

    string addressCode = SymbolTable::getAddress(operand);
    //cout << "Address Code: " << addressCode << endl;

    while(addressCode.size() != Constants::ADDRESS_CODE_SIZE){
        addressCode = Constants::ZERO + addressCode;
    }

    if(indexing){
        addressCode = indexingAddressing(addressCode);
    }
    return addressCode;
}
