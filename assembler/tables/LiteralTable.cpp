#include "LiteralTable.h"

using namespace std;

map<string, LiteralData> LiteralTable::literalTable;
vector<string> pool;

void LiteralTable::addLiteral(std::string key, const LiteralData &data)
{
    literalTable[key] = data;
    pool.push_back(key);
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

vector<string> LiteralTable::getLiteralPool()
{
    vector<string> temporaryPool = pool;
    pool.clear();
    return temporaryPool;
}
