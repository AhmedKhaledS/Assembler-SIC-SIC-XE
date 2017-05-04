#include "LabelVerifier.h"
#include "../tables/InstructionTypeTable.h"
#include "../tables/SymbolTable.h"

using namespace std;

bool LabelVerifier::checkReservedWord(string label) {
    /// Check if the instruction is a RESERVED WORD ...
    bool isResreved = InstructionTypeTable::searchOperation(label);
    if(isResreved) {
        cout << "State will be moved to Instruction Handle State" << endl;
        return false;
    }
    return true;
}

bool LabelVerifier::checkExistence(string label) {
    /// Check if the label previously exist in the symbol Table...
    bool exist = SymbolTable::searchSymbol(label);
    if(exist){
        cout << "ERROR: Symbol already exists" << endl;
        return false;
    }
    return true;
}

bool LabelVerifier::checkNamingConvention(string label) {

    if (!isalpha(label[0])) {
        cout << "Label can't start with this" << endl;
        return false;
    }

    for(int i = 1; i<label.length(); i++){
        if(!isalpha(label[i]) && !isdigit(label[i])) {
            cout << label << " : Character at " << i << " is invalid" << endl;
            return false;
        }
    }
    return true;
}

