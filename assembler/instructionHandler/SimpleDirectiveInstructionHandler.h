#ifndef SIMPLEDIRECTIVEINSTRUCTIONHANDLER_H
#define SIMPLEDIRECTIVEINSTRUCTIONHANDLER_H
#include "InstructionHandler.h"
#include <string>

class SimpleDirectiveInstructionHandler : public InstructionHandler
{
    public:
        SimpleDirectiveInstructionHandler(std::string instruction);
        bool handle();
};

#endif // SIMPLEDIRECTIVEINSTRUCTIONHANDLER_H
