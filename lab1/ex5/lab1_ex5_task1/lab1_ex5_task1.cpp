#include <iostream>

using namespace std;

int main()
{
    cout << "Array of double:" << endl;

    int doubleSize = 8;
    double* doubleArray = new double[doubleSize]
        {
            1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5
        };

    for (int i = 0; i < doubleSize; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl << endl;

    delete[] doubleArray;

    cout << "Array of bool:" << endl;

    int boolSize = 8;
    bool* boolArray = new bool[boolSize] 
        {
            true, false, true, true, false, true, false, false
        };

    for (int i = 0; i < boolSize; i++)
    {
        cout << boolalpha << boolArray[i] << " ";
    }
    cout << endl;

    delete[] boolArray;

    return 0;
}
