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



short RowSum(int array[100][100], short RowNumber, short Cols)
{
    short Sum = 0;
    for (int i = 0; i <= Cols; i++)
    {
        Sum += array[RowNumber][i];
    }
    return Sum;
}

void PrintEachRowSum(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        //array[i][0]+array[i][1]+array[i][2]

        cout << "Row " << i + 1 << " Sum = " << RowSum(array, i, Cols) << "\t";

        cout << "\n";
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int array[100][100];

    short Rows = 3, Cols = 3;
    Fill3xArrayWithRandomElements(array, Rows, Cols);
    Print3xArray(array, Rows, Cols);
    PrintEachRowSum(array, Rows, Cols);

    

    return 0;
}

