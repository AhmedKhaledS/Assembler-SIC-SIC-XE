#include "LabelHandlerState.h"
#include "iostream"
#include "../tables/SymbolTable.h"
#include "../tables/InstructionTypeTable.h"
#include "../LocationCounter.h"
#include <string>
#include "../utils/LabelVerifier.h"

using namespace std;

LabelHandlerState::LabelHandlerState(HandlerContext *context): context(context){}


void LabelHandlerState::handle(string statement)
{
    // TO BE REMOVED
    cout << endl;
    cout << statement << endl;
    InstructionTypeTable::load();

    labelAvailable = false;

    //check if the label is an instruction
    if(!LabelVerifier::checkReservedWord(statement)){
        /// TO DO : Update the state to the Instruction State
        return;
    }

    // check the label format
    if(!LabelVerifier::checkNamingConvention(statement)){
        throwError();
    }

    // check for existence of the statement in Symbol Table
    if(!LabelVerifier::checkExistence(statement)){
        throwError();
    }
    else {
        /// TO DO : Add label Location Counter Value
        string currentAddres = "" + LocationCounter::getLocationCounter();
        SymbolTable::add(statement, currentAddres);
        labelAvailable = true;
    }

    cout << "Label Successfully Added" << endl;

    /// Finally, Update the state to the Instruction State
    //    this->context->setState(context->getInstructionHandler());
    //    cout << "Currently: instruction-handler-state" << endl;
}

void LabelHandlerState::throwError()
{
    throw "Error While Handling Label";
}
