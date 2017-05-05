#ifndef OBJECTFILEGENERATOR_H
#define OBJECTFILEGENERATOR_H
#include <string>
#include <vector>

class ObjectFileGenerator
{
    public:
        ObjectFileGenerator(std::vector<std::vector<std::string>> src);
        std::vector<std::string> generateObjectCode();
    private:
        std::vector<std::vector<std::string>> sourceCode;
        std::string getHeaderRecord();
        std::string getEndRecord();
};

#endif // OBJECTFILEGENERATOR_H
