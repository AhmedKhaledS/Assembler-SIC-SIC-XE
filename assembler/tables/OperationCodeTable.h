#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

class OperationCodeTable {
    private :

    static map<string, string> opCodeTable;

    public :

    static void load();

    static bool searchOperation(string operation);

    static string getCode(string operation);
};

