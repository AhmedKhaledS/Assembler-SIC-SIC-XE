#include "LabelHandlerState.h"
#include "iostream"
#include "../tables/SymbolTable.h"
#include "../tables/InstructionTypeTable.h"
#include "../LocationCounter.h"

using namespace std;

LabelHandlerState::LabelHandlerState(HandlerContext *context): context(context){}

bool LabelHandlerState::checkReservedWord(string label){
    /// Check if the instruction is a RESERVED WORD ...
    bool isResreved = InstructionTypeTable::searchOperation(label);
    if(isResreved){
        cout << "State will be moved to Instruction Handle State" << endl;
        return false;
    }
    return true;
}

bool LabelHandlerState::checkExistence(string label){
    /// Check if the label previously exist in the symbol Table...
    bool exist = SymbolTable::searchSymbol(label);
    if(exist){
        cout << "ERROR: Symbol already exists" << endl;
        return false;
    }
    return true;
}

bool LabelHandlerState::checkNamingConvention(string label){

    if (!isalpha(label[0])){
        cout << "Label can't start with this" << endl;
        return false;
    }

    for(int i=1;i<label.length();i++){
        if(!isalpha(label[i]) && !isdigit(label[i])){
            cout << "Character at " << i << " is invalid" << endl;
            return false;
        }
    }
    return true;
}

void LabelHandlerState::handle(string statement)
{
    // TO BE REMOVED
    cout << endl;
    cout << statement << endl;
    InstructionTypeTable::load();

    labelAvailable = false;

    //check if the label is an instruction
    if(!checkReservedWord(statement)){
        /// TO DO : Update the state to the Instruction State
        return;
    }

    // check the label format
    if(!checkNamingConvention(statement)){
        return;
    }

    // check for existence of the statement in Symbol Table
    if(!checkExistence(statement)){
        return;
    }
    else {
        SymbolTable::add(statement,"0000");
        labelAvailable = true;
    }

    //    if (statement != "") {
    //        labelAvailable = false;
    //    } else {
    //        labelAvailable = true;
    //    }

    cout << "Label Successfully Added" << endl;

    /// Finally, Update the state to the Instruction State
    //    this->context->setState(context->getInstructionHandler());
    //    cout << "Currently: instruction-handler-state" << endl;
}

void LabelHandlerState::throwError()
{

}
