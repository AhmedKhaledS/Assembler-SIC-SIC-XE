#include <iostream>
#include <vector>
using namespace std;

class LocationCounter {
    private :
        static int locationCounter;
        static vector<int> locations;

    public :
        static int getLocationCounter();
        static void increment(int increm);
};
