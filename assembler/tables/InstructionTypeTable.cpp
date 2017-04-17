#include <map>
#include <stdio.h>
#include "InstructionTypeTable.h"
#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, bool> > InstructionTypeTable::instructionTypeTable;

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
                string label;
                iss >> label;
                instructionTypeTable[instruction] = {type, label == "label" ? true : false};
            } while (iss);
        }
    }
    instructionsFile.close();
}

string InstructionTypeTable::getType(string operation) {
    return instructionTypeTable[operation].first;
}

bool InstructionTypeTable::getLabelState(string operation) {
    return instructionTypeTable[operation].second;
}
