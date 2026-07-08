#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>

using namespace std;

int ReadPositiveNumber(string message = "Please enter a positive number ? ")
{
    int number = 0;
    do
    {
        cout << message << "\n";
        cin >> number;
    } while (number <= 0);

    return number;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void PrintArray(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void AddArrayElement(int number, int array[100], int &size)
{
    array[++size-1] = number;
}

void InputUserNumberInArray(int array[100], int &size)
{
    bool addmore;
    do
    {
        AddArrayElement(ReadPositiveNumber("Please enter a number? "), array, size);
        cout << "Do you want to add more numbers?[0]:No,[1]:yes?\n ";
        cin >> addmore;}
        while (addmore);
    
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100];
    int size = 0;
    InputUserNumberInArray(array, size);

    cout << "Array Length: " << size << "\n";

    cout << "Array elements: \n";
    PrintArray(array, size);

    return 0;
}