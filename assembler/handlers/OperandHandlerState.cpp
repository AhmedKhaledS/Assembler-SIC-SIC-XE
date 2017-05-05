#include "OperandHandlerState.h"
#include "../tables/InstructionTypeTable.h"
#include "../instructionHandler/InstructionHandlerFactory.h"
#include "iostream"
#include "../LocationCounter.h"
#include "NumberConverter.h"
#include "../ObjectCodeGenerator/Constants.h"

using namespace std;

OperandHandlerState::OperandHandlerState(HandlerContext *context)
{
    this->context = context;
}

void OperandHandlerState::handle(string statement)
{
    if (statement == "#") {
        return;
    }
    if (StateHandler::instruction == "x'05'") {
        int debug = -1;
    }
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
