#include "LabelHandlerState.h"
#include "iostream"

using namespace std;

LabelHandlerState::LabelHandlerState(HandlerContext *context): context(context){}

bool checkLabelFormat(string label) {

    return false;
}

void LabelHandlerState::handle(string statement)
{
    ///check if it is not an instruction

    /// check for existence in SymTab
        // if exists throwError()
        // if not insert into symtab

    /// check label format
        // if not following the format throwError()
        // if following the format continue

    if (statement != "") {
        labelAvailable = false;
    } else {
        labelAvailable = true;
    }
    /// If there are no errors .. upgrade the state.
    this->context->setState(context->getInstructionHandler());
    cout << "Currently: instruction-handler-state" << endl;
}

void LabelHandlerState::throwError()
{

}
