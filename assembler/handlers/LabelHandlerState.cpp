#include "LabelHandlerState.h"
#include "iostream"

using namespace std;

LabelHandlerState::LabelHandlerState(HandlerContext *context): context(context){}

void LabelHandlerState::handle(string statement)
{



    /// If there are no errors .. upgrade the state.
    this->context->setState(context->getInstructionHandler());
    cout << "Currently: instruction-handler-state" << endl;
}

void LabelHandlerState::throwError()
{

}
