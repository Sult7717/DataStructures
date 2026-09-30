#include <iostream>
#include <string>

using namespace std;

//! \brief Структура, описывающая человека.
//! \details Хранит базовую информацию: имя, фамилию и возраст.
struct Person
{
    //! Имя человека.
    string FirstName;

    //! Фамилия человека.
    string LastName;

    //! Возраст человека.
    unsigned Age;
};

// Количество людей в массиве, заданное в методичке
const int PeopleCount = 5;

//! \brief Выводит в консоль данные о человеке.
//! \param person Ссылка на неизменяемый объект структуры Person.
void WritePerson(const Person& person)
{
    cout << "First Name: " + person.FirstName
        + "; Last Name: " + person.LastName
        + "; Age: " + to_string(person.Age)
        << endl;
}

//! \brief Очищает из памяти один объект человека.
//! \param person Указатель на удаляемый объект Person.
void ClearPerson(Person* person)
{
    delete person;
}

//! \brief Очищает массив указателей на объекты людей в динамической памятью.
//! \param people Двойной указатель на динамический массив структур.
//! \param itemsCount Количество элементов в массиве.
void ClearPeople(Person** people, int itemsCount)
{
    for (int i = 0; i < itemsCount; i++)
    {
        ClearPerson(people[i]);
    }

    delete[] people;
}

//! \brief Создает и заполняет тестовый массив объектов структуры Person в куче.
//! \return Двойной указатель на созданный массив указателей.
Person** CreatePeopleArray()
{
    Person** people = new Person * [PeopleCount];

    people[0] = new Person();
    people[0]->FirstName = "Casey";
    people[0]->LastName = "Aguilar";
    people[0]->Age = 30;

    people[1] = new Person();
    people[1]->FirstName = "Brock";
    people[1]->LastName = "Curtis";
    people[1]->Age = 19;

    people[2] = new Person();
    people[2]->FirstName = "Blake";
    people[2]->LastName = "Diaz";
    people[2]->Age = 21;

    people[3] = new Person();
    people[3]->FirstName = "Cristian";
    people[3]->LastName = "Evans";
    people[3]->Age = 55;

    people[4] = new Person();
    people[4]->FirstName = "Les";
    people[4]->LastName = "Foss";
    people[4]->Age = 4;

    return people;
}

//! \brief Задание 1. Выполняет линейный поиск человека в динамическом массиве по его фамилии.
void Task1_FindPersonByLastName()
{
    Person** people = CreatePeopleArray();
    string lastName;
    int foundIndex = -1;

    // Вывод исходного списка людей на экран
    for (int i = 0; i < PeopleCount; i++)
    {
        WritePerson(*people[i]);
    }

    cout << endl;
    cout << "Enter last name: ";
    cin >> lastName;

    // === РЕАЛИЗАЦИЯ ЛОГИКИ ЛИНЕЙНОГО ПОИСКА ===
    // Перебираем элементы массива и сравниваем поле LastName с искомой строкой
    for (int i = 0; i < PeopleCount; i++)
    {
        if (people[i]->LastName == lastName)
        {
            foundIndex = i;
            break; // Если нашли, прерываем цикл
        }
    }

    // Анализ результатов поиска
    if (foundIndex == -1)
    {
        cout << "Could not find a person by last name: " << lastName << endl;
    }
    else
    {
        cout << "A person's last name " << lastName
            << " was found. Its index in the array is " << foundIndex
            << endl;
    }

    // Освобождение выделенной памяти
    ClearPeople(people, PeopleCount);
}

int main()
{
    cout << "Task 1 - Find Person by Last Name" << endl;
    cout << "---------------------------------" << endl;

    Task1_FindPersonByLastName();

    return 0;
}
