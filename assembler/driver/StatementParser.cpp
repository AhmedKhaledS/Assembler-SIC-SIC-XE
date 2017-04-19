#include "StatementParser.h"
#include "../handlers/HandlerContext.h"

using namespace std;

StatementParser::StatementParser()
{

}

void StatementParser::parse(vector<string> statement)
{
    handlerContext = new HandlerContext();

    //TODO: Here goes catching statement for exceptions.
    handleLabel(statement.at(0));

    handleInstruction(statement.at(1));

    handleOperand(statement.at(2));

    // It's free of errors.
    return;
}

void StatementParser::handleLabel(string label)
{
    handlerContext->handle(label);
    // If reached here -> free of errors.
    return;
}

void StatementParser::handleInstruction(string instruction)
{
    handlerContext->handle(instruction);
    // If reached here ->free of errors.
    return;
}

void StatementParser::handleOperand(string operand)
{
    handlerContext->handle(operand);
    // If reached here ->free of errors.
    return;
}
