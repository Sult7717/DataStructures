#include <iostream>

using namespace std;

// Возводит основание base в степень exponent
double GetPower(double base, int exponent)
{
    double result = 1.0;
    int absExponent = exponent;

    if (exponent < 0)
    {
        absExponent = -exponent;
    }

    for (int i = 0; i < absExponent; i++)
    {
        result *= base;
    }

    if (exponent < 0)
    {
        return 1.0 / result;
    }

    return result;
}

// Демонстрирует работу функции GetPower в красивом формате
void DemoGetPower(double base, int exponent)
{
    double result = GetPower(base, exponent);

    cout << base << " ^ " << exponent << " = " << result << endl;
}

int main()
{
    double base;
    int exponent;
    char choice;

    do
    {
        cout << "Enter base (double): ";
        cin >> base;
        cout << "Enter exponent (int): ";
        cin >> exponent;

        DemoGetPower(base, exponent);

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y' || choice == '1');

    return 0;
}
