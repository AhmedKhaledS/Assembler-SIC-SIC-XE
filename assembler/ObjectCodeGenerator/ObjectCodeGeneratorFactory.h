#ifndef OCGF_INCLUDED
#define OCGF_INCLUDED

#include <map>
#include "ObjectCodeGenerator.h"
using namespace std;

class ObjectCodeGeneratorFactory {
    private :
    ObjectCodeGeneratorFactory();
    static ObjectCodeGeneratorFactory* objectCodeGeneratorFactoryInstance;

    public :

    static ObjectCodeGeneratorFactory* getInstance();

    ObjectCodeGenerator* getObjectCodeGenerator(string type, string instruction, string operand);
};

#endif // OCGF_INCLUDED
