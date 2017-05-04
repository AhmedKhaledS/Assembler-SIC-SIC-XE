#include <iostream>

using namespace std;

int main()
{
    int x = -(1 << 31) - 1;
    cout << x;
    return 0;
}
