#ifndef DIRECTIVEVERIFIER_H
#define DIRECTIVEVERIFIER_H
#include <string>

class DirectiveVerifier
{
    public:
        static bool checkString(std::string literal);
        static bool checkHexadecimal(std::string literal);
        static std::string handleByte(std::string literal);
};
#endif // DIRECTIVEVERIFIER_H
