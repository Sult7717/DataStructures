#include <iostream>

using namespace std;

//! \brief Точка входа: демонстрирует, что ссылка является синонимом переменной.
/**
* Адрес ссылки b совпадает с адресом переменной a, а присваивание значения
* через b изменяет значение a.
* \return Код завершения программы (0 – успешное завершение).
*/
int main()
{
    int a = 5;
    int& b = a;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;
    cout << endl;

    b = 7;
    cout << "Value of a: " << a << endl;

    return 0;
}
