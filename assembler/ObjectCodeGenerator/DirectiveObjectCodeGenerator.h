#ifndef DOCG_INCLUDED
#define DOCG_INCLUDED

#include <iostream>
#include "ObjectCodeGenerator.h"

using namespace std;

class DirectiveObjectCodeGenerator : public ObjectCodeGenerator {
    private :
        string handleWord();
        string handleByte();

    public :
        DirectiveObjectCodeGenerator(string oper, string inst);
        string parse();
};

#endif // DOCG_INCLUDED
