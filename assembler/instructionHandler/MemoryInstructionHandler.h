#ifndef MEMORYINSTRUCTIONHANDLER_H
#define MEMORYINSTRUCTIONHANDLER_H
#include "InstructionHandler.h"
#include <string>

class MemoryInstructionHandler : public InstructionHandler
{
    public:
        MemoryInstructionHandler(std::string instruction);
        bool handle();

};

#endif // MEMORYINSTRUCTIONHANDLER_H
