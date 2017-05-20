#ifndef LITERALSPOOL_H
#define LITERAL
#include <vector>
#include <string>
#include "../utils/DirectiveVerifier.h"
#include "../LocationCounter.h"

class LiteralsPool
{
    public:
        static std::vector<std::string> literalPool;
        static std::vector<int> literalPoolSizes;
        static void addLiterals(std::vector<std::string> literals);
        static std::string getLiteral(int index);
        static void addLiteralPoolSize(int poolSize);
        static int getPoolSize(int index);

    protected:

    private:
};

#endif // LITERALSPOOL_H
