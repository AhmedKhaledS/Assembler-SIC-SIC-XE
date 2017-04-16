#ifndef DOCG_INCLUDED
#define DOCG_INCLUDED

#include <iostream>
#include "ObjectCodeGenerator.h"

class DirectiveObjectCodeGenerator : public ObjectCodeGenerator {

public :
    DirectiveObjectCodeGenerator(std::string operand);
    std::string parse();
};

#endif // DOCG_INCLUDED
