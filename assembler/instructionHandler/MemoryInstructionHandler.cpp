#include "MemoryInstructionHandler.h"
#include "../tables/InstructionTypeTable.h"
#include <iostream>
#include <../utils/LabelVerifier.h>
#include <DirectiveVerifier.h>
#include "../logger/Logger.h"
#include "../logger/LoggerConstants.h"
#include "../ObjectCodeGenerator/Constants.h"
#include "NumberConverter.h"
#include "../tables/LiteralTable.h"

using namespace std;

MemoryInstructionHandler::MemoryInstructionHandler(string inst)
{
    instruction = inst;
}

bool MemoryInstructionHandler::checkEmptyInstruction() {
    // Check if the instruction is empty
    if(instruction == ""){
        Logger::log("Empty Instruction", LoggerConstants::ERROR);
        return false;
    }
    return true;
}

bool MemoryInstructionHandler::checkIndexedAddressing() {
    // Check if ",X" exists zero or 1 one time only in the correct position
    if(instruction.length() > 2){
        int check =  instruction.find(",X", 0, 2);
        if(check == instruction.length() - 2){
            instruction.replace(instruction.find(",X", 0, 2),2 ,"");
            Logger::log("INDEXING OK " + instruction, LoggerConstants::DEBUG);
        }else if(check > -1){
            Logger::log("INDEXING NOT OK", LoggerConstants::ERROR);
            return false;
        }
    }
    return true;
}

bool MemoryInstructionHandler::handleStatement() {
    return checkEmptyInstruction() && checkIndexedAddressing()
     && LabelVerifier::checkReservedWord(instruction)
     && LabelVerifier::checkNamingConvention(instruction);
}

bool checkStringLiteral(string literal){
    bool check = DirectiveVerifier::checkString(literal);
    if(!check){
        return false;
    }

    cout << "STRING IS CORRECT" << endl;
    string key = DirectiveVerifier::handleByte(literal);
    cout << key << endl;

    LiteralData lt(literal, "", key.length());
    LiteralTable::addLiteral(key,lt);
    return true;
}

bool checkHexaDecimalLiteral(string literal){
    bool check = DirectiveVerifier::checkHexadecimal(literal);
    if(!check){
        return false;
    }
    cout << "HEXADECIMAL IS CORRECT" << endl;
    string key = DirectiveVerifier::handleByte(literal);
    cout << key << endl;

    LiteralData lt(literal, "", key.length());
    LiteralTable::addLiteral(key,lt);
    return true;
}

bool MemoryInstructionHandler::handleLiteral(){
    string literal = instruction.substr(1,instruction.length());
    return  checkStringLiteral(literal) || checkHexaDecimalLiteral(literal);
}

bool MemoryInstructionHandler::handle() {
    InstructionTypeTable::load();
    if(instruction.at(0) == '='){
        return handleLiteral();
    }else{
        return handleStatement();
    }
}
