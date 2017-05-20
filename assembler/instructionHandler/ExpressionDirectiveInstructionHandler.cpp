#include "ExpressionDirectiveInstructionHandler.h"
#include "../ObjectCodeGenerator/Constants.h"
#include <cstring>
#include "../tables/SymbolTable.h"
#include "expressions.handler/ExpressionEvaluator.h"
#include "NumberConverter.h"
#include "../LocationCounter.h"
#include "expressions.handler/ExpressionUtils.h"

using namespace std;

ExpressionDirectiveInstructionHandler::ExpressionDirectiveInstructionHandler(string lbl, string instruc, string oper)
{
    label = lbl;
    instruction = instruc;
    operand = oper;
}



bool validateSyntax(string expression) {
    /// check valid forms
        // LABEL +/- LABEL
        // NUM +/- LABEL
        // NUM +/- NUM
    for (int i = 0; i < expression.length(); i++) {

    }
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
    vector<string> operandsList;
    vector<char> operatorsList;
    string curOperand = "";
    for (int i = 0; i < operand.length(); i++) {
        if (!ExpressionUtils::isOperator(operand[i])) {
            curOperand.push_back(operand[i]);
        }
        else {
            operandsList.push_back(curOperand);
            curOperand = "";
            operatorsList.push_back(operand[i]);
        }
    }
    if (curOperand.length() != 0) {
        operandsList.push_back(curOperand);
    }
    if (operandsList.size() - 1 != operatorsList.size()) {
        return false;
    }

    string parsedExpression = "";
    for (int i = 0; i < operandsList.size(); i++) {
        pair<bool, int> operandParseResult = tryParsingOperand(operandsList[i]);
        if (!operandParseResult.first) {return false;}
        parsedExpression += NumberConverter::stringfy(operandParseResult.second);
        if (i != operandsList.size() - 1) {parsedExpression.push_back(operatorsList[i]);}
    }
    int operandValue = ExpressionEvaluator::evaluate(parsedExpression);
    cout << operandValue;
    LocationCounter::setLocationCounter(NumberConverter::convertDecToHex(NumberConverter::stringfy(operandValue)));
    return true;
}


bool ExpressionDirectiveInstructionHandler::handle() {
    if (instruction == Constants::ORG) {
        return handleExpression();
    } else if (instruction == Constants::EQU) {
        return handleExpression();
    }
    return false;
}
