#include <iostream>

using namespace std;

//! \brief Принимает указатель на число и изменяет значение по этому адресу.
/**
* Указатель a – копия исходного указателя (у неё свой адрес), но хранит
* адрес той же переменной, поэтому разыменование позволяет изменить оригинал.
* \param a – указатель на изменяемую переменную.
*/
void FooByPointer(double* a)
{
    cout << "Address in pointer a: " << a << endl;
    cout << "Address of pointer a itself: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;

    *a = 15.0;
    cout << "New value in pointer address: " << *a << endl;
}

//! \brief Точка входа: демонстрирует работу с указателями.
/**
* Часть 1 – основы: адрес в указателе, адрес самого указателя, разыменование.
* Часть 2 – передача указателя в функцию.
* \return Код завершения программы (0 – успешное завершение).
*/
int main()
{
    cout << "--- Part 1: Pointer Basics ---" << endl;

    int a = 5;
    int* pointer = &a;

    cout << "Address of a: " << &a << endl;
    cout << "Address in pointer: " << pointer << endl;
    cout << "Address of pointer itself: " << &pointer << endl;
    cout << endl;

    *pointer = 7;
    cout << "Value in a: " << a << endl;
    cout << "Value by pointer address: " << *pointer << endl;
    cout << endl;

    cout << "--- Part 2: Passing Pointer to Function ---" << endl;

    double value = 5.0;
    double* pValue = &value;

    cout << "Address of value in main(): " << &value << endl;
    cout << "Address in pValue in main(): " << pValue << endl;
    cout << "Address of pValue itself in main(): " << &pValue << endl;
    cout << "Value in main(): " << value << endl;
    cout << endl;

    FooByPointer(pValue);

    cout << endl;

    // Значение изменилось на 15.0, так как функция изменила его по адресу.
    cout << "Value in main() after FooByPointer(): " << value << endl;

    return 0;
}

/*
Ответ на вопрос из задания: как отличить разыменование, объявление указателя
и умножение, если во всех трёх случаях используется символ *?
- Объявление указателя: * стоит сразу после имени типа в объявлении
  переменной или параметра: int* pointer = &a;  void FooByPointer(double* a).
- Разыменование: унарная операция, у * нет левого операнда (начало выражения,
  после =, (, запятой): *pointer = 7;  cout << *a;
- Умножение: бинарная операция, * стоит между двумя операндами: a * b.
*/
