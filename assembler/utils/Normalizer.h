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
        int normalizeQuotes(std::string instruction,int i);
        int normalizeComments(std::string instruction,int i);
        void addLastPart();


    public:
        Normalizer();
        std::string normalizedInst(std::string);
        std::vector<std::string> splittedInst(std::string);
};
#endif
