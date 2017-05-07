#ifndef SyntaxVerifier_H
#define SyntaxVerifier_H

class SyntaxVerifier
{
    public:
        static void setStartIncrement();
        static void setEndIncrement();
        static int getStartIncrement();
        static int getEndIncrement();
        static void setObjectCodeSyntaxValidity(bool objectCodeSyntaxValidity);
        static bool isValidObjectCodeSyntax();
        static void setListingSyntaxValidity(bool listingSyntaxValidity);
        static bool isValidListingSyntax();

    private:
        static int startCount;
        static int endCount;
        static bool objectCodeSyntaxValidity;
        static bool listingSyntaxValidity;
};

#endif // SyntaxVerifier_H
