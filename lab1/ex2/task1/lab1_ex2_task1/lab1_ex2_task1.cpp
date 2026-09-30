#include <iostream>

using namespace std;

int main()
{
    int intArray[] = { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };

    cout << "Source array is:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // Сортировка методом пузырька по возрастанию
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (intArray[j] > intArray[j + 1])
            {
                int temp = intArray[j];
                intArray[j] = intArray[j + 1];
                intArray[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array is:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    return 0;
}
