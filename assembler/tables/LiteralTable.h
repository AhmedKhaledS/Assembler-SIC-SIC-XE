#ifndef LITERALTABLE_H
#define LITERALTABLE_H
#include "LiteralData.h"
#include <string>
#include <map>
#include <vector>

class LiteralTable
{
    public:
        static void addLiteral(std::string key, const LiteralData &data);
        static LiteralData* getData(std::string key);
        static std::string getName(std::string key);
        static std::string getAddress(std::string key);
        static int getLength(std::string key);
        static std::vector<std::string> getLiteralPool();
    private:
        /** Default constructor */
        LiteralTable();
        /**
        * The key is the hexadecimal representation for the literal.
        * The value containing the three required fields (address, length, name).
        */
        static std::map<std::string, LiteralData> literalTable;
        std::vector<std::string> pool;
};

#endif // LITERALTABLE_H
