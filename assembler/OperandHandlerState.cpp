#include "OperandHandlerState.h"
#include "string"
#include "vector"

using namespace std;

OperandHandlerState::OperandHandlerState(HandlerContext *context)
{
    this->context = context;
}

void OperandHandlerState::handle(vector<string> statement)
{

}

void OperandHandlerState::throwError()
{

}
