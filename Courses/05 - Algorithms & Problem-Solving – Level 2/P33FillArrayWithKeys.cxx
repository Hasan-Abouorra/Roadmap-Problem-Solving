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

void PrintArray(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void PrintStringArray(string array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i << "]: " << array[i] << "\n";
    }
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

string GenerateWord(enCharType ch, int numberOfLetters)
{
    string word = "";
    for (int i = 1; i <= numberOfLetters; i++)
    {
        word += GetRandomChar(ch);
    }
    return word;
}

string GenerateKey(int numberOfFields=4, int numberOfLetters=4)
{
    string key = "";
    int count = 0;
    for (int i = 1; i <= numberOfFields; i++)
    {
        count++;
        key += GenerateWord(enCharType::capitalLetter, numberOfLetters);
        if (count < numberOfFields)
            key += "-";
    }
    return key;
}



void FillArrayWithKeys(string array[100], int size, int numberOfFields)
{
     
    int numberOfLetters= numberOfFields;
    
    for (int i = 0; i < size; i++)
    {
        array[i] = GenerateKey(numberOfFields, numberOfLetters) ;
    }
}




int main()
{
    srand((unsigned)time(NULL));

    string array[100];
    int size = ReadPositiveNumber();
    FillArrayWithKeys(array,size,4);

    cout << "Array elements: \n";
    PrintStringArray(array, size);

    

    return 0;
}