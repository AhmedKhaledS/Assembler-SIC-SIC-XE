#include "HandlerContext.h"
#include "iostream"

using namespace std;

HandlerContext::HandlerContext()
{
    labelHandler = new LabelHandlerState(this);
    instHandler = new InstructionHandlerState(this);
    operHandler = new OperandHandlerState(this);
    currentState = getLabelHandler();
}

void HandlerContext::setState(StateHandler *newState)
{
    currentState = newState;
}
void HandlerContext::handle(string statement)
{
    // Delegates this action to state handler.
    currentState->handle(statement);
}
void HandlerContext::throwError(string message)
{

}

StateHandler* HandlerContext::getLabelHandler()
{
    //cout << "Currently: label-handler-state." << endl;
    return this->labelHandler;
}
StateHandler* HandlerContext::getInstructionHandler()
{
    return this->instHandler;
}
StateHandler* HandlerContext::getOperandHandler()
{
    return this->operHandler;
}
