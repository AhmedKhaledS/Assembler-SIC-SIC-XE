#ifndef ASSEMBLERDRIVER_H
#define ASSEMBLERDRIVER_H
#include "StatementParser.h"
#include "../fileServices/FileReader.h"
#include "../utils/Normalizer.h"
//#include "../ObjectCodeGenerator/ObjectCodeGenerator.h"
#include <string>
#include <vector>


class ObjectCodeGenerator;
class AssemblerDriver
{
    public:
        AssemblerDriver();
        void assemble(std::string path);
        void generateListingCode();
        void generateObjectCode();
    private:
        std::vector<std::string> normalize(std::string assemblyStatement);
        /**
        * Contains all lines of instruction of assembly code.
        */
        std::vector<std::string> unparsedStatements;
        std::vector<std::string> normalizedStatement;
        std::vector<std::vector<std::string>> parsedStatement;
        FileReader* fileReader;
        //StatementNormalizer normalizer;
        StatementParser* stParser;
        Normalizer* normalizer;
        ObjectCodeGenerator* cGenerator;
};

#endif // AssemblerDriver_H
