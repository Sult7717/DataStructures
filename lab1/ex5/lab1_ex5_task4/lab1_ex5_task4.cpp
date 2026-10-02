#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int* MakeRandomArray(int arraySize)
{
    int* randomArray = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        randomArray[i] = rand() % 101;
    }

    return randomArray;
}

void PrintArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(nullptr));

    int size5 = 5;
    int* array5 = MakeRandomArray(size5);
    cout << "Random array of 5:" << endl;
    PrintArray(array5, size5);
    delete[] array5; 

    int size8 = 8;
    int* array8 = MakeRandomArray(size8);
    cout << "Random array of 8:" << endl;
    PrintArray(array8, size8);
    delete[] array8;

    int size13 = 13;
    int* array13 = MakeRandomArray(size13);
    cout << "Random array of 13:" << endl;
    PrintArray(array13, size13);
    delete[] array13;

    return 0;
}
