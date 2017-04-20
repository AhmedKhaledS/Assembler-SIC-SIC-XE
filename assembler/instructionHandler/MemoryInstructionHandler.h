#ifndef MEMORYINSTRUCTIONHANDLER_H
#define MEMORYINSTRUCTIONHANDLER_H
#include "InstructionHandler.h"
#include <string>

class MemoryInstructionHandler : public InstructionHandler
{
    public:
        MemoryInstructionHandler(std::string instruction);
        bool handle();

    private:
        bool checkEmptyInstruction();
        bool checkFirstCharacter();
        bool checkIndexedAddressing();
        bool checkReservedWord();
        bool checkNamingConventions();
        bool handleStatement();

};

#endif // MEMORYINSTRUCTIONHANDLER_H
