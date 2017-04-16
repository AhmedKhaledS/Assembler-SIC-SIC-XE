#ifndef STATEMENTPARSER_H
#define STATEMENTPARSER_H
#include "../handlers/HandlerContext.h"
#include "../handlers/InstructionHandlerState.h"
#include "../handlers/OperandHandlerState.h"
#include "vector"
#include "string"

class StatementParser
{
    public:
        /** Default constructor */
        StatementParser();
        // TODO .. throwing exception for each function.
        void parse(std::vector<std::string> statement);
    private:
        HandlerContext *handlerContext;
        LabelHandlerState *labelhandler;
        InstructionHandlerState *insthandler;
        OperandHandlerState *operhandler;
        void handleLabel(std::string label);
        void handleInstruction(std::string instruction);
        void handleOperand(std::string operand);
};

#endif // STATEMENTPARSER_H
