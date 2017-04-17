#include "NumberConverter.h"
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

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

string NumberConverter::convertDexToHex(unsigned int decNumber){
    stringstream hexNumber;
    hexNumber << hex  << uppercase << decNumber;
    return hexNumber.str();
}
