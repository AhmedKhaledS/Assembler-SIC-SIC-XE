#ifndef INSTRUCTIONHANDLERFACTORY_H
#define INSTRUCTIONHANDLERFACTORY_H
#include <InstructionHandler.h>
#include <string>

class InstructionHandlerFactory
{
    private:
        InstructionHandlerFactory();
        static InstructionHandlerFactory* instructionHandlerFactoryInstance;

    public:
        InstructionHandlerFactory* getInstance();
        InstructionHandler* getInstructionHandler(std::string type, std::string instruction, std::string operand);

};

#endif // INSTRUCTIONHANDLERFACTORY_H
