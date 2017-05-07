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

const string OUT_OF_RANGE = "OUT OF RANGE ADDRESS";
const string LABEL_MISSING = "LABEL DOES NOT EXIST";
const int MAX_ADDRESS_SIZE = 4;

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

    if(addressCode == LABEL_MISSING){
       return LABEL_MISSING;
    }

    if(addressCode == OUT_OF_RANGE){
        return OUT_OF_RANGE;
    }

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
        return LABEL_MISSING;
    }

    string addressCode = SymbolTable::getAddress(operand);
    if(addressCode.size() > MAX_ADDRESS_SIZE){
        Logger::log("Address is out of range", LoggerConstants::ERROR);
        return OUT_OF_RANGE;
    }

    //cout << "Address Code: " << addressCode << endl;

    while(addressCode.size() != Constants::ADDRESS_CODE_SIZE){
        addressCode = Constants::ZERO + addressCode;
    }

    if(indexing){
        addressCode = indexingAddressing(addressCode);
    }
    return addressCode;
}
