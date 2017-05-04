#include <iostream>
#include <sstream>
#include <string>
#include "TablesLoader.h"
#include "ObjectCodeGenerator/DirectiveObjectCodeGenerator.h"
#include "tables/SymbolTable.h"

using namespace std;

int main(void)
{
    string inst, oper;
    TablesLoader::loadTables();
    SymbolTable::add("limit", "00032F");
    while (true) {
        cin >> inst >> oper;
        DirectiveObjectCodeGenerator d = DirectiveObjectCodeGenerator(oper, inst);
        cout << d.parse() << endl;
    }
    return 0;
}
