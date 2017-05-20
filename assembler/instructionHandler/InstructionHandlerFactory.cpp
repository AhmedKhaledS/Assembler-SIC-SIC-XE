#include "InstructionHandlerFactory.h"
#include "DirectiveInstructionHandler.h"
#include "MemoryInstructionHandler.h"
#include "SimpleDirectiveInstructionHandler.h"
#include "InstructionHandlerConstants.h"
#include "NonExistingInstructionHandler.h"
#include "ExpressionDirectiveInstructionHandler.h"

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
    (string type, string label ,string instruction, string operand) {
    InstructionHandler* ptr;
    if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_DIR) {
        ptr = new DirectiveInstructionHandler(instruction, operand);
    } else if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_MEMREG) {
        ptr = new MemoryInstructionHandler(operand);
    } else if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_OPER) {
        ptr = new SimpleDirectiveInstructionHandler(instruction);
    } else if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_DIREXP) {
        ptr = new ExpressionDirectiveInstructionHandler(label, instruction, operand);
    } else {
        ptr = new NonExistingInstructionHandler();
    }
    return ptr;
}
