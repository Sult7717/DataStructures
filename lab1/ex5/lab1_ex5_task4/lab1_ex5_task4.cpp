#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//! \brief Максимальное значение элемента случайного массива (минимальное – 0).
const int MaxRandomValue = 100;

//! \brief Создает в динамической памяти массив случайных целых чисел.
/**
* Элементы массива принимают значения от 0 до MaxRandomValue включительно.
* Память необходимо освободить вызовом delete[] в вызывающем коде.
* \param arraySize – количество элементов массива (должно быть больше 0).
* \return Указатель на первый элемент созданного массива.
*/
int* MakeRandomArray(int arraySize)
{
    int* randomArray = new int[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        randomArray[i] = rand() % (MaxRandomValue + 1);
    }

    return randomArray;
}

//! \brief Выводит элементы массива целых чисел в одну строку.
//! \param values – указатель на первый элемент массива.
//! \param itemsCount – количество элементов в массиве.
void PrintArray(const int* values, int itemsCount)
{
    for (int i = 0; i < itemsCount; ++i)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

//! \brief Точка входа: создает и выводит три случайных массива разного размера.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int arraySizes[] = { 5, 8, 13 };

    for (int arraySize : arraySizes)
    {
        int* randomArray = MakeRandomArray(arraySize);

        cout << "Random array of " << arraySize << ":" << endl;
        PrintArray(randomArray, arraySize);

        delete[] randomArray;
    }

    return 0;
}
