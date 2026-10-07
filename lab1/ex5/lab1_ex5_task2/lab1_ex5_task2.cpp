#include <iostream>

using namespace std;

//! \brief Точка входа: создает динамический массив char заданного размера.
/**
* Размер массива и его элементы вводятся с клавиатуры. После вывода массива
* память освобождается.
* \return Код завершения программы (0 – успех, 1 – некорректный размер).
*/
int main()
{
    int arraySize = 0;

    cout << "Enter char array size: ";
    cin >> arraySize;

    if (arraySize <= 0)
    {
        cout << "Size must be a positive integer!" << endl;
        return 1;
    }

    char* charArray = new char[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        cout << "Enter a[" << i << "]: ";
        cin >> charArray[i];
    }

    cout << "Your char array is:" << endl;
    for (int i = 0; i < arraySize; ++i)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    delete[] charArray;

    return 0;
}
