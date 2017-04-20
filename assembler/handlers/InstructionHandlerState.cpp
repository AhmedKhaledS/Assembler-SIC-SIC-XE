#include "InstructionHandlerState.h"
#include "iostream"

using namespace std;

InstructionHandlerState::InstructionHandlerState(HandlerContext *context)
{
    this->context = context;
}

void InstructionHandlerState::handle(string statement)
{
    ///check valid instruction (opCode Table)

    ///check for label state

    ///location counter increment
        // if ( RESW RESB WORD BYTE )
            // Do nothing to the location counter increment
        //  else
            // Increment the location counter by 3

    //instruction = statement;

    /// this part for testing the operand..
    StateHandler::instruction = statement;

    /// If there are no errors .. upgrade the state.
    this->context->setState(context->getOperandHandler());
    //cout << "Currently: operand-handler-state" << endl;
}

void InstructionHandlerState::throwError()
{

}
