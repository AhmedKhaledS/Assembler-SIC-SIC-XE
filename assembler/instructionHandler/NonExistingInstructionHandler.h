#ifndef NONEXISTINGINSTRUCTIONHANDLER_H
#define NONEXISTINGINSTRUCTIONHANDLER_H

#include <InstructionHandler.h>


class NonExistingInstructionHandler : public InstructionHandler
{
    public:
        NonExistingInstructionHandler();
        bool handle();

    protected:

    private:
};

#endif // NONEXISTINGINSTRUCTIONHANDLER_H
