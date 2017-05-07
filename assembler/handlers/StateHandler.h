#ifndef STATEHANDLER_H
#define STATEHANDLER_H
#include "string"

class StateHandler
{
    public:
        /** Default constructor */
        StateHandler();
        virtual void handle(std::string statement) = 0;
        virtual void throwError(std::string message) = 0;
    protected:
        static bool labelAvailable;
        static std::string instruction;
    private:
};

#endif // STATEHANDLER_H
