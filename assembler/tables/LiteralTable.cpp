#include "LiteralTable.h"

using namespace std;

map<string, LiteralData> LiteralTable::literalTable;

void LiteralTable::addLiteral(std::string key, const LiteralData &data)
{

    literalTable[key] = data;
}
LiteralData* LiteralTable::getData(std::string key)
{
    return &literalTable[key];
}
string LiteralTable::getName(std::string key)
{
    return literalTable[key].getName();
}
string LiteralTable::getAddress(std::string key)
{
    return literalTable[key].getAddress();
}
int LiteralTable::getLength(std::string key)
{
    return literalTable[key].getLength();
}
