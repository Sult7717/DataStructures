#include <iostream>

using namespace std;

// Функция считывания массива (выделяет динамическую память)
int* ReadArray(int count)
{
    int* values = new int[count];

    for (int i = 0; i < count; i++)
    {
        cin >> values[i];
    }

    return values;
}

// Функция подсчета положительных элементов
int CountPositiveValues(int* values, int count)
{
    int result = 0;

    for (int i = 0; i < count; i++)
    {
        if (values[i] > 0)
        {
            result++;
        }
    }

    return result;
}

int main()
{
    int count = 15;
    int* values = ReadArray(count);

    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    // ИСПРАВЛЕНИЕ: Освобождаем память первого массива перед выделением второго!
    delete[] values;

    count = 20;
    values = ReadArray(count); // Теперь старый адрес не затрется с утечкой
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    // Освобождаем память второго массива
    delete[] values;

    return 0;
}
