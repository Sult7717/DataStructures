#include <iomanip>
#include <iostream>

using namespace std;

//! \brief Количество элементов в массиве вещественных чисел.
const int ArraySize = 12;

//! \brief Количество знаков после запятой при выводе вещественных чисел.
const int OutputPrecision = 1;

//! \brief Точка входа: подсчитывает элементы массива, не меньшие введенного значения.
/**
* Массив инициализируется в коде программы, значение searchingValue вводится
* с клавиатуры.
* \return Код завершения программы (0 – успешное завершение).
*/
int main()
{
    double doubleArray[ArraySize] =
    {
        12.0, 21.5, 119.2, -80.7, 300.0, 75.5,
        81.2, 8.1, 47.3, 31.2, 85.3, 100.1
    };

    cout << fixed << setprecision(OutputPrecision);

    cout << "Source array is:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    double searchingValue = 0.0;
    cout << "Enter searching value: ";
    cin >> searchingValue;

    int countMoreOrEqual = 0;
    for (int i = 0; i < ArraySize; ++i)
    {
        if (doubleArray[i] >= searchingValue)
        {
            ++countMoreOrEqual;
        }
    }

    cout << "Elements of array more than " << searchingValue
        << " is: " << countMoreOrEqual << endl;

    return 0;
}
