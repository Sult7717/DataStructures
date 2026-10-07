#include <iomanip>
#include <iostream>

using namespace std;

//! \brief Количество элементов динамического массива.
const int ArraySize = 10;

//! \brief Количество знаков после запятой при выводе вещественных чисел.
const int OutputPrecision = 1;

//! \brief Сортирует массив вещественных чисел по возрастанию (метод пузырька).
//! \param values – указатель на первый элемент массива.
//! \param itemsCount – количество элементов в массиве.
void SortDoubleArray(double* values, int itemsCount)
{
    for (int i = 0; i < itemsCount - 1; ++i)
    {
        for (int j = 0; j < itemsCount - 1 - i; ++j)
        {
            if (values[j] > values[j + 1])
            {
                double temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

//! \brief Выводит элементы массива вещественных чисел в одну строку.
//! \param values – указатель на первый элемент массива.
//! \param itemsCount – количество элементов в массиве.
void PrintDoubleArray(const double* values, int itemsCount)
{
    for (int i = 0; i < itemsCount; ++i)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

//! \brief Точка входа: сортирует динамический массив вещественных чисел.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    cout << fixed << setprecision(OutputPrecision);

    double* doubleArray = new double[ArraySize]
    {
        1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5
    };

    cout << "Array of double:" << endl;
    PrintDoubleArray(doubleArray, ArraySize);

    SortDoubleArray(doubleArray, ArraySize);

    cout << "Sorted array of double:" << endl;
    PrintDoubleArray(doubleArray, ArraySize);

    delete[] doubleArray;

    return 0;
}
