#include "ExpressionUtils.h"

const char operatorKeys[] = "+-";
const int OPERATERS_SIZE = 2;

bool ExpressionUtils::isOperator(char c) {
    for (int i = 0; i < OPERATERS_SIZE; i++) {
        if (c == operatorKeys[i]) {return true;}
    }
    return false;
}
