#include <iostream>

using namespace std;

//! \brief Количество элементов в массиве целых чисел.
const int ArraySize = 10;

//! \brief Точка входа: выводит массив целых чисел до и после сортировки.
/**
* Массив инициализируется в коде программы и сортируется по возрастанию
* методом пузырька.
* \return Код завершения программы (0 – успешное завершение).
*/
int main()
{
    int intArray[ArraySize] = { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };

    cout << "Source array is:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ArraySize - 1; ++i)
    {
        for (int j = 0; j < ArraySize - 1 - i; ++j)
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
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    return 0;
}
