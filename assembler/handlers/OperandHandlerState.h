#ifndef OPERANDHANDLERSTATE_H
#define OPERANDHANDLERSTATE_H
#include "StateHandler.h"
#include "HandlerContext.h"

class HandlerContext;

class OperandHandlerState: public StateHandler
{
    public:
        /** Default constructor */
        OperandHandlerState(HandlerContext *context);
        void handle(std::string statement);
        void throwError();
    private:
        HandlerContext *context;
};

#endif // OPERANDHANDLERSTATE_H
