#include <iostream>
#include "BaseRegister.h"
using namespace std;

int BaseRegister::baseValue = 0;
bool BaseRegister::available = false;

int BaseRegister::getBaseValue() {
    return baseValue;
}

bool BaseRegister::isAvailable() {
    return available;
}

void BaseRegister::setBaseAvailablity() {
    available = true;
}

void BaseRegister::setBaseInAvailablity() {
    available = false;
}
