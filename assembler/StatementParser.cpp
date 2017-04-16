#include "StatementParser.h"
#include "HandlerContext.h"

using namespace std;

StatementParser::StatementParser()
{

}

void StatementParser::parse(vector<string> statement)
{
    HandlerContext handler;
    handlerContext = &handler;

    //TODO: Here goes catching statement for exceptions.
    handleLabel(statement.at(0));

    handleInstruction(statement.at(1));

    handleOperand(statement.at(2));

    // It's free of errors.
    return;
}

void StatementParser::handleLabel(string label)
{
    LabelHandlerState lHandle(handlerContext);
    lHandle.handle(label);
    // If reached here -> free of errors.
    return;
}

void StatementParser::handleInstruction(string instruction)
{
    InstructionHandlerState iHandle(handlerContext);
    iHandle.handle(instruction);
    // If reached here ->free of errors.
    return;
}

void StatementParser::handleOperand(string operand)
{
    OperandHandlerState oHandle(handlerContext);
    oHandle.handle(operand);
    // If reached here ->free of errors.
    return;
}
