#ifndef NUMBERCONVERTER_H
#define NUMBERCONVERTER_H
#include <string>


class NumberConverter
{
    public:
        static std::string convertBinToHex(std::string binNumber);
        static unsigned int convertHexToDec(std::string hexNumber);
        static std::string convertDecToHex(unsigned int decNumber);
        static std::string convertDecToHex(std::string decNumber);
        static int getNumericValue(std::string number);
        static int getHexadecimalValue(std::string hexadecimal);
        static std::string stringfy(int number);
        static bool isNumber(std::string str);
};

#endif // NUMBERCONVERTER_H
