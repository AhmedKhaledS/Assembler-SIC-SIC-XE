#include <iostream>
#include "AssemblerDriver.h"
using namespace std;

const int COLUMNS_SIZE = 3;

AssemblerDriver::AssemblerDriver(){}

void AssemblerDriver::assemble(string path)
{
     unparsedStatements = fileReader->readInst(path);
     // A mark to terminate.
     for (string statement : unparsedStatements)
     {
         normalizedStatement = normalize(statement);
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

}
void AssemblerDriver::generateObjectCode()
{
    /// CodeGenerator codeGenerator = CodeGenerator(By Reference 2D Array);
    /// codeGenerator.generateObjectCode();

    // x ldx 1000 4F6C7E
    // y str 1000

}
