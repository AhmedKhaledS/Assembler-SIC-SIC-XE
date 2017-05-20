#include "LiteralData.h"

using namespace std;

LiteralData::LiteralData()
{

}

LiteralData::LiteralData(string _name,string _address, int _length):
    name(_name), address(_address), length(_length)
{

}
void LiteralData::setName(std::string _name)
{
    name = _name;
}
void LiteralData::setAddress(std::string _address)
{
    address = _address;
}
void LiteralData::setLength(int _length)
{
    length = _length;
}
string LiteralData::getName() const
{
    return name;
}
string LiteralData::getAddress() const
{
    return address;
}
int LiteralData::getLength() const
{
    return length;
}
