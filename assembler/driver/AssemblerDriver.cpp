#include <iostream>
#include "AssemblerDriver.h"
#include "CodeGenerator.h"
#include "ObjectFileGenerator.h"

using namespace std;

const int COLUMNS_SIZE = 3;

AssemblerDriver::AssemblerDriver(){}

void AssemblerDriver::assemble(string path)
{
    FileReader f = FileReader();
     unparsedStatements = f.read(path);
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

}
void AssemblerDriver::generateObjectCode()
{
    CodeGenerator codeGenerator = CodeGenerator(parsedStatement);
    vector<string> listingCode = codeGenerator.generateObjectCode();
    for (string obj : listingCode) {
        cout << obj << endl;
    }
    ObjectFileGenerator generator = ObjectFileGenerator(parsedStatement);
    vector<string> objFile = generator.generateObjectCode();
    for (string obj : objFile) {
        cout << obj << endl;
    }
    return;
}
