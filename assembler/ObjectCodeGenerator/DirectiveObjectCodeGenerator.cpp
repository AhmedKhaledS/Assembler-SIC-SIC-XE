#include "DirectiveObjectCodeGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include "../NumberConverters/HexadecimalConverter.h"
#include "Constants.h"

using namespace std;

DirectiveObjectCodeGenerator::DirectiveObjectCodeGenerator(string oper, string inst) {
    operand = oper;
    instruction = inst;
}


string DirectiveObjectCodeGenerator::handleWord() {
    string objectCode;
    if (operand[0] == Constants::HEX_PREFIX) {
        return operand.substr(2, operand.length() - 3);
    } else {
        return HexadecimalConverter::convertDecToHex(operand);
    }
    return objectCode;
}

string DirectiveObjectCodeGenerator::handleByte() {
     string objectCode;
     if (operand[0] == Constants::HEX_PREFIX) {
        return objectCode = operand.substr(2, operand.length() - 3);
     } else if (operand[0] == Constants::CHAR_PREFIX) {
        for (int i = 2; i < operand.length() - 1; i++) {
            objectCode += HexadecimalConverter::convertDecToHex(operand[i]);
        }
     }
     return objectCode;
}

string DirectiveObjectCodeGenerator::parse() {
    if (instruction == "word") {
        return handleWord();
    } else if (instruction == "byte") {
        return handleByte();
    }
    return "";
}
