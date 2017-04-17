#include <map>
#include <stdio.h>
#include "OperationCodeTable.h"
#include <fstream>
#include <sstream>

using namespace std;

map<string, string> OperationCodeTable::opCodeTable;

void OperationCodeTable::load() {

    fstream opCodeFile;
    opCodeFile.open("tables/opCodeTable.txt");
    if (opCodeFile.is_open()) {
        string line;
        while(getline(opCodeFile, line)) {
            istringstream iss(line);
            do
            {
                string operation;
                iss >> operation;
                string code;
                iss >> code;
                opCodeTable[operation] = code;
            } while (iss);
        }

    }
    opCodeFile.close();
}

bool OperationCodeTable::searchOperation(string operation) {
    if (OperationCodeTable::opCodeTable[operation] != "") {
        return true;
    }
    return false;
}

string OperationCodeTable::getCode(string operation) {
    return opCodeTable[operation];
}

