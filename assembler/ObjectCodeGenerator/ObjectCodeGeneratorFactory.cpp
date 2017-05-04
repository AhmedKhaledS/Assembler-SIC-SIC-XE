#include "ObjectCodeGeneratorFactory.h"
#include "DirectiveObjectCodeGenerator.h"
#include "MemoryObjectCodeGenerator.h"
#include "SimpleDirectiveObjectCodeGenerator.h"
#include "InstructionHandlerConstants.h"

using namespace std;


ObjectCodeGeneratorFactory::ObjectCodeGeneratorFactory() {

}

ObjectCodeGeneratorFactory*
    ObjectCodeGeneratorFactory::objectCodeGeneratorFactoryInstance = new ObjectCodeGeneratorFactory();

ObjectCodeGeneratorFactory* ObjectCodeGeneratorFactory::getInstance() {
    return ObjectCodeGeneratorFactory::objectCodeGeneratorFactoryInstance;
}

ObjectCodeGenerator* ObjectCodeGeneratorFactory::getObjectCodeGenerator
        (string type, string instruction, string operand) {
    ObjectCodeGenerator* ptr;
    if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_DIR) {
        ptr = new DirectiveObjectCodeGenerator(operand, instruction);
        return ptr;
    } else if (type  == InstructionHandlerConstants::INSTRUCTION_TYPE_MEMREG) {
        ptr = new MemoryObjectCodeGenerator(instruction, operand);
        return ptr;
    } else if(type == InstructionHandlerConstants::INSTRUCTION_TYPE_OPER) {
        ptr = new SimpleDirectiveObjectCodeGenerator(instruction);
        return ptr;
    }
    return ptr;
}
