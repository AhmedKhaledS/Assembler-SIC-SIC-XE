#include "CodeGenerator.h"
#include "../tables/InstructionTypeTable.h"
#include "ObjectCodeGenerator.h"
#include "ObjectCodeContainer.h"
#include "ObjectCodeGeneratorFactory.h"
#include "../LocationCounter.h"
#include "../utils/LabelVerifier.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const string SPACE = " ";
const int LOC_FIXED_LENGTH = 6;
const int LABEL_FIXED_LENGTH = 9;
const int INST_FIXED_LENGTH = 8;
const int OP_FIXED_LENGTH = 18;
const int COMMENT_FIXED_LENGTH = 31;

CodeGenerator::CodeGenerator(vector<vector<string>> src)
{
    sourceCode = src;
}


string createListingStatement(vector<string> statement, string objectCode, int index) {
    string listingStatement = "";
    listingStatement.append(
            LabelVerifier::fillSpaces(LocationCounter::getLocationAt(index), LOC_FIXED_LENGTH));
    listingStatement.append(
            LabelVerifier::fillSpaces(statement[0], LABEL_FIXED_LENGTH));
    listingStatement.append(
            LabelVerifier::fillSpaces(statement[1], INST_FIXED_LENGTH));
    listingStatement.append(
            LabelVerifier::fillSpaces(statement[2], OP_FIXED_LENGTH));
    listingStatement.append(objectCode + SPACE);
    if (statement.size() > 3) {
        string comment = "";
        for (int i = 3; i < statement.size(); i++) {
            comment.append(statement[i]);
            comment.append((SPACE));
        }
        listingStatement.append(
                LabelVerifier::fillSpaces(comment, COMMENT_FIXED_LENGTH));
    }
    return listingStatement;
}

vector<string> CodeGenerator::generateObjectCode() {
    vector<string> listingCode;
    int i = 0;
    for (vector<string> statement : sourceCode) {
        string instructionType = InstructionTypeTable::getType(statement[1]);
        ObjectCodeGenerator* generator = ObjectCodeGeneratorFactory::
        getInstance()->getObjectCodeGenerator(instructionType, statement[1], statement[2]);
        string objectCode = generator->parse();
        ObjectCodeContainer::addObjectCode(objectCode);
        listingCode.push_back(createListingStatement(statement, objectCode, i));
        i++;
    }
    return listingCode;
}



