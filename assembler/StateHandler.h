#ifndef STATEHANDLER_H
#define STATEHANDLER_H
#include "string"
#include "vector"

class StateHandler
{
    public:
        /** Default constructor */
        StateHandler();
        virtual void handle(std::vector<std::string> statement) = 0;
        virtual void throwError() = 0;
    protected:

    private:
};

#endif // STATEHANDLER_H
