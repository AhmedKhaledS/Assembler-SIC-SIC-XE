#include <iostream>

using namespace std;

class BaseRegister {
    private :
        static int baseValue;
        static bool available;
    public :
        static int getBaseValue();

        static bool isAvailable();

        static void setBaseAvailablity();

        static void setBaseInAvailablity();
};
