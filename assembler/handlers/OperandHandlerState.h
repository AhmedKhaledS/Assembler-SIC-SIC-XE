#ifndef OPERANDHANDLERSTATE_H
#define OPERANDHANDLERSTATE_H
#include "StateHandler.h"

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
