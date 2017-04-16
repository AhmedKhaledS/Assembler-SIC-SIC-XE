#ifndef HANDLERCONTEXT_H
#define HANDLERCONTEXT_H
#include "LabelHandlerState.h"
#include "InstructionHandlerState.h"
#include "OperandHandlerState.h"


class HandlerContext
{
    public:
        /** Default constructor */
        HandlerContext();
        void setState(StateHandler *newState);
    private:
        StateHandler *currentState;
        LabelHandlerState *labelHandler;
        InstructionHandlerState *instHandler;
        OperandHandlerState *operHandler;
};

#endif // HANDLERCONTEXT_H
