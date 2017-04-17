#include <map>
#include <stdio.h>
#include "InstructionTypeTable.h"
#include <bits/stdc++.h>
using namespace std;

map<string, string> InstructionTypeTable::instructionTypeTable;

void InstructionTypeTable::load() {
    fstream instructionsFile;
    instructionsFile.open("tables/instructionTypes.txt");
    if (instructionsFile.is_open()) {
        string line;
        while(getline(instructionsFile, line)) {
            istringstream iss(line);
            do
            {
                string instruction;
                iss >> instruction;
                string type;
                iss >> type;
                instructionTypeTable[instruction] = type;
            } while (iss);
        }
    }
    instructionsFile.close();
}

string InstructionTypeTable::getType(string operation) {
    return instructionTypeTable[operation];
}

