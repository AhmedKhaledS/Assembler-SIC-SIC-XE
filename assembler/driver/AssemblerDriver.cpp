#include <iostream>
#include "AssemblerDriver.h"
#include "../ObjectCodeGenerator/CodeGenerator.h"
#include "../objectFileGenerator/ObjectFileGenerator.h"

using namespace std;

const int COLUMNS_SIZE = 3;

AssemblerDriver::AssemblerDriver(){
    fileReader = new FileReader();
    fileWriter = new FileWriter();
}

void AssemblerDriver::assemble(string path)
{
     unparsedStatements = fileReader->read(path);
     // A mark to terminate.
     for (string statement : unparsedStatements)
     {
         normalizedStatement = normalize(statement);
         parsedStatement.push_back(normalizedStatement);
         stParser->parse(normalizedStatement);
         // Catch all unexpected errors.
         // Here goes the interaction with object code generator and file writer.
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
