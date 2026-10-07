#include <iostream>
#include <string>

using namespace std;

//! \brief Класс, описывающий человека.
/**
* Хранит имя, фамилию и возраст человека. Доступ к данным осуществляется
* через методы Get и Set.
*/
class Person
{
private:
    //! Имя человека.
    string _firstName;

    //! Фамилия человека.
    string _lastName;

    //! Возраст человека.
    unsigned _age = 0;

public:
    //! \brief Устанавливает имя человека.
    //! \param value – новое имя.
    void SetFirstName(string value)
    {
        _firstName = value;
    }

    //! \brief Возвращает имя человека.
    //! \return Имя человека.
    string GetFirstName() const
    {
        return _firstName;
    }

    //! \brief Устанавливает фамилию человека.
    //! \param value – новая фамилия.
    void SetLastName(string value)
    {
        _lastName = value;
    }

    //! \brief Возвращает фамилию человека.
    //! \return Фамилия человека.
    string GetLastName() const
    {
        return _lastName;
    }

    //! \brief Устанавливает возраст человека.
    //! \param value – новый возраст.
    void SetAge(unsigned value)
    {
        _age = value;
    }

    //! \brief Возвращает возраст человека.
    //! \return Возраст человека.
    unsigned GetAge() const
    {
        return _age;
    }
};

//! \brief Количество людей в массиве.
const int PeopleCount = 5;

//! \brief Значение индекса, возвращаемое при неудачном поиске.
const int NotFoundIndex = -1;

//! \brief Выводит в консоль данные о человеке.
//! \param person – данные о человеке \see Person.
void WritePerson(const Person& person)
{
    cout << "First Name: " + person.GetFirstName()
        + "; Last Name: " + person.GetLastName()
        + "; Age: " + to_string(person.GetAge())
        << endl;
}

//! \brief Создает в динамической памяти объект человека.
//! \param firstName – имя человека.
//! \param lastName – фамилия человека.
//! \param age – возраст человека.
//! \return Указатель на созданный объект \see Person.
Person* CreatePerson(const string& firstName, const string& lastName, unsigned age)
{
    Person* person = new Person();
    person->SetFirstName(firstName);
    person->SetLastName(lastName);
    person->SetAge(age);

    return person;
}

//! \brief Очищает из памяти объект человека \see Person.
//! \param person – объект человека \see Person.
void ClearPerson(Person* person)
{
    delete person;
}

//! \brief Очищает массив указателей на людей в динамической памяти \see Person.
//! \param people – массив указателей на объекты людей.
//! \param itemsCount – количество элементов в массиве.
void ClearPeople(Person** people, int itemsCount)
{
    for (int i = 0; i < itemsCount; ++i)
    {
        ClearPerson(people[i]);
    }

    delete[] people;
}

//! \brief Создает массив указателей на людей.
//! \return Массив из PeopleCount указателей на объекты \see Person.
Person** CreatePeopleArray()
{
    Person** people = new Person*[PeopleCount];

    people[0] = CreatePerson("Casey", "Aguilar", 30);
    people[1] = CreatePerson("Brock", "Curtis", 19);
    people[2] = CreatePerson("Blake", "Diaz", 21);
    people[3] = CreatePerson("Cristian", "Evans", 55);
    people[4] = CreatePerson("Les", "Foss", 4);

    return people;
}

//! \brief Ищет человека по фамилии (линейный поиск).
//! \param people – массив указателей на объекты людей.
//! \param itemsCount – количество элементов в массиве.
//! \param lastName – искомая фамилия.
//! \return Индекс первого найденного человека или NotFoundIndex, если его нет.
int FindPersonIndexByLastName(Person** people, int itemsCount, const string& lastName)
{
    for (int i = 0; i < itemsCount; ++i)
    {
        if (people[i]->GetLastName() == lastName)
        {
            return i;
        }
    }

    return NotFoundIndex;
}

//! \brief Задание 1. Поиск человека по фамилии.
void Task1_FindPersonByLastName()
{
    Person** people = CreatePeopleArray();

    for (int i = 0; i < PeopleCount; ++i)
    {
        WritePerson(*people[i]);
    }

    string lastName = "";
    cout << "Enter last name: ";
    cin >> lastName;

    int foundIndex = FindPersonIndexByLastName(people, PeopleCount, lastName);

    if (foundIndex == NotFoundIndex)
    {
        cout << "Could not find a person by last name: " << lastName << endl;
    }
    else
    {
        cout << "A person's last name " << lastName
            << " was found. Its index in the array is "
            << foundIndex << endl;
    }

    ClearPeople(people, PeopleCount);
}

//! \brief Точка входа в программу.
//! \return Код завершения программы (0 – успешное завершение).
int main()
{
    cout << "Task 1 - Find Person by Last Name" << endl;
    Task1_FindPersonByLastName();

    return 0;
}
