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

void SearchNumberResult(int number, int array[100], int size)
{
    cout << "Number you are looking for is : " << number << "\n";
    int numberPosition = FindNumberPositionInArray(number, array, size);

    if (numberPosition > -1)
    {
        cout << "The number is found at position: " << numberPosition << "\n";
        cout << "The number found its order " << numberPosition + 1 << "\n";
    }
    else
        cout << "No, The number is not found :-( " << number << "\n";
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
    SearchNumberResult(search, array, size);

    return 0;
}