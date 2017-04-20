#include "Normalizer.h"
#include "../ObjectCodeGenerator/Constants.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

Normalizer::Normalizer(){
}

string Normalizer::normalizedInst(string instruction){

    string input = instruction;

    // Replace white spaces with only one space
    // Case 1 : Tabs
    while(input.find("\t") != Constants::NOT_A_POSITION){
        input.replace(input.find("\t"), 1, " ");
    }

    // Case 2 : Spaces
    while(input.find("  ") != Constants::NOT_A_POSITION){
        input.replace(input.find("  "), 2, " ");
    }

    return input;
}

    vector<string> Normalizer::splittedInst(string instruction){

    string input = normalizedInst(instruction);
    vector<string> result;

    // Splitting the input into its components
    istringstream iss(instruction);

    // Storing the components into the vector
    for(string k; iss >> k;){
        result.push_back(k);
    }

    return result;
}
