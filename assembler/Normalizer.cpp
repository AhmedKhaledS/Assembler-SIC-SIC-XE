#include "Normalizer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

Normalizer::Normalizer(string instruction)
:instruction(instruction)
{
}

std::string Normalizer::normalizedInst(){

    string input = instruction;

    // Variable used to check the boundary of the input string
    static int nPos = -1;

    // Replace white spaces with only one space
    // Case 1 : Tabs
    while(input.find("\t") != nPos){
        input.replace(input.find("\t"), 1, " ");
    }
    // Case 2 : Spaces
    while(input.find("  ") != nPos){
        input.replace(input.find("  "), 2, " ");
    }

    return input;
}

std::vector<std::string> Normalizer::splittedInst(){

   std::string input = normalizedInst();

    vector<string> result;

    // Splitting the input into its components
    istringstream iss(instruction);

    // Storing the components into the vector
    for(string k; iss >> k;){
        result.push_back(k);
    }

    return result;
}
