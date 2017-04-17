#ifndef ITT_INCLUDED
#define ITT_INCLUDED

#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

class InstructionTypeTable {
    private :

    static map<string, pair<string, bool> > instructionTypeTable;

    public :

    static void load();

    static string getType(string operation);

    static bool getLabelState(string operation);
};

#endif // ITT_INCLUDED
