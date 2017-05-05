#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H
#include <string>
#include <vector>

class CodeGenerator
{
    public:
        CodeGenerator(std::vector<std::vector<std::string>> src);
        std::vector<std::string> generateObjectCode();

    private:
        std::vector<std::vector<std::string>> sourceCode;
};

#endif // CODEGENERATOR_H
