#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 4;
    double c = 13.5;
    bool d = true;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;
    cout << "Address of c: " << &c << endl;
    cout << "Address of d: " << &d << endl;

    return 0;
}
