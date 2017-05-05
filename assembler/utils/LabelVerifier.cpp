#include "LabelVerifier.h"
#include "../tables/InstructionTypeTable.h"
#include "../tables/SymbolTable.h"
#include "../logger/Logger.h"
#include "NumberConverter.h"

using namespace std;

bool LabelVerifier::checkReservedWord(string label) {
    /// Check if the instruction is a RESERVED WORD ...
    bool isResreved = InstructionTypeTable::searchOperation(label);
    if(isResreved) {
        return false;
    }
    return true;
}

bool LabelVerifier::checkExistence(string label) {
    /// Check if the label previously exist in the symbol Table...
    bool exist = SymbolTable::searchSymbol(label);
    if(exist){
        Logger::log("Symbol already exists", "ERROR");
        return false;
    }
    return true;
}

bool LabelVerifier::checkNamingConvention(string label) {

    if (!isalpha(label[0])) {
        Logger::log("Label can't start with this", "ERROR");
        return false;
    }

    for(int i = 1; i<label.length(); i++){
        if(!isalpha(label[i]) && !isdigit(label[i])) {
            string iString  = NumberConverter::stringfy(i);
            Logger::log(label + " : Character at " + iString + " is invalid", "ERROR");
            return false;
        }
    }
    return true;
}

