#include <map>

using namespace std;

class SymbolTable {
    private :
    static map<string,string> symTable;

    public :

    static void add(string label, string address);
    static bool searchSymbol(string label);
    static string getAddress(string address);
};
