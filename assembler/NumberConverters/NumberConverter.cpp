#include "NumberConverter.h"
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

const int BASE_10 = 10;
const char ZERO = '0';

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
