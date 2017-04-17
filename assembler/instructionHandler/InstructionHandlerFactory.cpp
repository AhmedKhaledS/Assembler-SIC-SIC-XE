#include "InstructionHandlerFactory.h"
using namespace std;

InstructionHandlerFactory::InstructionHandlerFactory()
{

}

InstructionHandlerFactory*
    InstructionHandlerFactory::instructionHandlerFactoryInstance = new InstructionHandlerFactory();

InstructionHandlerFactory* InstructionHandlerFactory::getInstance() {
    return InstructionHandlerFactory::instructionHandlerFactoryInstance;
}

InstructionHandler* InstructionHandlerFactory::getInstructionHandler(string type) {
    InstructionHandler* ptr;
    return ptr;
}
