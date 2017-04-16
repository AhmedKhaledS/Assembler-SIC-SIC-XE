#include <map>
#include <stdio.h>
#include "OperationCodeTable.h"

using namespace std;

map<string, string> OperationCodeTable::opCodeTable;

void OperationCodeTable::load() {
    freopen("opCodeTable.txt", "r", stdin);
    int numberOfRegisteredOperations;
    scanf("%d", &numberOfRegisteredOperations);
    for (int i = 0; i < numberOfRegisteredOperations; i++) {
        string operation, code;
        cin >> operation >> code;
        OperationCodeTable::opCodeTable[operation] = code;
    }
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
