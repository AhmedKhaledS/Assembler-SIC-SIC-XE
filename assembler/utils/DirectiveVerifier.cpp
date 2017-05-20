#include "DirectiveVerifier.h"
#include "../ObjectCodeGenerator/Constants.h"
#include "NumberConverter.h"

using namespace std;

const int INT_LOW_ASCII = 48;
const int INT_HIGH_ASCII = 57;
const int ALPHA_LOW_ASCII = 65;
const int ALPHA_HIGH_ASCII = 70;
const int MAX_ALLOWED_HEX_LENGTH = 6;
const string FIXED_INCREMENT = "3";

bool DirectiveVerifier::checkString(string literal) {
    string op = literal;
    if (op[0] != Constants::CHAR_PREFIX) {
        return false;
    }
    if (op[1] != '\''  || op[op.length() - 1] != '\'') {
        return false;
    }
    // check for length of word
    if (op.length() - 3 > 3 || op.length() - 3 == 0) {
        return false;
    }
    string increment = NumberConverter::stringfy(op.length() - 3);
    return true;
}

bool checkHexadecimalDigitTest(char c) {
    int ascii_rep = c;
    return (ascii_rep >= INT_LOW_ASCII && ascii_rep <= INT_HIGH_ASCII)
     || (ascii_rep >= ALPHA_LOW_ASCII && ascii_rep <= ALPHA_HIGH_ASCII);
}

bool DirectiveVerifier::checkHexadecimal(string literal) {
    string op = literal;
    if (op[0] != Constants::HEX_PREFIX) {
        return false;
    }
    if (op[1] != '\''  || op[op.length() - 1] != '\'') {
        return false;
    }
    // check for length of word
    if (op.length() - 3 > 2 || (op.length() - 3) % 2 != 0) {
        return false;
    }
    for (unsigned int i = 2; i < op.length() - 1; i++) {
        if (!checkHexadecimalDigitTest(op[i])) {
            return false;
        }
    }
    string increment = NumberConverter::stringfy(((op.length() - 3) / 2));
    return true;
}

string DirectiveVerifier::handleByte(string literal) {
     string operand = literal;
     string objectCode;
     if (operand[0] == Constants::HEX_PREFIX) {
        objectCode = operand.substr(2, operand.length() - 3);
     } else if (operand[0] == Constants::CHAR_PREFIX) {
        for (int i = 2; i < operand.length() - 1; i++) {
            objectCode += NumberConverter::convertDecToHex(operand[i]);
        }
     }
     return objectCode;
}
