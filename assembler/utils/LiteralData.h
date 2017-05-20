#ifndef LITERALDATA_H
#define LITERALDATA_H
#include <string>


class LiteralData
{
    public:
        /** Default constructor */
        LiteralData();
        LiteralData(std::string _name,
                    std::string _address, int _length);
        void setName(std::string _name);
        void setAddress(std::string _address);
        void setLength(int _length);
        std::string getName() const;
        std::string getAddress() const;
        int getLength() const;

    protected:

    private:
        std::string name, address;
        int length;
};

#endif // LITERALDATA_H
