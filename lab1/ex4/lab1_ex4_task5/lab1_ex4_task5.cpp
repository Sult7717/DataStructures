#include <iostream>

using namespace std;

void FooByPointer(double* a)
{
    cout << "Address in pointer a: " << a << endl;
    cout << "Address of pointer a itself: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;

    *a = 15.0; 
    cout << "New value in pointer address: " << *a << endl;
}

int main()
{
    cout << "--- Part 1: Pointer Basics ---" << endl;

    int a = 5;

    int* pointer = &a;

    cout << "Address of a: " << &a << endl;
    cout << "Address in pointer: " << pointer << endl;    
    cout << "Address of pointer itself: " << &pointer << endl;
    cout << endl;

    *pointer = 7;
    cout << "Value in a: " << a << endl;
    cout << "Value by pointer address: " << *pointer << endl;
    cout << endl;

    cout << "--- Part 2: Passing Pointer to Function ---" << endl;

    double value = 5.0;
    double* pValue = &value;

    cout << "Address of value in main(): " << &value << endl;
    cout << "Address in pValue in main(): " << pValue << endl;
    cout << "Address of pValue itself in main(): " << &pValue << endl;
    cout << "Value in main(): " << value << endl;
    cout << endl;

    FooByPointer(pValue);

    cout << endl;
    cout << "Value in main() after FooByPointer(): " << value << endl; // Значение изменится на 15.0

    return 0;
}
