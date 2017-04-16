#include "ObjectCodeGeneratorFactory.h"
#include "DirectiveObjectCodeGenerator.h"
using namespace std;


ObjectCodeGeneratorFactory::ObjectCodeGeneratorFactory() {

}

ObjectCodeGeneratorFactory*
    ObjectCodeGeneratorFactory::objectCodeGeneratorFactoryInstance = new ObjectCodeGeneratorFactory();

ObjectCodeGeneratorFactory* ObjectCodeGeneratorFactory::getInstance() {
    return ObjectCodeGeneratorFactory::objectCodeGeneratorFactoryInstance;
}

ObjectCodeGenerator* ObjectCodeGeneratorFactory::getObjectCodeGenerator(string type) {
    ObjectCodeGenerator* ptr;
    if (type == "dir") {
        ///TODO : provide proper argument to constructor
        DirectiveObjectCodeGenerator* generator = new DirectiveObjectCodeGenerator("", "");
        ptr = generator;
        return ptr;
    }
    // Here to insert the remaining if statements
    return ptr;
}
