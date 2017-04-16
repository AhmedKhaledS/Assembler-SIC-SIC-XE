#ifndef Included_OBJECTCODEGENERATOR_H
#define Included_OBJECTCODEGENERATOR_H

#include <iostream>

class ObjectCodeGenerator {
    protected :
    std::string operand;
    std::string instruction;
    public :
    ObjectCodeGenerator();
    virtual std::string parse() = 0;
};

#endif
