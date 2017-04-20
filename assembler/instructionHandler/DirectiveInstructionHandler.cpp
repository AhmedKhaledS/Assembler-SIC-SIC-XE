#include "DirectiveInstructionHandler.h"
#include "../ObjectCodeGenerator/Constants.h"
#include "NumberConverter.h"
using namespace std;

const int INT_LOW_ASCII = 48;
const int INT_HIGH_ASCII = 57;
const int ALPHA_LOW_ASCII = 65;
const int ALPHA_HIGH_ASCII = 70;

string DirectiveInstructionHandler::operand;

DirectiveInstructionHandler::DirectiveInstructionHandler(string instruc, string oper) {
    instruction = instruc;
    operand = oper;
}

bool checkDecimalDigit(char c) {
    return (c >= INT_LOW_ASCII && c <= INT_HIGH_ASCII);
}

bool checkHexadecimalDigit(char c) {
    int ascii_rep = c;
    return (ascii_rep >= INT_LOW_ASCII && ascii_rep <= INT_HIGH_ASCII)
     || (ascii_rep >= ALPHA_LOW_ASCII && ascii_rep <= ALPHA_HIGH_ASCII);
}

bool checkHexadecimal() {
    string op = DirectiveInstructionHandler::operand;
    if (op[0] != Constants::HEX_PREFIX) {
        return false;
    }
    if (op[1] != '\''  || op[op.length() - 1] != '\'') {
        return false;
    }
    ///check for length of word
    if (op.length() - 3 > 2 || (op.length() - 3) % 2 != 0) {
        return false;
    }
    for (unsigned int i = 2; i < op.length() - 1; i++) {
        if (!checkHexadecimalDigit(op[i])) {
            return false;
        }
    }
    return true;
}

bool checkDecimal() {
    string op = DirectiveInstructionHandler::operand;
    for (unsigned int i = 0; i < op.length(); i++) {
        if (!checkDecimalDigit(op[i])) {
            return false;
        }
    }
    if (NumberConverter::getNumericValue(op) >= Constants::MAX_NUMBER) {
        return false;
    }
    return true;
}

bool checkString() {
    string op = DirectiveInstructionHandler::operand;
    if (op[0] != Constants::CHAR_PREFIX) {
        return false;
    }
    if (op[1] != '\''  || op[op.length() - 1] != '\'') {
        return false;
    }
    ///check for length of word
    if (op.length() - 3 > 3 || op.length() - 3 == 0) {
        return false;
    }
    return true;
}

bool handleWord() {
    ///two cases 1) ---       2) X'---'
    return checkDecimal() || checkHexadecimal();
}

bool handleByte() {
    ///two cases 1) C'---' 2) X'--'
    return checkString() || checkHexadecimal();
}

bool DirectiveInstructionHandler::handle() {
    ///check for all correct scenarios
    if (instruction == "word") {
        return handleWord();
    } else if (instruction == "byte") {
        return handleByte();
    }
    return false;
}
