#ifndef OCGF_INCLUDED
#define OCGF_INCLUDED

#include <map>
#include "ObjectCodeGenerator.h"

class ObjectCodeGeneratorFactory {
    private :
    ObjectCodeGeneratorFactory();
    static ObjectCodeGeneratorFactory* objectCodeGeneratorFactoryInstance;

    public :

    ObjectCodeGeneratorFactory* getInstance();

    ObjectCodeGenerator* getObjectCodeGenerator(std::string type);
};

#endif // OCGF_INCLUDED
