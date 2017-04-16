#ifndef OPERATIONCODETABLE_H
#define OPERATIONCODETABLE_H
#include <map>
#include <iostream>
#include <stdio.h>

class OperationCodeTable {
    private :

    static std::map<std::string, std::string> opCodeTable;

    public :

    static void load();

    static bool searchOperation(std::string operation);

    static std::string getCode(std::string operation);
};



#endif // OPERATIONCODETABLE_H
