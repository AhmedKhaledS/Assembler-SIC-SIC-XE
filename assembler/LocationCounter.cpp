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
	if (locationCounter == "1030") {
        int debug = -1;
	}
	cout << locationCounter << endl;
	int locationCounterValue = NumberConverter::convertHexToDec(locationCounter);
	int incrementValue = (NumberConverter::convertHexToDec(increm));
    locationCounterValue += incrementValue;
    locationCounter = NumberConverter::convertDecToHex(locationCounterValue);
}
