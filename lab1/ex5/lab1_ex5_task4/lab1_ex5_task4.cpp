#include <iostream>
#include <cstdlib> // Нужно для функций rand() и srand()
#include <ctime>   // Нужно для функции time()

using namespace std;

//! \brief Создает динамический массив и заполняет его случайными числами.
//! \param arraySize Требуемый размер массива.
//! \return Указатель на созданный динамический массив целых чисел.
int* MakeRandomArray(int arraySize)
{
    // Выделение памяти под массив в куче
    int* randomArray = new int[arraySize];

    // Заполнение случайными числами от 0 до 100
    for (int i = 0; i < arraySize; i++)
    {
        randomArray[i] = rand() % 101;
    }

    return randomArray;
}

//! \brief Выводит элементы целочисленного массива на экран.
//! \param array Указатель на массив.
//! \param size Размер массива.
void PrintArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Инициализация генератора случайных чисел текущим временем
    srand(time(nullptr));

    // 1. Создание и вывод массива из 5 элементов
    int size5 = 5;
    int* array5 = MakeRandomArray(size5);
    cout << "Random array of 5:" << endl;
    PrintArray(array5, size5);
    delete[] array5; // Освобождаем память сразу после использования

    // 2. Создание и вывод массива из 8 элементов
    int size8 = 8;
    int* array8 = MakeRandomArray(size8);
    cout << "Random array of 8:" << endl;
    PrintArray(array8, size8);
    delete[] array8;

    // 3. Создание и вывод массива из 13 элементов
    int size13 = 13;
    int* array13 = MakeRandomArray(size13);
    cout << "Random array of 13:" << endl;
    PrintArray(array13, size13);
    delete[] array13;

    return 0;
}
