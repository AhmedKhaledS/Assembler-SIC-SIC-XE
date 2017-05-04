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
    string normalized = "";
    vector<string> result;
    result = splittedInst(instruction);
    for(int i=0;i<result.size();i++){
        normalized += result.at(i);
        normalized += " ";
    }
    return normalized;
}

vector<string> Normalizer::splittedInst(string instruction){

    for(size_t i=0; i<instruction.length(); i++){

        charcter = toupper(instruction[i]);

        if(charcter == ' ' && part != ""){
            result.push_back(part);
            part = "";
        } else if (charcter == '\'' ){
            i = normalizeQuotes(instruction,i);
        } else if (charcter == '.'){
           i = normalizeComments(instruction,i);
        } else if(charcter != ' ') {
            part += charcter;
        }
    }
    addLastPart();

    return result;
}

int Normalizer::normalizeQuotes(string instruction,int i){
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
    result.push_back(part);
    part = "";
    return i;
}

int Normalizer::normalizeComments(string instruction,int i){
     part += charcter;
     i++;
     while(i < instruction.length()){
        part += instruction[i];
        i++;
     }
     result.push_back(part);
     part = "";
     return i;
}

void Normalizer::addLastPart(){
    if (part != ""){
         result.push_back(part);
    }
}
