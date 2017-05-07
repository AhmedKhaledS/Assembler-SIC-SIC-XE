#include "ObjectFileGenerator.h"
#include "../LocationCounter.h"
#include "../ObjectCodeGenerator/objectCode/ObjectCodeContainer.h"
#include "../utils/LabelVerifier.h"
#include "NumberConverter.h"
#include "../tables/SymbolTable.h"

#include <string>
#include <vector>

using namespace std;

const char H = 'H';
const char T = 'T';
const char E = 'E';
const char ZERO = '0';
const int MAX_TEXT_REC_SIZE = 60;
const int COMP_SIZE = 6;

ObjectFileGenerator::ObjectFileGenerator(vector<vector<string>> src) {
    sourceCode = src;
}

string getDifference(string startPoint, string endPoint) {
    int startValue = NumberConverter::convertHexToDec(startPoint);
    int endValue = NumberConverter::convertHexToDec(endPoint);
    string result = NumberConverter::convertDecToHex(endValue - startValue);
    return result;
}

string fillZeros(string statement, int requiredSize) {
    int length = statement.length();
    string filledStatement = "";
    for (int i = 0; i < requiredSize - length; i++) {
        filledStatement.push_back(ZERO);
    }
    filledStatement.append(statement);
    return filledStatement;
}

string ObjectFileGenerator::getEndRecord() {
    string endRecord;
    vector<string> endInstruction = sourceCode[sourceCode.size() - 1];
    endRecord.push_back(E);
    if (endInstruction[2] == "#") {
        endRecord.append(fillZeros(LocationCounter::getLocationAt(0), COMP_SIZE));
    } else {
        if(SymbolTable::searchSymbol(endInstruction[2])){
            string address = SymbolTable::getAddress(endInstruction[2]);
            endRecord.append(fillZeros(address, COMP_SIZE));
        } else {
            endRecord.append(fillZeros(endInstruction[2], COMP_SIZE));
        }
    }
    return endRecord;
}

string ObjectFileGenerator::getHeaderRecord() {
    string header;
    vector<string> startInstruction = sourceCode[0];
    header.push_back(H);
    header.append(LabelVerifier::fillSpaces(startInstruction[0], COMP_SIZE));
    header.append(fillZeros(LocationCounter::getLocationAt(0), COMP_SIZE));
    string length = getDifference(LocationCounter::getLocationAt(0), LocationCounter::getFinalLocation());
    header.append(fillZeros(length, COMP_SIZE));
    return header;
}

vector<string> ObjectFileGenerator::generateObjectCode() {
    vector<string> objectFileStrings;
    objectFileStrings.push_back(getHeaderRecord());
    string textRecord = "";
    int recordSize = 0;
    for (int i = 1; i < ObjectCodeContainer::getObjectCodeContainerSize() - 1; i++) {
        string curObjectCode = ObjectCodeContainer::getObjectCodeAt(i);
        if (curObjectCode == "      ") {
            continue;
        }
        textRecord.push_back(T);
        textRecord.append(fillZeros(LocationCounter::getLocationAt(i), COMP_SIZE));
        string objectCodes = "";
        while (i < ObjectCodeContainer::getObjectCodeContainerSize() - 1) {
            curObjectCode = ObjectCodeContainer::getObjectCodeAt(i);

            if(curObjectCode == "      ") {
                break;
            }
            if (curObjectCode.length() + recordSize > MAX_TEXT_REC_SIZE) {
                i--;
                break;
            }
            i++;
            objectCodes.append(curObjectCode);
            recordSize += curObjectCode.length();

        }
        string recordLength = NumberConverter::convertDecToHex(recordSize / 2);
        textRecord.append(fillZeros(recordLength, 2));
        textRecord.append(objectCodes);
        objectFileStrings.push_back(textRecord);
        textRecord = "";
        recordSize = 0;
    }
    objectFileStrings.push_back(getEndRecord());
    return objectFileStrings;
}
