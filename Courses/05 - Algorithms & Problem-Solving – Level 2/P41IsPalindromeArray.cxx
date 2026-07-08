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

void FillArrayWithRandomElements(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

bool IsPalindromeArray(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] != array[size - i - 1])
            return false;
    }
    return true;
}

void PrintArrayPalindromeResult(int array[100], int size)
{
    if (IsPalindromeArray(array, size))
        cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100] = {10, 20, 30, 90, 30, 20, 10};
    int size = 7;

    cout << "Array elements: \n";
    PrintArray(array, size);

    PrintArrayPalindromeResult(array, size);

    return 0;
}