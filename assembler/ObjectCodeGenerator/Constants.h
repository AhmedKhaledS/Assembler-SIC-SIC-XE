#ifndef CONSTANTS_INCLUDED
#define CONSTANTS_INCLUDED

#include <string>

using namespace std;

class Constants {
public :
    static int NOT_A_POSITION;
    static int OP_CODE_SIZE;
    static int ADDRESS_CODE_SIZE;
    static int OBJECT_CODE_SIZE;
    static int WORD_SIZE;
    static int MAX_ADDRESS;
    static int MAX_NUMBER;
    static char HEX_PREFIX;
    static char CHAR_PREFIX;
    static string INDEXING_PREFIX;
    static string WORD;
    static string BYTE;
    static string RESB;
    static string RESW;
    static string ZERO;
    static string ZEROS;
};

#endif // CONSTANTS_INCLUDED
