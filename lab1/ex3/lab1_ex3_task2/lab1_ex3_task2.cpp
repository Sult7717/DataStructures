#include <iostream>

using namespace std;

// Округляет переданное по ссылке значение до десятков
void RoundToTens(int& value)
{
    int remainder = value % 10;

    if (remainder < 0)
    {
        remainder = -remainder;
    }

    if (remainder < 5)
    {
        value = (value / 10) * 10;
    }
    else
    {
        if (value >= 0)
        {
            value = ((value / 10) + 1) * 10;
        }
        else
        {
            value = ((value / 10) - 1) * 10;
        }
    }
}

int main()
{
    int number;
    char choice;

    do
    {
        cout << "Enter an integer to round: ";
        cin >> number;

        cout << "For " << number << " ";
        RoundToTens(number);
        cout << "rounded value is " << number << endl;

        cout << "Do you want to round another number? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y' || choice == '1');

    return 0;
}
