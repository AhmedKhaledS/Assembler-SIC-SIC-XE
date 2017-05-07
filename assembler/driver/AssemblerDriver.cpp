#include <iostream>
#include "AssemblerDriver.h"
#include "../ObjectCodeGenerator/CodeGenerator.h"
#include "../objectFileGenerator/ObjectFileGenerator.h"
#include "../utils/SyntaxVerifier.h"
#include "../logger/Logger.h"
#include "../utils/TablesLoader.h"

using namespace std;

const int COLUMNS_SIZE = 3;

AssemblerDriver::AssemblerDriver(){
    fileReader = new FileReader();
    fileWriter = new FileWriter();
}

bool checkTerminals(){
    int startCount = SyntaxVerifier::getStartIncrement();
    int endCount = SyntaxVerifier::getEndIncrement();
    if(startCount == 1 && endCount == 1){
        return true;
    }
    Logger::log("Error in terminals .obj file will not be generated","ERROR");
    return false;
}

void prepareForProcessing(){

     TablesLoader::loadTables();
     Logger::loggerOn = true;

}

void AssemblerDriver::assemble(string path)
{
     prepareForProcessing();
     unparsedStatements = fileReader->read(path);
     // A mark to terminate.
     for (string statement : unparsedStatements)
     {
         normalizedStatement = normalize(statement);
         if(normalizedStatement.size() == 0){
            continue;
         }
         parsedStatement.push_back(normalizedStatement);
         stParser->parse(normalizedStatement);
         // Catch all unexpected errors.
         // Here goes the interaction with object code generator and file writer.
     }

    if(SyntaxVerifier::isValidListingSyntax()){
        generateListingCode();
        if(checkTerminals()){
        generateObjectCode();
        }
    }




     return;
}

vector<string> AssemblerDriver::normalize(string assemblyCode)
{
    Normalizer n;
    return n.splittedInst(assemblyCode);
}

void AssemblerDriver::generateListingCode()
{
    CodeGenerator codeGenerator = CodeGenerator(parsedStatement);
    vector<string> listingCode = codeGenerator.generateObjectCode();
    fileWriter->write("", "ListingFile",listingCode);
    return;
}

void AssemblerDriver::generateObjectCode()
{
    ObjectFileGenerator generator = ObjectFileGenerator(parsedStatement);
    vector<string> objFile = generator.generateObjectCode();
    fileWriter->write("", "ObjectCode", objFile);
    return;
}
