#include "Constants.h"

using namespace std;

int Constants::NOT_A_POSITION = -1;
int Constants::OP_CODE_SIZE = 2;
int Constants::WORD_SIZE = 3;
int Constants::ADDRESS_CODE_SIZE = 4;
int Constants::OBJECT_CODE_SIZE = 6;
int Constants::MAX_ADDRESS = 32768;
int Constants::MAX_NUMBER = 9999;

char Constants::HEX_PREFIX = 'X';
char Constants::CHAR_PREFIX = 'C';

string Constants::INDEXING_PREFIX = ",X";
string Constants::BYTE = "BYTE";
string Constants::WORD = "WORD";
string Constants::RESW = "RESW";
string Constants::RESB = "RESB";
string Constants::START = "START";
string Constants::END = "END";
string Constants::EMPTY_OBJ_CODE = "      ";

string Constants::ZERO = "0";
string Constants::ZEROS = "0000";
