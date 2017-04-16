#include "StatementParser.h"
#ifndef ASSEMBLERDRIVER_H
#define ASSEMBLERDRIVER_H
#include <string>
#include <vector>

class AssemblerDriver
{
    public:
        AssemblerDriver();
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

#endif // AssemblerDriver_H
