#include "SimpleDirectiveObjectCodeGenerator.h"
#include "../tables/OperationCodeTable.h"
#include "Constants.h"
#include "../NumberConverters/NumberConverter.h"

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;

SimpleDirectiveObjectCodeGenerator::SimpleDirectiveObjectCodeGenerator(string inst)
{
    instruction = inst;
}

 string SimpleDirectiveObjectCodeGenerator::parse(){

    // Grabbing instruction object code in binary
    string binObjectCode;
    OperationCodeTable::load();                                 // TO BE REMOVED
    binObjectCode = OperationCodeTable::getCode(instruction);   // TO BE REMOVED

    // Converting object code to hexadecimal
    string objectCode = NumberConverter::convertBinToHex(binObjectCode);

    // Normalizing the object code form
    objectCode += Constants::ZEROS;

    if(objectCode.size() != Constants::OBJECT_CODE_SIZE){
        objectCode = Constants::ZERO + objectCode;
    }

    return objectCode;
 }
