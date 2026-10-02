#include <iostream>

using namespace std;

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
    double* doubleArray = new double[size] 
    {
        1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5
    };

    cout << "Array of double:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

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
