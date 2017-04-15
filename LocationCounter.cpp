#include <iostream>
#include "LocationCounter.h"

using namespace std;

int LocationCounter::locationCounter = 0;
vector<int> LocationCounter::locations;

int LocationCounter::getLocationCounter() {
	return locationCounter;
}

void LocationCounter::increment(int increm) {
	locations.push_back(locationCounter);
	locationCounter += increm;
}
