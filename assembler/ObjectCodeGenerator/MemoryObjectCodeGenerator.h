#ifndef MEMORYOBJECTCODEGENERATOR_H
#define MEMORYOBJECTCODEGENERATOR_H

#include "ObjectCodeGenerator.h"


class MemoryObjectCodeGenerator : public ObjectCodeGenerator
{
    public:
        MemoryObjectCodeGenerator(string instruction,string operand);
        string parse();
};

#endif // MEMORYOBJECTCODEGENERATOR_H
