#include "DirectiveInstructionHandler.h"
#include "../ObjectCodeGenerator/Constants.h"
#include "NumberConverter.h"
#include "../LocationCounter.h"
#include "../utils/LabelVerifier.h"
#include "../utils/SyntaxVerifier.h"

using namespace std;

const int INT_LOW_ASCII = 48;
const int INT_HIGH_ASCII = 57;
const int ALPHA_LOW_ASCII = 65;
const int ALPHA_HIGH_ASCII = 70;
const int MAX_ALLOWED_HEX_LENGTH = 6;
const string FIXED_INCREMENT = "3";


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
    string increment = NumberConverter::stringfy(((op.length() - 3) / 2));
    LocationCounter::increment(increment);
    return true;
}

bool checkDecimalInWord() {
    string op = DirectiveInstructionHandler::operand;
    int initial = 0;
    if (op[0] == '-') {
        initial = 1;
    }
    for (unsigned int i = 0 + initial; i < op.length(); i++) {
        if (!checkDecimalDigit(op[i])) {
            return false;
        }
    }
    if (NumberConverter::getNumericValue(op) >= Constants::MAX_NUMBER) {
        return false;
    }
    LocationCounter::increment(FIXED_INCREMENT);
    return true;
}

bool checkDecimalInReservation() {
    string op = DirectiveInstructionHandler::operand;
    for (unsigned int i = 0; i < op.length(); i++) {
        if (!checkDecimalDigit(op[i])) {
            return false;
        }
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
    string increment = NumberConverter::stringfy(op.length() - 3);
    LocationCounter::increment(increment);
    return true;
}

bool checkLabel() {

    bool labelcheck
    = LabelVerifier::checkReservedWord(DirectiveInstructionHandler::operand);
    labelcheck = labelcheck
    & LabelVerifier::checkNamingConvention(DirectiveInstructionHandler::operand);
    ///TODO : SET PROPER INCREMENT
    return labelcheck;
}

bool handleWord() {
    ///two cases 1) ---
    return checkDecimalInWord() || checkLabel();
}

bool handleByte() {
    ///two cases 1) C'---' 2) X'----x2'
    return checkString() || checkHexadecimal();
}

bool handleReserveWord() {
    /// RESW 1000
    //cout << "2. " + DirectiveInstructionHandler::operand << endl;
    bool checkOperand = checkDecimalInReservation();
    if (checkOperand) {
        int numberOfWords
        = NumberConverter::getNumericValue(DirectiveInstructionHandler::operand);
        numberOfWords *= Constants::WORD_SIZE;
        string increment = NumberConverter::convertDecToHex(numberOfWords);
        //cout << "3. Set increment by :" + increment << endl;
        LocationCounter::increment(increment);
    }
    return checkOperand;
}

bool handleReserveByte() {
    bool checkOperand = checkDecimalInReservation();
    if (checkOperand) {
        int numberOfWords
        = NumberConverter::getNumericValue(DirectiveInstructionHandler::operand);
        string increment = NumberConverter::convertDecToHex(numberOfWords);
        LocationCounter::increment(increment);
    }
    return checkOperand;
}

bool DirectiveInstructionHandler::handle() {
    ///check for all correct scenarios
    //cout << DirectiveInstructionHandler::operand << " ";
    if (instruction == Constants::WORD) {
        return handleWord();
    } else if (instruction == Constants::BYTE) {
        return handleByte();
    } else if (instruction == Constants::RESB) {
        return handleReserveByte();
    } else if (instruction == Constants::RESW) {
       // cout << "1. Incrementing RESW" << endl;
        return handleReserveWord();
    } else if (instruction == Constants::START) {
        LocationCounter::setLocationCounter(DirectiveInstructionHandler::operand);
        LocationCounter::increment(Constants::ZERO);
        SyntaxVerifier::setStartIncrement();
    } else if(instruction == Constants::END) {
        SyntaxVerifier::setEndIncrement();
        //LocationCounter::increment(FIXED_INCREMENT);
    }
    return false;
}
