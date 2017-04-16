#ifndef Included_OBJECTCODEGENERATOR_H
#define Included_OBJECTCODEGENERATOR_H

#include <iostream>

using namespace std;

class ObjectCodeGenerator {
    protected :
    string operand;
    string instruction;
    public :
    ObjectCodeGenerator();
    virtual string parse() = 0;
};

#endif
