#include "HexadecimalConverter.h"
#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;

const int BASE_16 = 16;
const int BASE_10 = 10;
const int START_INDEX = 10;
const int END_INDEX = 15;
const int REGISTERED_ALPHABETS = 6;
const char _NULL = '\0';
const char ZERO = '0';

char HexadecimalConverter::hexAlphabet[REGISTERED_ALPHABETS] = {'A', 'B', 'C', 'D', 'E', 'F'};

char HexadecimalConverter::getChar(int n) {
    if (n > END_INDEX) {
        return _NULL;
    }
    if (n < START_INDEX) {
        return ZERO + n;
    }
    return hexAlphabet[n - START_INDEX];
}

int intLog(int base, int number) {
    return (int)round(log(number) / log(base));
}

int getNumericValue(string number) {
    int obtainedNumber = 0;
    for (char digit : number) {
        obtainedNumber *= BASE_10;
        obtainedNumber += (digit - ZERO);
    }
    return obtainedNumber;
}

string HexadecimalConverter::convertDecToHex(int number) {
    string convertedString;
    int upper = intLog(BASE_16, number);
    bool firstIteration = true;
    while (upper >= 0) {
        convertedString += getChar(number / pow(BASE_16, upper));
        if (firstIteration && convertedString[0] == '0') {
            convertedString.pop_back();
        }
        firstIteration = false;
        number  = number % (int) pow(BASE_16, upper);
        upper--;
    }
    return convertedString;
}

string HexadecimalConverter::convertDecToHex(string number) {
    string convertedString =
    HexadecimalConverter::convertDecToHex(getNumericValue(number));
    return convertedString;
}
