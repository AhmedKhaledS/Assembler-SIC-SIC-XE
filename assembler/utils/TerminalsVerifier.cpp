#include "TerminalsVerifier.h"

using namespace std;

bool TerminalsVerifier::startExistance = false;
bool TerminalsVerifier::endExistance = false;

void TerminalsVerifier::setStartExistance(bool exist)
{
    startExistance = exist;
}

void TerminalsVerifier::setEndExistance(bool exist)
{
     endExistance = exist;
}

bool TerminalsVerifier::getStartExistance()
{
    return startExistance;
}

bool TerminalsVerifier::getEndExistance()
{
     return endExistance;
}
