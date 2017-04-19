#include "InstructionHandler.h"

using namespace std;

class DirectiveInstructionHandler : public InstructionHandler {

    public :
        DirectiveInstructionHandler(string instruc, string oper);
        bool handle();
    //private :
        static string operand;
};
