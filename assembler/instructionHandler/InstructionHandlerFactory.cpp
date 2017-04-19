#include "InstructionHandlerFactory.h"
#include "DirectiveInstructionHandler.h"
#include "MemoryInstructionHandler.h"
#include "SimpleDirectiveInstructionHandler.h"

using namespace std;

InstructionHandlerFactory::InstructionHandlerFactory()
{

}

InstructionHandlerFactory*
    InstructionHandlerFactory::instructionHandlerFactoryInstance = new InstructionHandlerFactory();

InstructionHandlerFactory* InstructionHandlerFactory::getInstance() {
    return InstructionHandlerFactory::instructionHandlerFactoryInstance;
}

InstructionHandler* InstructionHandlerFactory::getInstructionHandler
    (string type, string instruction, string operand) {
    InstructionHandler* ptr;
    if (type == "dir") {
        ptr = new DirectiveInstructionHandler(instruction, operand);
    } else if (type == "mem_reg") {
        ptr = new MemoryInstructionHandler(instruction);
    } else if (type == "oper") {
        ptr = new SimpleDirectiveInstructionHandler(instruction);
    }
    return ptr;
}
