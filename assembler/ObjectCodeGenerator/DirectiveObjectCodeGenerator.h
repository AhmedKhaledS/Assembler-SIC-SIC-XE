#ifndef DOCG_INCLUDED
#define DOCG_INCLUDED

#include <iostream>
#include "ObjectCodeGenerator.h"

using namespace std;

class DirectiveObjectCodeGenerator : public ObjectCodeGenerator {

public :
    DirectiveObjectCodeGenerator(string operand);
    string parse();
};

#endif // DOCG_INCLUDED
