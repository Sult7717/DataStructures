#include <iomanip>
#include <iostream>

using namespace std;

//! \brief Количество элементов динамического массива вещественных чисел.
const int DoubleArraySize = 8;

//! \brief Количество элементов динамического массива логических значений.
const int BoolArraySize = 8;

//! \brief Количество знаков после запятой при выводе вещественных чисел.
const int OutputPrecision = 1;

//! \brief Точка входа: создает в динамической памяти массивы double и bool.
/**
* Каждый массив инициализируется в коде программы, выводится на экран,
* после чего память освобождается.
* \return Код завершения программы (0 – успешное завершение).
*/
int main()
{
    cout << fixed << setprecision(OutputPrecision) << boolalpha;

    cout << "Array of double:" << endl;
    double* doubleArray = new double[DoubleArraySize]
    {
        1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5
    };

    for (int i = 0; i < DoubleArraySize; ++i)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl << endl;

    delete[] doubleArray;

    cout << "Array of bool:" << endl;
    bool* boolArray = new bool[BoolArraySize]
    {
        true, false, true, true, false, true, false, false
    };

    for (int i = 0; i < BoolArraySize; ++i)
    {
        cout << boolArray[i] << " ";
    }
    cout << endl;

    delete[] boolArray;

    return 0;
}
