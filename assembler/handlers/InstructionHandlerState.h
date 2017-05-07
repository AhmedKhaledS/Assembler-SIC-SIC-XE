#ifndef INSTRUCTIONHANDLERSTATE_H
#define INSTRUCTIONHANDLERSTATE_H
#include "StateHandler.h"
#include "HandlerContext.h"

class HandlerContext;

class InstructionHandlerState: public StateHandler
{
    public:
        /** Default constructor */
        InstructionHandlerState(HandlerContext *context);
        void handle(std::string statement);
        void throwError(std::string message);
    private:
        HandlerContext *context;
};

#endif // INSTRUCTIONHANDLERSTATE_H
