#include <iostream>

using namespace std;

//! \brief Количество элементов в символьном массиве.
const int ArraySize = 8;

//! \brief Точка входа: вводит символьный массив и выводит строчные латинские буквы.
/**
* Массив заполняется с клавиатуры. Регистр учитывается: выводятся только
* символы от 'a' до 'z'.
* \return Код завершения программы (0 – успешное завершение).
*/
int main()
{
    char charArray[ArraySize] = { 0 };

    cout << "Enter array of " << ArraySize << " chars" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << "a[" << i << "]: ";
        cin >> charArray[i];
    }

    cout << "Your array is:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    cout << "All letters in your array:" << endl;
    for (int i = 0; i < ArraySize; ++i)
    {
        if (charArray[i] >= 'a' && charArray[i] <= 'z')
        {
            cout << charArray[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
