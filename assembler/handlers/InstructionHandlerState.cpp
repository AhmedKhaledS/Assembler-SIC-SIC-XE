#include "InstructionHandlerState.h"
#include "iostream"

using namespace std;

InstructionHandlerState::InstructionHandlerState(HandlerContext *context)
{
    this->context = context;
}

void InstructionHandlerState::handle(string statement)
{


    /// If there are no errors .. upgrade the state.
    this->context->setState(context->getOperandHandler());
    cout << "Currently: operand-handler-state" << endl;
}

void InstructionHandlerState::throwError()
{

}
