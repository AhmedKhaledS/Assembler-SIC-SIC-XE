#include "ObjectCodeContainer.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ObjectCodeContainer::objectCodes;

void ObjectCodeContainer::addObjectCode(string objectCode) {
    objectCodes.push_back(objectCode);
    return;
}

string ObjectCodeContainer::getObjectCodeAt(int index) {
    if (index < 0 || index >= objectCodes.size()) {
        return nullptr;
    }
    return objectCodes[index];
}

int ObjectCodeContainer::getObjectCodeContainerSize() {
    return objectCodes.size();
}
