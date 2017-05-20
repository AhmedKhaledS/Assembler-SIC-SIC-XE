#ifndef NONEXISTINGOBJECTCODEGENERATOR_H
#define NONEXISTINGOBJECTCODEGENERATOR_H

#include "ObjectCodeGenerator.h"


class NonExistingObjectCodeGenerator : public ObjectCodeGenerator
{
    public:
        NonExistingObjectCodeGenerator();
        string parse();
};

#endif // NONEXISTINGOBJECTCODEGENERATOR_H
