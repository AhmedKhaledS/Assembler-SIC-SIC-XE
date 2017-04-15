#include <string>
#ifndef ASSEMBLERDIRECTIVE_H
#define ASSEMBLERDIRECTIVE_H


class AssemblerDirective
{
    public:
        AssemblerDirective();
        std::string* read(std::string path);
        std::string** normalize(std::string* assemblyCode);
        void parseStatement(std::string* statement);
        std::string* generateListingCode();
        std::string* generateObjectCode();
    private:
        std::string* statements[3];
        //FileHandler* fileHandler;
        //StatementNormalizer normalizer;
        //StatementParser stParser;
        //CodeGenerator cGenerator;
};

#endif // ASSEMBLERDIRECTIVE_H
