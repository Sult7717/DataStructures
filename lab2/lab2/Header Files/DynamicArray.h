#pragma once
#pragma once

//! \brief Структура динамического массива.
struct DynamicArray
{
private:
    //! \brief Коэффициент роста массива.
    static const int GrowthFactor = 2;

    //! \brief Начальная вместимость массива по умолчанию.
    static const int DefaultCapacity = 4;

    //! \brief Размер массива.
    int _size;

    //! \brief Вместимость массива.
    int _capacity;

    //! \brief Массив.
    int* _array;

    //! \brief Изменяет вместимость внутреннего массива.
    //! \param newCapacity Новая вместимость массива.
    void Resize(int newCapacity);

    //! \brief Уменьшает вместимость массива при необходимости после удаления элемента.
    void ShrinkIfNeeded();

public:
    //! \brief Конструктор по умолчанию, инициализирующий поля массива.
    DynamicArray();

    //! \brief Деструктор, освобождающий выделенную память.
    ~DynamicArray();

    //! \brief Возвращает размер массива.
    //! \return Размер массива.
    int GetSize() const;

    //! \brief Возвращает вместимость массива.
    //! \return Вместимость массива.
    int GetCapacity() const;

    //! \brief Возвращает массив.
    //! \return Указатель на внутренний массив.
    int* GetArray() const;

    //! \brief Возвращает элемент по индексу.
    //! \param index Индекс, по которому нужно получить значение.
    //! \return Возвращает значение, которое находится под индексом.
    int GetElement(int index) const;

    //! \brief Добавляет элемент в массив по указанному индексу.
    //! \param index Индекс элемента, куда нужно добавить элемент.
    //! \param value Значение элемента.
    //! \return true, если элемент успешно добавлен; иначе false.
    bool AddElement(int index, int value);

    //! \brief Вставляет элемент в начало массива.
    //! \param value Значение элемента.
    void InsertAtBeginning(int value);

    //! \brief Вставляет элемент в конец массива.
    //! \param value Значение элемента.
    void InsertAtEnd(int value);

    //! \brief Вставляет новый элемент после определенного элемента.
    //! \param targetValue Значение элемента, после которого выполняется вставка.
    //! \param newValue Значение нового элемента.
    //! \return true, если элемент найден и вставка выполнена; иначе false.
    bool InsertAfterElement(int targetValue, int newValue);

    //! \brief Удаляет элемент массива по передаваемому индексу.
    //! \param index Индекс элемента, который нужно удалить.
    //! \return true, если удаление выполнено успешно; иначе false.
    bool RemoveByIndex(int index);

    //! \brief Удаляет элемент по его передаваемому значению.
    //! \param value Посылаемое значение, которое нужно удалить.
    //! \return true, если элемент найден и удален; иначе false.
    bool RemoveByValue(int value);

    //! \brief Сортирует массив (Вариант 3: Сортировка вставками).
    void SortArray();

    //! \brief Линейный поиск индекса элемента по передаваемому значению.
    //! \param value Значение, индекс которого нужно найти.
    //! \return Индекс найденного элемента или -1, если элемент не найден.
    int LinearSearch(int value) const;

    //! \brief Бинарный поиск индекса элемента по передаваемому значению.
    //! \param value Значение, индекс которого нужно найти.
    //! \return Индекс найденного элемента или -1, если элемент не найден.
    int BinarySearch(int value) const;

    //! \brief Проверяет, отсортирован ли массив по возрастанию.
    //! \return true, если массив отсортирован; иначе false.
    bool IsSorted() const;
};