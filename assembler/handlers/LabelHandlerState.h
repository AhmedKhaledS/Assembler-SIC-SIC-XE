#ifndef LABELHANDLERSTATE_H
#define LABELHANDLERSTATE_H
#include "StateHandler.h"
#include "HandlerContext.h"

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
        bool checkReservedWord(std::string label);
        bool checkExistence(std::string label);
        bool checkNamingConvention(std::string label);
};

#endif // LABELHANDLERSTATE_H
