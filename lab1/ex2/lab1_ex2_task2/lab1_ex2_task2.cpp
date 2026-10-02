#include <iostream>

using namespace std;

int main()
{
    double doubleArray[] = 
    { 
        12.0, 21.5, 119.2, -80.7, 
        300.0, 75.5, 81.2, 8.1, 
        47.3, 31.2, 85.3, 100.1 
    };
    double searchingValue = 0.0;
    int countMoreOrEqual = 0;

    cout << "Source array is:" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    cout << "Enter searching value: ";
    cin >> searchingValue;

    for (int i = 0; i < 12; i++)
    {
        if (doubleArray[i] >= searchingValue)
        {
            countMoreOrEqual++;
        }
    }
    cout << "Elements of array more than " << searchingValue 
        << " is: " << countMoreOrEqual << endl;

    return 0;
}
