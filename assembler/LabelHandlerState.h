#ifndef LABELHANDLERSTATE_H
#define LABELHANDLERSTATE_H
#include "vector"
#include "string"
#include "StateHandler.h"

class HandlerContext;

class LabelHandlerState: public StateHandler
{
    public:
        /** Default constructor */
        LabelHandlerState(HandlerContext *context);
        void handle(std::vector<std::string> statement);
        void throwError();
    private:
        HandlerContext *context;
};

#endif // LABELHANDLERSTATE_H
