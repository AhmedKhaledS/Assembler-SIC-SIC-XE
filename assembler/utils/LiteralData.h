#ifndef LITERALDATA_H
#define LITERALDATA_H
#include <string>


class LiteralData
{
    public:
        /** Default constructor */
        LiteralData(std::string _name, std::string _value,
                    std::string _address, int _length);
        void setName(std::string _name);
        void setValue(std::string _value);
        void setAddress(std::string _address);
        void setLength(int _length);
        std::string getName();
        std::string getValue();
        std::string getAddress();
        int getLength();

    protected:

    private:
        std::string name, value, address;
        int length;
};

#endif // LITERALDATA_H
