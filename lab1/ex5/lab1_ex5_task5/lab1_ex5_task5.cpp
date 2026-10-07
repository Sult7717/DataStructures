#include <iostream>

using namespace std;

//! \brief Количество элементов первого массива.
const int FirstArraySize = 15;

//! \brief Количество элементов второго массива.
const int SecondArraySize = 20;

//! \brief Считывает с клавиатуры массив целых чисел в динамическую память.
/**
* Память необходимо освободить вызовом delete[] в вызывающем коде.
* \param count – количество считываемых элементов.
* \return Указатель на первый элемент массива или nullptr, если count <= 0.
*/
int* ReadArray(int count)
{
    if (count <= 0)
    {
        return nullptr;
    }

    int* values = new int[count]();

    cout << "Enter " << count << " integers:" << endl;
    for (int i = 0; i < count; ++i)
    {
        cin >> values[i];
    }

    return values;
}

//! \brief Подсчитывает количество положительных элементов массива.
//! \param values – указатель на первый элемент массива.
//! \param count – количество элементов в массиве.
//! \return Количество элементов, значение которых больше нуля.
int CountPositiveValues(const int* values, int count)
{
    int result = 0;

    for (int i = 0; i < count; ++i)
    {
        if (values[i] > 0)
        {
            ++result;
        }
    }

    return result;
}

//! \brief Точка входа: читает два массива и подсчитывает в них положительные числа.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    int count = FirstArraySize;
    int* values = ReadArray(count);

    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    // ИСПРАВЛЕНИЕ: освобождаем память первого массива до того, как указатель
    // values будет перезаписан адресом нового массива.
    delete[] values;

    count = SecondArraySize;
    values = ReadArray(count); // Теперь старый адрес не теряется
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    // Освобождаем память второго массива.
    delete[] values;

    return 0;
}

/*
Ответ на вопрос из задания: какие примеры некорректной работы с кодом есть
в исходном примере?
1. Утечка памяти: при повторном values = ReadArray(count) адрес первого массива
   теряется, и delete[] в конце программы освобождает только второй массив.
2. Неясное владение: ReadArray возвращает "голый" указатель, и из сигнатуры не
   видно, кто должен освободить память (надёжнее std::vector или unique_ptr).
3. Нет проверок: не проверяется count > 0 и успешность чтения через cin.
4. Нет приглашения к вводу, поэтому непонятно, что именно нужно вводить.
5. CountPositiveValues не изменяет массив, поэтому параметр должен быть const.
6. Дублирование кода и "магические" числа 15 и 20.
*/
