#include "OperandHandlerState.h"
#include "../tables/InstructionTypeTable.h"
#include "../instructionHandler/InstructionHandlerFactory.h"
#include "iostream"

using namespace std;

OperandHandlerState::OperandHandlerState(HandlerContext *context)
{
    this->context = context;
}

void OperandHandlerState::handle(string statement)
{
    /// loading the proper type from the instruction table with the help of the static string
    string instructionType = InstructionTypeTable::getType(StateHandler::instruction);
    InstructionHandler* handler = InstructionHandlerFactory::
        getInstance()->getInstructionHandler(instructionType, StateHandler::instruction, statement);
    bool isHandled = handler->handle();
    if (!isHandled)
    {
        ///throw error;
    }
    /// If there are no errors .. upgrade the state.
    this->context->setState(nullptr);
    //cout << "Currently: null-state." << endl;
}

void OperandHandlerState::throwError()
{

}
