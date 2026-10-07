#include <iostream>

using namespace std;

//! \brief Количество элементов динамического массива символов.
const int ArraySize = 15;

//! \brief Проверяет, является ли символ строчной латинской буквой от 'a' до 'z'.
//! \param symbol – проверяемый символ.
//! \return true, если symbol – буква от 'a' до 'z' (регистр учитывается).
bool IsLowercaseLetter(char symbol)
{
    return symbol >= 'a' && symbol <= 'z';
}

//! \brief Подсчитывает количество строчных латинских букв в массиве символов.
//! \param values – указатель на первый элемент массива.
//! \param itemsCount – количество элементов в массиве.
//! \return Количество символов от 'a' до 'z'.
int CountLetters(const char* values, int itemsCount)
{
    int result = 0;

    for (int i = 0; i < itemsCount; ++i)
    {
        if (IsLowercaseLetter(values[i]))
        {
            ++result;
        }
    }

    return result;
}

//! \brief Точка входа: подсчитывает и выводит буквы в динамическом массиве char.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    char* charArray = new char[ArraySize]
    {
        'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';', 'q', 'k'
    };

    cout << "Char array is:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    cout << "Letters count: " << CountLetters(charArray, ArraySize) << endl;

    cout << "Letters in array:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        if (IsLowercaseLetter(charArray[i]))
        {
            cout << charArray[i] << " ";
        }
    }
    cout << endl;

    delete[] charArray;

    return 0;
}
