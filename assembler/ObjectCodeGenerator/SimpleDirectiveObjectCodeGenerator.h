#ifndef SIMPLEDIRECTIVEOBJECTCODEGENERATOR_H
#define SIMPLEDIRECTIVEOBJECTCODEGENERATOR_H

#include "ObjectCodeGenerator.h"


class SimpleDirectiveObjectCodeGenerator : public ObjectCodeGenerator
{
    public:
        SimpleDirectiveObjectCodeGenerator(string instruction);
        string parse();

};

#endif // SIMPLEDIRECTIVEOBJECTCODEGENERATOR_H
