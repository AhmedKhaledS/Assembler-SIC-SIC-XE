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
};

#endif // NUMBERCONVERTER_H
