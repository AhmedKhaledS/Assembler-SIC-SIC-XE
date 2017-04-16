#include "StatementParser.h"
#ifndef ASSEMBLERDIRECTIVE_H
#define ASSEMBLERDIRECTIVE_H
#include <string>
#include <vector>

class AssemblerDirective
{
    public:
        AssemblerDirective();
        void assemble(std::string path);
        std::vector<std::string> generateListingCode();
        std::vector<std::string> generateObjectCode();
    private:
        void parseStatement(std::vector<std::string> statement);
        std::vector<std::vector<std::string> > normalize(std::vector<std::string> assemblyCode);
        std::vector<std::string> unparsedStatements;
        std::vector<std::vector<std::string> > statements;
        //FileHandler* fileHandler;
        //StatementNormalizer normalizer;
        StatementParser stParser;
        //CodeGenerator cGenerator;
};

#endif // ASSEMBLERDIRECTIVE_H
