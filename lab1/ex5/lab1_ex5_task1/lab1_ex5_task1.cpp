#include <iostream>

using namespace std;

int main()
{
    // === 1. Работа с динамическим массивом double ===
    cout << "Array of double:" << endl;

    int doubleSize = 8;
    // Выделение памяти в куче под массив из 8 вещественных чисел
    double* doubleArray = new double[doubleSize];

    // Инициализация элементов массива значениями
    doubleArray[0] = 1.0;
    doubleArray[1] = 15.0;
    doubleArray[2] = -8.2;
    doubleArray[3] = -3.5;
    doubleArray[4] = 12.6;
    doubleArray[5] = 38.4;
    doubleArray[6] = -0.5;
    doubleArray[7] = 4.5;
    
    // Вывод массива на экран
    for (int i = 0; i < doubleSize; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl << endl;

    // Освобождение выделенной памяти (обязательно со скобками [])
    delete[] doubleArray;


    // === 2. Работа с динамическим массивом bool ===
    cout << "Array of bool:" << endl;

    int boolSize = 8;
    // Выделение памяти в куче под массив из 8 булевых значений
    bool* boolArray = new bool[boolSize];

    // Инициализация элементов массива
    boolArray[0] = true;
    boolArray[1] = false;
    boolArray[2] = true;
    boolArray[3] = true;
    boolArray[4] = false;
    boolArray[5] = true;
    boolArray[6] = false;
    boolArray[7] = false;

    // Вывод массива на экран (выводит true/false вместо 1/0 благодаря boolalpha)
    for (int i = 0; i < boolSize; i++)
    {
        cout << boolalpha << boolArray[i] << " ";
    }
    cout << endl;

    // Освобождение памяти
    delete[] boolArray;

    return 0;
}
