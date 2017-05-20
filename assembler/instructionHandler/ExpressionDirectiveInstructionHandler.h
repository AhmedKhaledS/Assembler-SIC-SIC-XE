#ifndef EXPRESSIONDIRECTIVEINSTRUCTIONHANDLER_H
#define EXPRESSIONDIRECTIVEINSTRUCTIONHANDLER_H

#include "InstructionHandler.h"

class ExpressionDirectiveInstructionHandler : public InstructionHandler {
    public:
        ExpressionDirectiveInstructionHandler(std::string instruc, std::string oper);
        bool handle();
    protected:

    private:
        bool handleExpression();
        std::string operand;
};

#endif // EXPRESSIONDIRECTIVEINSTRUCTIONHANDLER_H
