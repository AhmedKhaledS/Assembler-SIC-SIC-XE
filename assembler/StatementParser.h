#ifndef STATEMENTPARSER_H
#define STATEMENTPARSER_H
#include "LabelHandlerState.h"
#include "InstructionHandlerState.h"
#include "OperandHandlerState.h"
#include "vector"
#include "string"


class StatementParser
{
    public:
        /** Default constructor */
        StatementParser();
        void parse(std::vector<std::string> statement);
    private:
        LabelHandlerState *labelhandler;
        InstructionHandlerState *insthandler;
        OperandHandlerState *operhandler;
};

#endif // STATEMENTPARSER_H
