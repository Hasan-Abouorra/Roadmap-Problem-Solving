#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.

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

enum enCharType
{
    smallLetter = 1,
    capitalLetter,
    specialLetter,
    digit

};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomChar(enCharType ch)
{
    switch (ch)
    {
    case enCharType::smallLetter:
        return char(RandomNumber(97, 122));

    case enCharType::capitalLetter:
        return char(RandomNumber(65, 90));

    case enCharType::specialLetter:
        return char(RandomNumber(33, 38));
        break;

    case enCharType::digit:
        return char(RandomNumber(48, 57));
    }
}

void ReadArrayElements(int array[100], int size)
{
    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element[" << i+1 << "]: ";
        cin >> array[i];
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

int CountNumberInArray(int array[100], int size, int number)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == number)
            count++;
    }
    return count;
}

void CheckNumberInArray(int array[100], int size)
{
    int number = ReadPositiveNumber("Enter the number you want to check: ");
    cout << "Original array: ";
    PrintArray(array, size);
    cout << number << " is repeated " << CountNumberInArray(array, size, number) << " time(s)";
}
    
int main()n
{
    srand((unsigned)time(NULL));

    //cout<<rand()%10+10<<"\t"<<rand()%100+1<<"\n";
    int array[100];
    int size = ReadPositiveNumber();
    ReadArrayElements(array,size);
    CheckNumberInArray(array, size);

    return 0;
}