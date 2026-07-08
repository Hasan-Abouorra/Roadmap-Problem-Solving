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

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

enPrimeNotPrime CheckPrime(int Number)
{
    int M = Number / 2;

    for (int Counter = 2; Counter <= M; Counter++)

    {
        if (Number % Counter == 0)

            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
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

void AddArrayElement(int number, int array[100], int &size)
{
    array[size++] = number;
}


void CopyPrimeNumbersUsingAddArrayElement(int orginal[100], int copy[100], int size, int &size2)
{
    for (int i = 0; i < size; i++)
    {
        if (CheckPrime(orginal[i]) == enPrimeNotPrime::Prime)
            AddArrayElement(orginal[i], copy, size2);
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

    int array2[100];
    int size2 = 0;

    CopyPrimeNumbersUsingAddArrayElement(array, array2, size, size2);

    cout << "Array2 Prime numbers: \n";
    PrintArray(array2, size2);

    return 0;
}    