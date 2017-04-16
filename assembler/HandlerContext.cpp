#include "HandlerContext.h"

HandlerContext::HandlerContext()
{
    LabelHandlerState lHandler(this);

    InstructionHandlerState iHandler(this);

    OperandHandlerState oHandler(this);

    labelHandler = &lHandler;
    instHandler = &iHandler;
    operHandler = &oHandler;
}

void HandlerContext::setState(StateHandler *newState)
{
    currentState = newState;
}

