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
    return instruction;
}

vector<string> Normalizer::splittedInst(string instruction){

    cout << "Instruction is: " << instruction << endl;


    for(size_t i=0; i<instruction.length(); i++){

        charcter = toupper(instruction[i]);

        if(charcter == ' ' && part != ""){
            cout << part << "     " << part.length() << endl;
            result.push_back(part);
            part = "";
        } else if (charcter == '\'' ){
            i = normalizeQuotes(i,instruction);
        } else if (charcter == '.'){
           i = normalizeComments(i,instruction);
        } else if(charcter != ' ') {
            part += charcter;
        }
    }
    addLastPart();
    cout << "DONE!!!";

    return result;
}

int Normalizer::normalizeQuotes(int i,string instruction){
    part += charcter;
    i++;
    while(i < instruction.length() && instruction[i] != '\''){
        part += instruction[i];
        i++;
    }
    if(i < instruction.length() && instruction[i] == '\''){
        part += instruction[i];
        i++;
    }
    while(i < instruction.length() && instruction[i] != ' '){
        part += instruction[i];
        i++;
    }
    cout << part << "     " << part.length() << endl;
    result.push_back(part);
    part = "";
    return i;
}

int Normalizer::normalizeComments(int i,string instruction){
     part += charcter;
     i++;
     while(i < instruction.length()){
        part += instruction[i];
        i++;
     }
     cout << part << "     " << part.length() << endl;
     result.push_back(part);
     part = "";
     return i;
}

void Normalizer::addLastPart(){
    if (part != ""){
        cout << part << "     " << part.length() << endl;
         result.push_back(part);
    }
}
