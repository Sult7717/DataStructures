#include <iostream>

using namespace std;

int main()
{
    char charArray[8] = { 0 };

    cout << "Enter array of 8 chars" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> charArray[i];
    }

    cout << "Your array is:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    cout << "All letters in your array:" << endl;
    for (int i = 0; i < 8; i++)
    {
        if (charArray[i] >= 'a' && charArray[i] <= 'z')
        {
            cout << charArray[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
