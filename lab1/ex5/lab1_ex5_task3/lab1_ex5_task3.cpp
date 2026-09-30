#include <iostream>

using namespace std;

//! \brief Сортирует динамический массив вещественных чисел по возрастанию.
//! \param array Указатель на динамический массив.
//! \param size Размер массива.
void SortDoubleArray(double* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size = 10;
    double* doubleArray = new double[size];

    doubleArray[0] = 1.0;
    doubleArray[1] = 15.0;
    doubleArray[2] = -8.2;
    doubleArray[3] = -3.5;
    doubleArray[4] = 12.6;
    doubleArray[5] = 38.4;
    doubleArray[6] = -0.5;
    doubleArray[7] = 4.5;
    doubleArray[8] = 16.7;
    doubleArray[9] = 4.5;

    cout << "Array of double:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    // Передача динамического массива в функцию сортировки
    SortDoubleArray(doubleArray, size);

    cout << "Sorted array of double:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    delete[] doubleArray;

    return 0;
}
