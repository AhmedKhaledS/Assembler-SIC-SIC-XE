#ifndef HC_INCLUDED
#define HC_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class HexadecimalConverter {
private :
    static char getChar(int n);
    static char hexAlphabet[6];

public :
    static string convertDecToHex(int number);
    static string convertDecToHex(string number);
    static int getNumericValue(string number);
};

#endif // HC_INCLUDED
