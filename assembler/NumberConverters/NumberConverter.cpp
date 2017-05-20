#include "NumberConverter.h"
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

const int BASE_10 = 10;
const int BASE_16 = 16;
const char ZERO = '0';
const char A  = 'A';

string NumberConverter::convertBinToHex(string binNumber){

    bitset<8> set(binNumber);
    stringstream hexNumber;
    hexNumber << hex << uppercase << set.to_ulong();
    return hexNumber.str();

}

unsigned int NumberConverter::convertHexToDec(string hexNumber){
    unsigned int decNumber;
    stringstream stream;
    stream << hex << hexNumber;
    stream >> decNumber;
    return decNumber;
}

string NumberConverter::convertDecToHex(unsigned int decNumber){
    stringstream hexNumber;
    hexNumber << hex  << uppercase << decNumber;
    return hexNumber.str();
}

string NumberConverter::convertDecToHex(string decNumber){

    unsigned int decNumberValue;
    stringstream sstream(decNumber);
    sstream >> decNumberValue;

    stringstream hexNumber;
    hexNumber << hex  << uppercase << decNumberValue;
    return hexNumber.str();
}

int NumberConverter::getNumericValue(string number) {
    int obtainedNumber = 0;
    for (char digit : number) {
        obtainedNumber *= BASE_10;
        obtainedNumber += (digit - ZERO);
    }
    return obtainedNumber;
}

int NumberConverter::getHexadecimalValue(string hexadecimal) {
    int obtainedNumber = 0;
    for (char digit : hexadecimal) {
        obtainedNumber *= BASE_16;
        if (isalpha(digit)) {
            obtainedNumber += (digit - A);
        } else {
            obtainedNumber += (digit - ZERO);
        }
    }
    return obtainedNumber;
}

string NumberConverter::stringfy(int number) {
    stringstream ss;
    ss << number;
    string numberString = ss.str();
    return numberString;
}

bool NumberConverter::isNumber(string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
