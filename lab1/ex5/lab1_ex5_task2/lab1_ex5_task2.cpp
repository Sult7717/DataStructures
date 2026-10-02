#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter char array size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Size must be a positive integer!" << endl;
        return 1;
    }

    char* charArray = new char[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "]: ";
        cin >> charArray[i];
    }

    cout << "Your char array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    delete[] charArray;

    return 0;
}
