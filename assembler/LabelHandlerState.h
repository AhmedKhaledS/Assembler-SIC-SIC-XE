#ifndef LABELHANDLERSTATE_H
#define LABELHANDLERSTATE_H
#include "StateHandler.h"

class HandlerContext;

class LabelHandlerState: public StateHandler
{
    public:
        /** Default constructor */
        LabelHandlerState(HandlerContext *context);
        void handle(std::string statement);
        void throwError();
    private:
        HandlerContext *context;
};

#endif // LABELHANDLERSTATE_H
