#include <iostream>
#include "LocationCounter.h"
#include "NumberConverter.h"
#include <string>

using namespace std;

string LocationCounter::locationCounter = "0";
vector<string> LocationCounter::locations;

string LocationCounter::getLocationCounter() {
	return locationCounter;
}

void LocationCounter::increment(string increm) {
	locations.push_back(locationCounter);
	int locationCounterValue = NumberConverter::convertHexToDec(locationCounter);
	int incrementValue = (NumberConverter::convertHexToDec(increm));
    locationCounterValue += incrementValue;
    locationCounter = NumberConverter::convertDecToHex(locationCounterValue);
    return;
}

void LocationCounter::setLocationCounter(string value) {
    locationCounter = value;
    return;
}

string LocationCounter::getFinalLocation() {
    return locations.back();
}

string LocationCounter::getLocationAt(int index) {
    return locations[index];
}
