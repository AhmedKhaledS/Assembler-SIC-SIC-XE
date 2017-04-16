#ifndef OPERANDHANDLERSTATE_H
#define OPERANDHANDLERSTATE_H
#include "vector"
#include "string"
#include "StateHandler.h"

class HandlerContext;

class OperandHandlerState: public StateHandler
{
    public:
        /** Default constructor */
        OperandHandlerState(HandlerContext *context);
        void handle(std::vector<std::string> statement);
        void throwError();
    private:
        HandlerContext *context;
};

#endif // OPERANDHANDLERSTATE_H
