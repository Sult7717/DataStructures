#include <iostream>

using namespace std;

//! \brief Принимает число по значению и пытается его изменить.
/**
* Параметр a – копия исходной переменной (с другим адресом), поэтому
* изменение не влияет на значение в вызывающем коде.
* \param a – копия переданного значения.
*/
void FooByValue(double a)
{
    cout << "Address of a in FooByValue(): " << &a << endl;
    cout << "Value of a in FooByValue(): " << a << endl;

    a = 15.0;
    cout << "New value of a in FooByValue(): " << a << endl;
}

//! \brief Принимает число по ссылке и изменяет его.
/**
* Параметр a – синоним исходной переменной (с тем же адресом), поэтому
* изменение видно в вызывающем коде.
* \param a – ссылка на исходную переменную.
*/
void FooByReference(double& a)
{
    cout << "Address of a in FooByReference(): " << &a << endl;
    cout << "Value of a in FooByReference(): " << a << endl;

    a = 15.0;
    cout << "New value of a in FooByReference(): " << a << endl;
}

//! \brief Точка входа: сравнивает передачу аргумента по значению и по ссылке.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    double a = 5.0;

    cout << "--- TEST 1: Passing by Value ---" << endl;
    cout << "Address of a in main(): " << &a << endl;
    cout << "Value of a in main(): " << a << endl;
    cout << endl;

    FooByValue(a);

    cout << endl;

    // Значение остается 5.0, так как функция работала с копией.
    cout << "Value of a in main() after FooByValue(): " << a << endl;
    cout << endl;

    cout << "--- TEST 2: Passing by Reference ---" << endl;
    FooByReference(a);

    cout << endl;

    // Значение изменилось на 15.0, так как функция работала с оригиналом.
    cout << "Value of a in main() after FooByReference(): " << a << endl;

    return 0;
}
