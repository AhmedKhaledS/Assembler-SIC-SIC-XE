#include "Normalizer.h"
#include "../ObjectCodeGenerator/Constants.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "LabelVerifier.h"

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

        if( (charcter == ' ' || charcter == '\t') && part != ""){
            result.push_back(part);
            part = "";
        } else if (charcter == '\'' ){
            i = normalizeQuotes(instruction,i);
        } else if (charcter == '.'){
           i = normalizeComments(instruction,i);
        } else if(charcter != ' ' && charcter != '\t') {
            part += charcter;
        }
    }

    addLastPart();

    if(!LabelVerifier::checkReservedWord(result.at(0))){
        result.insert(result.begin(),"#");
    }

    if (result.size() == 2) {
        result.push_back("#");
    }
//    for(int i=0;i<result.size(); i++) {
//        cout <<  result[i] << " " ;
//    }

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
    while(i < instruction.length() && (instruction[i] != ' ' && instruction[i] != '\t')){
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
