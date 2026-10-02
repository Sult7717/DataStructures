#include <iostream>

using namespace std;

void FooByValue(double a)
{
    cout << "Address of a in FooByValue(): " << &a << endl;
    cout << "Value of a in FooByValue(): " << a << endl;

    a = 15.0; 
    cout << "New value of a in FooByValue(): " << a << endl;
}

void FooByReference(double& a)
{
    cout << "Address of a in FooByReference(): " << &a << endl;
    cout << "Value of a in FooByReference(): " << a << endl;

    a = 15.0; 
    cout << "New value of a in FooByReference(): " << a << endl;
}

int main()
{
    double a = 5.0;

    cout << "--- TEST 1: Passing by Value ---" << endl;
    cout << "Address of a in main(): " << &a << endl;
    cout << "Value of a in main(): " << a << endl;
    cout << endl;

    FooByValue(a);

    cout << endl;
    cout << "Value of a in main() after FooByValue(): " << a << endl; // Значение останется 5.0
    cout << endl;

    cout << "--- TEST 2: Passing by Reference ---" << endl;
    FooByReference(a);

    cout << endl;
    cout << "Value of a in main() after FooByReference(): " << a << endl; // Значение изменится на 15.0

    return 0;
}
