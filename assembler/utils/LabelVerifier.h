#ifndef LABELVERIFIER_H
#define LABELVERIFIER_H
#include <string>

using namespace std;

class LabelVerifier {

    public :
        static bool checkReservedWord(string label);
        static string fillSpaces(string statemenComponent, int requiredSize);
        static bool checkExistence(string label);
        static bool checkNamingConvention(string label);
};

#endif // LABELVERIFIER_H
