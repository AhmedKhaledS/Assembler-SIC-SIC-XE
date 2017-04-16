#ifndef INSTRUCTIONHANDLERSTATE_H
#define INSTRUCTIONHANDLERSTATE_H
#include "vector"
#include "string"
#include "StateHandler.h"

class HandlerContext;

class InstructionHandlerState: public StateHandler
{
    public:
        /** Default constructor */
        InstructionHandlerState(HandlerContext *context);
        void handle(std::vector<std::string> statement);
        void throwError();
    private:
        HandlerContext *context;
};

#endif // INSTRUCTIONHANDLERSTATE_H
