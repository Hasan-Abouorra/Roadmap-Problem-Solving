#include <iostream>
#include <vector>
using namespace std;

//c++2
int ReadPositiveNumber(string message = "Please enter a positive number ? ")
{
    int number = 0;
    do
    {
        cout << message << "\n";
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (number <= 0);

    return number;
}
 //30
struct stEmployee
{
    string Name;
    int Salary;
};

void FillEmployees(vector<stEmployee> &Employees)
{
    stEmployee Employee;
    char Answer = 'y';
    do
    {
        cout << "Enter Name: ";
        cin >> Employee.Name;
        //remove
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "\nEnter Salary: ";
        cin >> Employee.Salary; //= ReadPositiveNumber("");
        Employees.push_back(Employee);
        cout << "\nDo you to enter more Employees? ";
        cin >> Answer;
        cout << "\n";
    } while (Answer == 'Y' || Answer == 'y');
}
void PrintEmployees(vector<stEmployee> &Employees)
{
    short count = 1;
    for (const stEmployee &Employee : Employees)
    {
        cout << count++ << "- Name: " << Employee.Name << ", Salary: " << Employee.Salary << "\n";
    }
    cout << "\n";
}

int main()
{
    vector<stEmployee> Employees;
    FillEmployees(Employees);
    PrintEmployees(Employees);
    return 0;
}