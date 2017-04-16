#ifndef STATEHANDLER_H
#define STATEHANDLER_H
#include "string"

class StateHandler
{
    public:
        /** Default constructor */
        StateHandler();
        virtual void handle(std::string statement) = 0;
        virtual void throwError() = 0;
    protected:

    private:
};

#endif // STATEHANDLER_H
