#include "MemoryObjectCodeGenerator.h"
#include "../tables/OperationCodeTable.h"
#include "../tables/SymbolTable.h"
#include "Constants.h"
#include "../NumberConverters/NumberConverter.h"

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

    // Grabbing instruction object code in binary
    string binObjectCode;
    OperationCodeTable::load();                                 // TO BE REMOVED
    binObjectCode = OperationCodeTable::getCode(instruction);   // TO BE REMOVED

    // Converting object code to hexadecimal
    string objectCode = NumberConverter::convertBinToHex(binObjectCode);

    // Normalizing the first part object code form
    if(objectCode.size() != Constants::OP_CODE_SIZE){
        objectCode = Constants::ZERO + objectCode;
    }

    SymbolTable::add("BUFFER","1039");                         // TO BE REMOVED

    // Check Mode of addressing
    bool indexing;
    if(operand.find(Constants::INDEXING_PREFIX) != Constants::NOT_A_POSITION){
        operand.replace(operand.find(Constants::INDEXING_PREFIX), 2, "");
        indexing = true;
    }else{
        indexing = false;
    }

    string addressCode = SymbolTable::getAddress(operand);
    while(addressCode.size() != Constants::ADDRESS_CODE_SIZE){
        addressCode = Constants::ZERO + addressCode;
    }

    if(indexing){
        addressCode = indexingAddressing(addressCode);
    }

    objectCode += addressCode;
    return objectCode;

 }

string MemoryObjectCodeGenerator::indexingAddressing(string address){
    unsigned int addressCode = NumberConverter::convertHexToDec(address);
    addressCode += Constants::MAX_ADDRESS;
    return NumberConverter::convertDexToHex(addressCode);
}
