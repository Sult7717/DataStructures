#include <iostream>

using namespace std;

//! \brief Округляет целое число до десятков.
/**
* Если последняя цифра числа (по модулю) меньше 5, число округляется в сторону
* нуля, иначе – от нуля. Например: 14 -> 10, 191 -> 190, 27 -> 30, -15 -> -20.
* \param value – округляемое число, передается по ссылке и изменяется.
*/
void RoundToTens(int& value)
{
    int lastDigit = value % 10;

    if (lastDigit < 0)
    {
        lastDigit = -lastDigit;
    }

    if (lastDigit < 5)
    {
        value = value / 10 * 10;
    }
    else if (value >= 0)
    {
        value = (value / 10 + 1) * 10;
    }
    else
    {
        value = (value / 10 - 1) * 10;
    }
}

//! \brief Точка входа: округляет набор чисел до десятков и выводит результат.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    const int testNumbers[] = { 14, 191, 27, -14, -15, 5, 0 };

    for (int number : testNumbers)
    {
        cout << "For " << number << " ";
        RoundToTens(number);
        cout << "rounded value is " << number << endl;
    }

    return 0;
}
