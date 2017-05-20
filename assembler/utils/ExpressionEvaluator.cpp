#include "ExpressionEvaluator.h"
#include "NumberConverter.h"
#include <cstring>
#include <vector>

using namespace std;

const char operatorKeys[] = "+-";
const int OPERATERS_SIZE = 2;



int ExpressionEvaluator::evaluate(string expression) {
    vector<string> operandsList;
    vector<char> operatorsList;
    string curOperand = "";
    for (int i = 0; i < expression.length(); i++) {
        if (!isOperator(expression[i])) {
            curOperand.push_back(expression[i]);
        }
        else {
            operandsList.push_back(curOperand);
            curOperand = "";
            operatorsList.push_back(expression[i]);
        }
    }
    if (curOperand.length() != 0) {
        operandsList.push_back(curOperand);
    }
    int expressionValue = 0;
    int factor = 1;
    for (int i = 0; i < operandsList.size(); i++) {
        int curOperandValue = NumberConverter::getNumericValue(operandsList[i]);
        expressionValue += curOperandValue * factor;
        if (i != operandsList.size() - 1) {
            switch (expression[i]) {
            case '+' :
                factor = 1;
                break;
            case '-' :
                factor = -1;
                break;
            }
        }
    }
    return expressionValue;
}
