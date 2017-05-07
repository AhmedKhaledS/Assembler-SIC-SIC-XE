#include "SyntaxVerifier.h"

using namespace std;

int SyntaxVerifier::startCount = 0;
int SyntaxVerifier::endCount = 0;
bool SyntaxVerifier::objectCodeSyntaxValidity = true;
bool SyntaxVerifier::listingSyntaxValidity = true;


void SyntaxVerifier::setStartIncrement()
{
    startCount++;
}

void SyntaxVerifier::setEndIncrement()
{
     endCount++;
}

int SyntaxVerifier::getStartIncrement()
{
    return startCount;
}

int SyntaxVerifier::getEndIncrement()
{
     return endCount;
}

void SyntaxVerifier::setObjectCodeSyntaxValidity(bool objectCodeSyntaxState){
    objectCodeSyntaxValidity = objectCodeSyntaxState;
}

bool SyntaxVerifier::isValidObjectCodeSyntax(){
    return objectCodeSyntaxValidity;
}

void SyntaxVerifier::setListingSyntaxValidity(bool listingSyntaxState){
    listingSyntaxValidity = listingSyntaxState;
}

bool SyntaxVerifier::isValidListingSyntax(){
    return listingSyntaxValidity;
}
