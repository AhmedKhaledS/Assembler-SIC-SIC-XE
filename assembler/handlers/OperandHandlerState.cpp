#include "OperandHandlerState.h"
#include "iostream"

using namespace std;

OperandHandlerState::OperandHandlerState(HandlerContext *context)
{
    this->context = context;
}

void OperandHandlerState::handle(string statement)
{

    /// If there are no errors .. upgrade the state.
    this->context->setState(nullptr);
    cout << "Currently: null-state." << endl;
}

void OperandHandlerState::throwError()
{

}
