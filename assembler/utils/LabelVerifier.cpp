#include "LabelVerifier.h"
#include "../tables/InstructionTypeTable.h"
#include "../tables/SymbolTable.h"
#include "Logger.h"
#include "NumberConverter.h"

using namespace std;

const string SPACE = " ";
const string OUT_OF_RANGE = "Out of memory range of SIC machine.";


bool LabelVerifier::checkReservedWord(string label) {
    /// Check if the instruction is a RESERVED WORD ...
    bool isResreved = InstructionTypeTable::searchOperation(label);
    if(isResreved) {
        return false;
    }
    return true;
}

string LabelVerifier::fillSpaces(string statemenComponent, int requiredSize) {
    if (statemenComponent == "#") {
        statemenComponent = "";
    }
    if (statemenComponent.length() > requiredSize) {
        return OUT_OF_RANGE;
    }
    int length = statemenComponent.length();
    for (int i = 0; i < requiredSize - length; i++) {
        statemenComponent += SPACE;
    }
    return statemenComponent;
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

