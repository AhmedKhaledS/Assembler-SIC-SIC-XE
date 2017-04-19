#include "OperandHandlerState.h"
#include "iostream"

using namespace std;

OperandHandlerState::OperandHandlerState(HandlerContext *context)
{
    this->context = context;
}

void OperandHandlerState::handle(string statement)
{
   /// loading the proper type from the instruction table with the help of the static string
   /// Output string will be passes to the factory directly

    // Calling of the Instruction Handler factory
    //InstructionHandlerFactory* factory = InstructionHandlerFactory::getInstance();
    // string denoting the key for the factory call
    //InstructionHandler* handler = factory.getInstructionHandler();
    //handler.handle();
    //if false call throwError()
    /// If there are no errors .. upgrade the state.
    this->context->setState(nullptr);
    cout << "Currently: null-state." << endl;
}

void OperandHandlerState::throwError()
{

}
