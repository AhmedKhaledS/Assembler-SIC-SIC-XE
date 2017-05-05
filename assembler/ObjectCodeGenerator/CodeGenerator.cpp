#include "CodeGenerator.h"
#include "../tables/InstructionTypeTable.h"
#include "ObjectCodeGenerator.h"
#include "ObjectCodeContainer.h"
#include "ObjectCodeGeneratorFactory.h"
#include <string>
#include <vector>

using namespace std;

CodeGenerator::CodeGenerator(vector<vector<string>> src)
{
    sourceCode = src;
}

void CodeGenerator::generateObjectCode() {
    for (vector<string> statement : sourceCode) {
        string instructionType = InstructionTypeTable::getType(statement[1]);
        ObjectCodeGenerator* generator = ObjectCodeGeneratorFactory::
        getInstance()->getObjectCodeGenerator(instructionType, statement[1], statement[2]);
        string objectCode = generator->parse();
        ObjectCodeContainer::addObjectCode(objectCode);
    }
    return;
}



