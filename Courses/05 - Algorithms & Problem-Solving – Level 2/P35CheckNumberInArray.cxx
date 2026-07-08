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

void FillArrayWithOrderd1ToNElements(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
}

int FindNumberPositionInArray(int number, int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (number == array[i])
            return i;
    }
    return -1;
}

bool IsNumberInArray(int number, int array[100], int size)
{
    return FindNumberPositionInArray(number, array, size) != -1;
}

void FoundNumberResult(int number, int array[100], int size)
{
    cout << "Number you are looking for is : " << number << "\n";

    if (!IsNumberInArray(number, array, size))
        cout << "No, The number is not found :-( \n";
    else
        cout << "Yes, The number is found :-)\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100];
    int size = ReadPositiveNumber();
    FillArrayWithRandomElements(array, size);

    cout << "Array elements: \n";
    PrintArray(array, size);

    int search = ReadPositiveNumber("Please enter a number to search for?");

    FoundNumberResult(search, array, size);

    return 0;
}