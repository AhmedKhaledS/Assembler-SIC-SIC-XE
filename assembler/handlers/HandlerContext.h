#ifndef HANDLERCONTEXT_H
#define HANDLERCONTEXT_H
#include "LabelHandlerState.h"
#include "InstructionHandlerState.h"
#include "OperandHandlerState.h"

/** Forward declarations are to be detected by the compiler. */
class LabelHandlerState;
class InstructionHandlerState;
class OperandHandlerState;

class HandlerContext
{
    public:
        /** Default constructor */
        HandlerContext();
        void setState(StateHandler *newState);
        void handle(std::string statement);
        void throwError(std::string message);
        StateHandler *getLabelHandler();
        StateHandler *getInstructionHandler();
        StateHandler *getOperandHandler();
    private:
        StateHandler *currentState;
        LabelHandlerState *labelHandler;
        InstructionHandlerState *instHandler;
        OperandHandlerState *operHandler;
};

#endif // HANDLERCONTEXT_H
