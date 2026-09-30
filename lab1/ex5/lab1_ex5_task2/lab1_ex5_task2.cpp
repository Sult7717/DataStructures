#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter char array size: ";
    cin >> n;

    // Проверка на корректность введенного размера
    if (n <= 0)
    {
        cout << "Size must be a positive integer!" << endl;
        return 1;
    }

    // Динамическое выделение памяти под n символов
    char* charArray = new char[n];

    // Заполнение массива пользователем с клавиатуры
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "]: ";
        cin >> charArray[i];
    }

    // Вывод получившегося массива
    cout << "Your char array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    // Освобождение динамической памяти
    delete[] charArray;

    return 0;
}
