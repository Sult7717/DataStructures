#include "../Header Files/DynamicArray.h"

DynamicArray::DynamicArray()
{
    _size = 0;
    _capacity = DefaultCapacity;
    _array = new int[_capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] _array;
}

void DynamicArray::Resize(int newCapacity)
{
    if (newCapacity < DefaultCapacity)
    {
        newCapacity = DefaultCapacity;
    }

    if (newCapacity == _capacity)
    {
        return;
    }

    int* newArray = new int[newCapacity];
    int elementsToCopy = (_size < newCapacity) ? _size : newCapacity;

    for (int i = 0; i < elementsToCopy; ++i)
    {
        newArray[i] = _array[i];
    }

    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

void DynamicArray::ShrinkIfNeeded()
{
    if (_capacity <= DefaultCapacity)
    {
        return;
    }

    if (_size == 0)
    {
        Resize(DefaultCapacity);
        return;
    }

    if (_capacity / _size >= GrowthFactor)
    {
        Resize(_capacity / GrowthFactor);
    }
}

int DynamicArray::GetSize() const
{
    return _size;
}

int DynamicArray::GetCapacity() const
{
    return _capacity;
}

int* DynamicArray::GetArray() const
{
    return _array;
}

int DynamicArray::GetElement(int index) const
{
    return _array[index];
}

bool DynamicArray::AddElement(int index, int value)
{
    if (index < 0 || index > _size)
    {
        return false;
    }

    if (_size >= _capacity)
    {
        Resize(_capacity * GrowthFactor);
    }

    for (int i = _size; i > index; --i)
    {
        _array[i] = _array[i - 1];
    }

    _array[index] = value;
    ++_size;

    return true;
}

void DynamicArray::InsertAtBeginning(int value)
{
    AddElement(0, value);
}

void DynamicArray::InsertAtEnd(int value)
{
    AddElement(_size, value);
}

bool DynamicArray::InsertAfterElement(int targetValue, int newValue)
{
    int targetIndex = LinearSearch(targetValue);

    if (targetIndex == -1)
    {
        return false;
    }

    return AddElement(targetIndex + 1, newValue);
}

bool DynamicArray::RemoveByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        return false;
    }

    for (int i = index; i < _size - 1; ++i)
    {
        _array[i] = _array[i + 1];
    }

    --_size;
    ShrinkIfNeeded();

    return true;
}

bool DynamicArray::RemoveByValue(int value)
{
    int targetIndex = LinearSearch(value);

    if (targetIndex == -1)
    {
        return false;
    }

    return RemoveByIndex(targetIndex);
}

void DynamicArray::SortArray()
{
    for (int i = 1; i < _size; ++i)
    {
        int key = _array[i];
        int j = i - 1;

        while (j >= 0 && _array[j] > key)
        {
            _array[j + 1] = _array[j];
            --j;
        }

        _array[j + 1] = key;
    }
}

int DynamicArray::LinearSearch(int value) const
{
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int DynamicArray::BinarySearch(int value) const
{
    int left = 0;
    int right = _size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (_array[mid] == value)
        {
            return mid;
        }

        if (_array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

bool DynamicArray::IsSorted() const
{
    for (int i = 0; i < _size - 1; ++i)
    {
        if (_array[i] > _array[i + 1])
        {
            return false;
        }
    }

    return true;
}