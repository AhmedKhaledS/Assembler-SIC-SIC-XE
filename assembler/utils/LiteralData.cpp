#include "LiteralData.h"

using namespace std;

string name;
string value;
string address;
int length;

LiteralData::LiteralData(string _name, string _value,string _address, int _length):
     name(_name), value(_value), address(_address), length(_length)
{

}
void LiteralData::setName(std::string _name)
{
    name = _name;
}
void LiteralData::setValue(std::string _value)
{
    value = _value;
}
void LiteralData::setAddress(std::string _address)
{
    address = _address;
}
void LiteralData::setLength(int _length)
{
    length = _length;
}
string LiteralData::getName()
{
    return name;
}
string LiteralData::getValue()
{
    return value;
}
string LiteralData::getAddress()
{
    return address;
}
int LiteralData::getLength()
{
    return length;
}
