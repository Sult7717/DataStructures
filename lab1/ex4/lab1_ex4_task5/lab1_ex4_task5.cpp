#include <iostream>

using namespace std;

//! \brief Демонстрирует передачу аргумента по указателю.
//! \details В функцию передается копия адреса. С помощью разыменования '*'
//! можно изменить значение, лежащее по этому адресу в вызывающем методе.
//! \param a Указатель на вещественное число (хранит адрес переменной).
void FooByPointer(double* a)
{
    cout << "Address in pointer a: " << a << endl;
    cout << "Address of pointer a itself: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;

    *a = 15.0; // Разыменование и перезапись значения по адресу
    cout << "New value in pointer address: " << *a << endl;
}

int main()
{
    // --- Часть 1: Основы работы с указателями ---
    cout << "--- Part 1: Pointer Basics ---" << endl;

    int a = 5;

    // Объявление указателя 'pointer' и запись в него адреса переменной 'a'
    // Символ '*' после типа означает объявление указателя, а '&' перед 'a' — взятие адреса
    int* pointer = &a;

    cout << "Address of a: " << &a << endl;
    cout << "Address in pointer: " << pointer << endl;     // Совпадает с адресом 'a'
    cout << "Address of pointer itself: " << &pointer << endl; // Собственный адрес указателя
    cout << endl;

    // Изменение значения переменной 'a' через операцию разыменования '*'
    *pointer = 7;
    cout << "Value in a: " << a << endl;
    cout << "Value by pointer address: " << *pointer << endl;
    cout << endl;

    // --- Часть 2: Передача указателя в функцию ---
    cout << "--- Part 2: Passing Pointer to Function ---" << endl;

    double value = 5.0;
    double* pValue = &value;

    cout << "Address of value in main(): " << &value << endl;
    cout << "Address in pValue in main(): " << pValue << endl;
    cout << "Address of pValue itself in main(): " << &pValue << endl;
    cout << "Value in main(): " << value << endl;
    cout << endl;

    // Передаем указатель (адрес) в функцию
    FooByPointer(pValue);

    cout << endl;
    cout << "Value in main() after FooByPointer(): " << value << endl; // Значение изменится на 15.0

    return 0;
}
