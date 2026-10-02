#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string _firstName;

    string _lastName;

    unsigned _age;

public:
    void SetFirstName(string value) { _firstName = value; }
    string GetFirstName() const { return _firstName; }

    void SetLastName(string value) { _lastName = value; }
    string GetLastName() const { return _lastName; }

    void SetAge(unsigned value) { _age = value; }
    unsigned GetAge() const { return _age; }
};

const int PeopleCount = 5;

void WritePerson(const Person& person)
{
    cout << "First Name: " + person.GetFirstName()
        + "; Last Name: " + person.GetLastName()
        + "; Age: " + to_string(person.GetAge())
        << endl;
}

void ClearPerson(Person* person)
{
    delete person;
}

void ClearPeople(Person** people, int itemsCount)
{
    for (int i = 0; i < itemsCount; i++)
    {
        ClearPerson(people[i]);
    }

    delete[] people;
}

Person** CreatePeopleArray()
{
    Person** people = new Person * [PeopleCount];

    people[0] = new Person();
    people[0]->SetFirstName("Casey");
    people[0]->SetLastName("Aguilar");
    people[0]->SetAge(30);

    people[1] = new Person();
    people[1]->SetFirstName("Brock");
    people[1]->SetLastName("Curtis");
    people[1]->SetAge(19);

    people[2] = new Person();
    people[2]->SetFirstName("Blake");
    people[2]->SetLastName("Diaz");
    people[2]->SetAge(21);

    people[3] = new Person();
    people[3]->SetFirstName("Cristian");
    people[3]->SetLastName("Evans");
    people[3]->SetAge(55);

    people[4] = new Person();
    people[4]->SetFirstName("Les");
    people[4]->SetLastName("Foss");
    people[4]->SetAge(4);

    return people;
}

void Task1_FindPersonByLastName()
{
    Person** people = CreatePeopleArray();
    string lastName = "";
    int foundIndex = -1;

    for (int i = 0; i < PeopleCount; i++)
    {
        WritePerson(*people[i]);
    }

    cout << endl;
    cout << "Enter last name: ";
    cin >> lastName;

    for (int i = 0; i < PeopleCount; i++)
    {
        if (people[i]->GetLastName() == lastName)
        {
            foundIndex = i;
            break;
        }
    }

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

    ClearPeople(people, PeopleCount);
}

int main()
{
    Task1_FindPersonByLastName();
    return 0;
}
