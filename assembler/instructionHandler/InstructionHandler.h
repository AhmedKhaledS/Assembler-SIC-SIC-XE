#ifndef INSTRUCTIONHANDLER_H
#define INSTRUCTIONHANDLER_H
#include <string>


class InstructionHandler
{
    public:
        InstructionHandler();
        virtual bool handle() = 0;

    protected:
        std::string instruction;
};

#endif // INSTRUCTIONHANDLER_H
