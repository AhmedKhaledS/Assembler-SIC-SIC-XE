#ifndef LOCATIONCOUNTER_H
#define LOCATIONCOUNTER_H
#include <iostream>
#include <vector>
#include <string>
#include "NumberConverter.h"

using namespace std;

class LocationCounter {
    private :
        static string locationCounter;
        static vector<string> locations;

    public :
        static string getLocationCounter();
        static void increment(string increm);
        static void setLocationCounter(string value);
        static string getLocationAt(int index);
        static string getFinalLocation();
};

#endif // LOCATIONCOUNTER_H
