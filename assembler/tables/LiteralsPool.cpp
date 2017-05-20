#include "LiteralsPool.h"

using namespace std;

vector<string> LiteralsPool::literalPool;
vector<int> LiteralsPool::literalPoolSizes;

void incrementLocationCounter(string literal) {
    literal = literal.substr(1, literal.length() - 1);
    string key = DirectiveVerifier::handleByte(literal);
    LocationCounter::increment(NumberConverter::stringfy(key.length() / 2));
    return;
}

void LiteralsPool::addLiterals(vector<string> literals) {
    for (string literal : literals) {
        literalPool.push_back(literal);
        incrementLocationCounter(literal);
    }
    return;
}

string LiteralsPool::getLiteral(int index) {
    return literalPool[index];
}

void LiteralsPool::addLiteralPoolSize(int poolSize) {
    literalPoolSizes.push_back(poolSize);
}

int LiteralsPool::getPoolSize(int index) {
    return literalPoolSizes[index];
}
