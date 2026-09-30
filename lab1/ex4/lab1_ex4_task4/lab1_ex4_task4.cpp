#include <iostream>

using namespace std;

//! \brief Демонстрирует передачу аргумента по значению.
//! \details При вызове создается локальная копия переменной. 
//! Изменения внутри функции безопасны для оригинала.
//! \param a Копия вещественного числа.
void FooByValue(double a)
{
    cout << "Address of a in FooByValue(): " << &a << endl;
    cout << "Value of a in FooByValue(): " << a << endl;

    a = 15.0; // Меняется только локальная копия
    cout << "New value of a in FooByValue(): " << a << endl;
}

//! \brief Демонстрирует передачу аргумента по ссылке.
//! \details Функция работает напрямую с оригинальной переменной по её адресу.
//! Изменения внутри функции перезапишут исходные данные.
//! \param a Ссылка на исходное вещественное число.
void FooByReference(double& a)
{
    cout << "Address of a in FooByReference(): " << &a << endl;
    cout << "Value of a in FooByReference(): " << a << endl;

    a = 15.0; // Изменяет оригинальную переменную из main()
    cout << "New value of a in FooByReference(): " << a << endl;
}

int main()
{
    double a = 5.0;

    // Тест 1: Передача по значению
    cout << "--- TEST 1: Passing by Value ---" << endl;
    cout << "Address of a in main(): " << &a << endl;
    cout << "Value of a in main(): " << a << endl;
    cout << endl;

    FooByValue(a);

    cout << endl;
    cout << "Value of a in main() after FooByValue(): " << a << endl; // Значение останется 5.0
    cout << endl;

    // Тест 2: Передача по ссылке
    cout << "--- TEST 2: Passing by Reference ---" << endl;
    FooByReference(a);

    cout << endl;
    cout << "Value of a in main() after FooByReference(): " << a << endl; // Значение изменится на 15.0

    return 0;
}
