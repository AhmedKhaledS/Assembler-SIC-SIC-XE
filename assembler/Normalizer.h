#ifndef NORMALIZER_H
#define NORMALIZER_H
#include <vector>
#include <string>

class Normalizer
{
    private:
        std::string instruction;

    public:
        Normalizer(std::string);
        std::string normalizedInst();
        std::vector<std::string> splittedInst();
};
#endif
