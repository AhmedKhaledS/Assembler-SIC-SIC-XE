#include "InstructionHandler.h"
#include "../tables/LiteralsPool.h"

using namespace std;

class DirectiveInstructionHandler : public InstructionHandler {

    public :
        DirectiveInstructionHandler(string instruc, string oper);
        bool handle();
    //private :
        static string operand;
};
