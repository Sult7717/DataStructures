#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

//! \brief Количество знаков после запятой при выводе основания степени.
const int BasePrecision = 1;

//! \brief Точность вывода результата (значение по умолчанию для std::cout).
const int ResultPrecision = 6;

//! \brief Возводит число в целую степень.
/**
* Допускаются отрицательные и нулевой показатели степени. Для нулевого
* основания с отрицательным показателем результат не определен, функция
* возвращает бесконечность.
* \param base – основание степени.
* \param exponent – показатель степени.
* \return Значение base в степени exponent.
*/
double GetPower(double base, int exponent)
{
    if (base == 0.0 && exponent < 0)
    {
        return numeric_limits<double>::infinity();
    }

    int absExponent = exponent < 0 ? -exponent : exponent;
    double result = 1.0;

    for (int i = 0; i < absExponent; ++i)
    {
        result *= base;
    }

    if (exponent < 0)
    {
        return 1.0 / result;
    }

    return result;
}

//! \brief Вычисляет степень с помощью GetPower() и выводит её в консоль.
/**
* Формат вывода: base ^ exponent = result.
* \param base – основание степени.
* \param exponent – показатель степени.
*/
void DemoGetPower(double base, int exponent)
{
    double result = GetPower(base, exponent);

    cout << fixed << setprecision(BasePrecision) << base
        << " ^ " << exponent << " = ";
    cout << defaultfloat << setprecision(ResultPrecision) << result << endl;
}

//! \brief Точка входа: демонстрирует вызов GetPower() напрямую и через DemoGetPower().
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    cout << "--- Direct GetPower() calls in main() ---" << endl;
    cout << "2.0 ^ 5 = " << GetPower(2.0, 5) << endl;
    cout << "3.0 ^ 4 = " << GetPower(3.0, 4) << endl;
    cout << "-2.0 ^ 5 = " << GetPower(-2.0, 5) << endl;
    cout << endl;

    cout << "--- DemoGetPower() calls ---" << endl;
    DemoGetPower(2.0, 5);
    DemoGetPower(3.0, 4);
    DemoGetPower(-2.0, 5);
    DemoGetPower(2.0, -2);
    DemoGetPower(5.0, 0);

    return 0;
}
