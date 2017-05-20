#include "ExpressionDirectiveInstructionHandler.h"
#include "../ObjectCodeGenerator/Constants.h"
#include <cstring>
#include "../tables/SymbolTable.h"
#include "ExpressionEvaluator.h"
#include "NumberConverter.h"
#include "../LocationCounter.h"

using namespace std;

const char operatorKeys[] = "+-";

ExpressionDirectiveInstructionHandler::ExpressionDirectiveInstructionHandler(string instruc, string oper)
{
    instruction = instruc;
    operand = oper;
}

bool validateSyntax() {
    /// check valid forms
        // LABEL +/- LABEL
        // NUM +/- LABEL
        // NUM +/- NUM
    return false;
}
/**
    tries to parse the operand as both label and number
    @param operand the operand to be checked
    @return boolean indicating the validity of the operand
    and int denoting the value of operand if parsing was
    successful ,-1 otherwise.
*/
pair<bool, int> tryParsingOperand(string operand) {
    int operandValue;
    if (NumberConverter::isNumber(operand)) {
        operandValue = NumberConverter::getNumericValue(operand);
    } else {
        if (!SymbolTable::searchSymbol(operand)) {
            return {false, -1};
        }
        operandValue = NumberConverter::convertHexToDec(SymbolTable::getAddress(operand));
    }
    return {true, operandValue};
}

bool ExpressionDirectiveInstructionHandler::handleExpression() {
    int operatorIndex = strcspn(operand.c_str(),operatorKeys);
    string firstOperand = operand.substr(0, operatorIndex);
    string secondOperand = operand.substr(operatorIndex + 1, operand.length() - operatorIndex);
    pair<bool, int> firstOperandParsingResult = tryParsingOperand(firstOperand);
    pair<bool, int> secondOperandParsingResult = tryParsingOperand(secondOperand);
    if (!firstOperandParsingResult.first) {return false;}
    if (!secondOperandParsingResult.first) {return false;}
    string parsedExpression = NumberConverter::stringfy(firstOperandParsingResult.second)
     + operand[operatorIndex] + NumberConverter::stringfy(secondOperandParsingResult.second);
    int operandValue = ExpressionEvaluator::evaluate(parsedExpression);
    LocationCounter::setLocationCounter(NumberConverter::convertDecToHex(NumberConverter::stringfy(operandValue)));
    return true;
}


bool ExpressionDirectiveInstructionHandler::handle() {
    if (instruction == Constants::ORG) {
        return handleExpression();
    } else if (instruction == Constants::EQU) {

    }
    return false;
}
