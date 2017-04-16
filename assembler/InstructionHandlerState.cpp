#include "InstructionHandlerState.h"
#include "string"
#include "vector"

using namespace std;

InstructionHandlerState::InstructionHandlerState(HandlerContext *context)
{
    this->context = context;
}

void InstructionHandlerState::handle(vector<string> statement)
{

}

void InstructionHandlerState::throwError()
{

}
