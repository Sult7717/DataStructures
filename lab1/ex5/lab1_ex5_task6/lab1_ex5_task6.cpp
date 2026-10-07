#include <iostream>

using namespace std;

//! \brief Количество элементов динамического массива.
const int ArraySize = 10;

//! \brief Значение, возвращаемое при поиске, если элемент не найден.
const int NotFoundIndex = -1;

//! \brief Ищет первое вхождение значения в массиве целых чисел (линейный поиск).
//! \param values – указатель на первый элемент массива.
//! \param itemsCount – количество элементов в массиве.
//! \param searchingValue – искомое значение.
//! \return Индекс первого найденного элемента или NotFoundIndex, если его нет.
int FindIndex(const int* values, int itemsCount, int searchingValue)
{
    for (int i = 0; i < itemsCount; ++i)
    {
        if (values[i] == searchingValue)
        {
            return i;
        }
    }

    return NotFoundIndex;
}

//! \brief Точка входа: ищет индекс введенного значения в динамическом массиве.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    int* intArray = new int[ArraySize] { 1, 15, -8, -3, 12, 38, 0, 4, 16, 4 };

    cout << "Int array:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    int searchingValue = 0;
    cout << "Enter searching value: ";
    cin >> searchingValue;

    int foundIndex = FindIndex(intArray, ArraySize, searchingValue);

    if (foundIndex == NotFoundIndex)
    {
        cout << "Searching value " << searchingValue << " was not found" << endl;
    }
    else
    {
        cout << "Index of searching value " << searchingValue
            << " is: " << foundIndex << endl;
    }

    delete[] intArray;

    return 0;
}
