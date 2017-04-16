#include "StatementParser.h"
#ifndef ASSEMBLERDIRECTIVE_H
#define ASSEMBLERDIRECTIVE_H
#include <string>
#include <vector>

class AssemblerDirective
{
    public:
        AssemblerDirective();
        std::vector<std::string> read(std::string path);
        std::vector<std::vector<std::string>> normalize(std::vector<std::string> assemblyCode);
        void parseStatement(std::vector<std::string> statement);
        std::vector<std::string> generateListingCode();
        std::vector<std::string> generateObjectCode();
    private:
        std::vector<std::vector<std::string>> statements;
        //FileHandler* fileHandler;
        //StatementNormalizer normalizer;
        StatementParser stParser;
        //CodeGenerator cGenerator;
};

#endif // ASSEMBLERDIRECTIVE_H
