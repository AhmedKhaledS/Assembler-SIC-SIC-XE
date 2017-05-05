#ifndef DOCG_INCLUDED
#define DOCG_INCLUDED

#include "ObjectCodeGenerator.h"

class DirectiveObjectCodeGenerator : public ObjectCodeGenerator {
    private :
        string handleWord();
        string handleByte();
        bool requiresNoObjectCode();

    public :
        DirectiveObjectCodeGenerator(string oper, string inst);
        string parse();
};

#endif // DOCG_INCLUDED
