#ifndef NORMALIZER_H
#define NORMALIZER_H
#include <vector>
#include <string>

class Normalizer
{
    private:
        std::string instruction;
        char charcter;
        std::string part;
        std::vector<std::string> result;
        int normalizeQuotes(int i,std::string instruction);
        int normalizeComments(int i,std::string instruction);
        void addLastPart();


    public:
        Normalizer();
        std::string normalizedInst(std::string);
        std::vector<std::string> splittedInst(std::string);
};
#endif
