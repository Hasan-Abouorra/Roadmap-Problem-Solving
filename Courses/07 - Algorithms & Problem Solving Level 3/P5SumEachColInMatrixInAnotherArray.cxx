#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>
#include <iomanip>
#include <cstdio>
//BreakPoints,  StepInOutOver, AutosWindow, Quick Watch Window, Changing Values while Debugging
// Library through Header Files.h, Pragma Once, namespaces
// Ternary Operator/Short Hand IF ?:, nested
//Ranged Loop for :, Set{}, int array[]={,,,}

//struct pints
//
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill3xArrayWithRandomElements(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            array[i][j] = RandomNumber(1, 100);
        }
    }
}



void Print3xArray(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << array[i][j] << "   ";
            
        }
        cout << "\n";
    }
}




short ColSum(int array[100][100], short Rows, short ColNumber)
{
    short Sum = 0;
    for (int i = 0; i <= Rows; i++)
    {
        Sum += array[i][ColNumber];
    }
    return Sum;
}

void PrintEachColSum(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Cols; i++)
    {
        //array[i][0]+array[i][1]+array[i][2]

        cout << "Col " << i + 1 << " Sum = " << ColSum(array, Rows, i) << "\t";

        cout << "\n";
    }
}

short ColSumArray(int array[100][100], int sumArray[100], short Rows, short Cols)
{
    for (int i = 0; i < Cols; i++)
    {
        sumArray[i] = ColSum(array, Rows, i);
    }
}

void PrintColSumArray(int array[100], short Cols)
{
    for (int i = 0; i < Cols; i++)
    {
        //array[i][0]+array[i][1]+array[i][2]

        cout << "Col " << i + 1 << " Sum = " << array[i] << "\t";

        cout << "\n";
    }
}

void PrintArray(int array[100], short Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}


int main()
{
    srand((unsigned)time(NULL));

    int array[100][100];

    short Rows = 3, Cols = 3;
    Fill3xArrayWithRandomElements(array, Rows, Cols);
    Print3xArray(array, Rows, Cols);

    PrintEachColSum(array, Rows, Cols);

    cout << "-------------\n";
    int sumColArray[100];

    ColSumArray(array, sumColArray, Rows, Cols);
    PrintColSumArray(sumColArray, Cols);

    PrintArray(sumColArray, Cols);

    

    return 0;
}

