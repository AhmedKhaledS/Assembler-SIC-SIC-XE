#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LocationCounter {
    private :
        static string locationCounter;
        static vector<string> locations;

    public :
        static string getLocationCounter();
        static void increment(string increm);
};
