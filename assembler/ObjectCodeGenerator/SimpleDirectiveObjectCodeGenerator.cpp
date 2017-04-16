#include "SimpleDirectiveObjectCodeGenerator.h"
#include "../tables/OperationCodeTable.h"

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

    // Grabbing object code in Binary...
    string binaryObjectCode;
    OperationCodeTable::load();
    binaryObjectCode = OperationCodeTable::getCode(instruction);

    // Converting object code to Hexadecimal
    bitset<8> set(binaryObjectCode);
    stringstream hexaObjectCode;
    hexaObjectCode << hex << uppercase << set.to_ulong();

    string objectCode = hexaObjectCode.str() += "0000";

    if(objectCode.size() != 6){
        objectCode = "0" + objectCode;
    }

    return objectCode;
 }
