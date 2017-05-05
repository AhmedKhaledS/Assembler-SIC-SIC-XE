#include <map>
#include <string>
#include <iostream>

#include "SymbolTable.h"

using namespace std;

map<string,string> SymbolTable::symTable;

void SymbolTable::add(string label, string address) {
    symTable[label] = address;
}

bool SymbolTable::searchSymbol(string label) {
    if (symTable[label] != "") {
        return true;
    }
    return false;
}
string SymbolTable::getAddress(string address) {
    return symTable[address];
}
