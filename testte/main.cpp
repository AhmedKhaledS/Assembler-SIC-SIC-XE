#include <iostream>

using namespace std;

int main()
{
    int *pt;
    int x = 2;
    pt = &x;
    cout << *pt << endl;
    int *pt2;
    pt2 = pt;
    cout << *pt2 << endl;
    *pt2 = 3;
    cout << *pt << endl;
    return 0;
}
