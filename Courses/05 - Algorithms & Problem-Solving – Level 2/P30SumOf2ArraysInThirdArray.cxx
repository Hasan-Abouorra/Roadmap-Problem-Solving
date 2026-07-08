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

void SumOf2ArraysInThirdArray(int array[100], int array2[100], int array3[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        array3[i] = array[i] + array2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100];
    int size = ReadPositiveNumber();
    FillArrayWithRandomElements(array, size);
    cout << "Array Elements: \n";
    PrintArray(array, size);

    int array2[100];
    FillArrayWithRandomElements(array2, size);
    cout << "Array 2 Elements: \n";
    PrintArray(array2, size);

    int array3[100];
    SumOf2ArraysInThirdArray(array, array2, array3, size);
    cout << " Sum of array1 and array2 elements: \n";
    PrintArray(array3, size);

    return 0;
}