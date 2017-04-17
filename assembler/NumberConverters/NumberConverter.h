#ifndef NUMBERCONVERTER_H
#define NUMBERCONVERTER_H
#include <string>


class NumberConverter
{
    public:
        static std::string convertBinToHex(std::string binNumber);
        static unsigned int convertHexToDec(std::string hexNumber);
        static std::string convertDexToHex(unsigned int decNumber);
};

#endif // NUMBERCONVERTER_H
