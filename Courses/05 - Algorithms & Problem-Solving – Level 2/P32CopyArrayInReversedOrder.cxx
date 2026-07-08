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

void FillArrayWithRandomElements(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = RandomNumber(1, 100);
    }
}

void CopyArrayInReversedOrder(int orginal[100], int copy[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        copy[size - 1 - i] = orginal[i];
        //or
        //copy[i] = orginal[size - 1 - i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100];
    int size = ReadPositiveNumber();

    FillArrayWithRandomElements(array, size);
    cout << "Array1 elements: \n";
    PrintArray(array, size);

    int copy[100];
    CopyArrayInReversedOrder(array, copy, size);
    cout << "Array 2 Elements: \n";
    PrintArray(copy, size);

    return 0;
}