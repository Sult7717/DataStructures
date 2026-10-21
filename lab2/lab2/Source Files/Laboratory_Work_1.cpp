#include <iostream>
#include <limits>
#include "../Header Files/DynamicArray.h"

using namespace std;

//! \brief Считывает целое число из консоли с проверкой корректности ввода.
//! \param prompt Сообщение для пользователя перед вводом.
//! \return Введенное целое число.
int ReadInt(const char* prompt)
{
    int value = 0;

    while (true)
    {
        cout << prompt;

        if (cin >> value && cin.peek() == '\n')
        {
            return value;
        }

        cout << "Unknown command. Try entering the command again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//! \brief Выводит текущее состояние динамического массива в консоль.
//! \param array Структура динамического массива.
void PrintArray(const DynamicArray& array)
{
    cout << endl;
    cout << "Current array (Size: " << array.GetSize()
        << ", Capacity: " << array.GetCapacity() << "):" << endl;

    if (array.GetSize() == 0)
    {
        cout << "[Empty]" << endl;
        return;
    }

    for (int i = 0; i < array.GetSize(); ++i)
    {
        cout << array.GetElement(i);

        if (i < array.GetSize() - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
}

//! \brief Выводит пользовательское меню действий над динамическим массивом.
void PrintMenu()
{
    cout << endl;
    cout << "Select the action you want to do:" << endl;
    cout << "1. Remove an element by index from an array" << endl;
    cout << "2. Remove an element by value from an array" << endl;
    cout << "3. Insert an element at the beginning" << endl;
    cout << "4. Insert an element at the end" << endl;
    cout << "5. Insert after a certain element" << endl;
    cout << "6. Sort array" << endl;
    cout << "7. Linear search for an element in an array" << endl;
    cout << "8. Binary search for an element in an array" << endl;
    cout << "0. Exit" << endl;
}

//! \brief Выполняет выбранную пользователем команду над массивом.
//! \param array Структура динамического массива.
//! \param command Номер выбранного действия.
void ExecuteCommand(DynamicArray& array, int command)
{
    switch (command)
    {
    case 1:
    {
        if (array.GetSize() == 0)
        {
            cout << "Error: Array is empty." << endl;
            break;
        }

        int index = ReadInt("Enter index to remove: ");

        if (!array.RemoveByIndex(index))
        {
            cout << "Error: Index " << index << " is out of range (0.."
                << array.GetSize() - 1 << ")." << endl;
        }
        else
        {
            cout << "Element at index " << index << " removed." << endl;
        }
        break;
    }
    case 2:
    {
        if (array.GetSize() == 0)
        {
            cout << "Error: Array is empty." << endl;
            break;
        }

        int value = ReadInt("Enter value to remove: ");

        if (!array.RemoveByValue(value))
        {
            cout << "Error: Value " << value << " not found in the array." << endl;
        }
        else
        {
            cout << "Element with value " << value << " removed." << endl;
        }
        break;
    }
    case 3:
    {
        int value = ReadInt("Enter value to insert at the beginning: ");
        array.InsertAtBeginning(value);
        cout << "Element " << value << " inserted at the beginning." << endl;
        break;
    }
    case 4:
    {
        int value = ReadInt("Enter value to insert at the end: ");
        array.InsertAtEnd(value);
        cout << "Element " << value << " inserted at the end." << endl;
        break;
    }
    case 5:
    {
        if (array.GetSize() == 0)
        {
            cout << "Error: Array is empty." << endl;
            break;
        }

        int targetValue = ReadInt("Enter target element value after which to insert: ");
        int newValue = ReadInt("Enter new value to insert: ");

        if (!array.InsertAfterElement(targetValue, newValue))
        {
            cout << "Error: Target element " << targetValue << " not found." << endl;
        }
        else
        {
            cout << "Element " << newValue << " inserted after " << targetValue << "." << endl;
        }
        break;
    }
    case 6:
    {
        array.SortArray();
        cout << "Array sorted using Insertion Sort (Variant 3)." << endl;
        break;
    }
    case 7:
    {
        int value = ReadInt("Enter value for linear search: ");
        int index = array.LinearSearch(value);

        if (index != -1)
        {
            cout << "Element found at index: " << index << endl;
        }
        else
        {
            cout << "Element not found in the array." << endl;
        }
        break;
    }
    case 8:
    {
        if (!array.IsSorted())
        {
            cout << "Array is not sorted. Sorting array before binary search..." << endl;
            array.SortArray();
            PrintArray(array);
        }

        int value = ReadInt("Enter value for binary search: ");
        int index = array.BinarySearch(value);

        if (index != -1)
        {
            cout << "Element found at index: " << index << endl;
        }
        else
        {
            cout << "Element not found in the array." << endl;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

int main()
{
    DynamicArray array;

    array.InsertAtEnd(12);
    array.InsertAtEnd(3);
    array.InsertAtEnd(8);
    array.InsertAtEnd(25);

    cout << "Laboratory Work #1 Dynamic Array" << endl;

    while (true)
    {
        PrintArray(array);
        PrintMenu();

        int command = -1;

        while (true)
        {
            command = ReadInt("Your input: ");

            if (command >= 0 && command <= 8)
            {
                break;
            }

            cout << "Unknown command. Try entering the command again" << endl;
        }

        if (command == 0)
        {
            break;
        }

        ExecuteCommand(array, command);
    }

    return 0;
}