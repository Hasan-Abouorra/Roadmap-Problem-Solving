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
            //cout << setw(3) << array[i][j] << "   ";
            // printf("%0*d   ", 2, array[i][j] );
            printf("%02d    ", array[i][j]);
        }
        cout << "\n";
    }
}


void MultiplyMatrix(int Matrix1[100][100], int Matrix2[100][100], int MatrixResults[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int array[100][100];

    short Rows = 3, Cols = 3;
    Fill3xArrayWithRandomElements(array, Rows, Cols);
    Print3xArray(array, Rows, Cols);
    
    cout << "-------------\n";

    int results[100][100];
    MultiplyMatrix(array, trans, results, Rows, Cols);
    Print3xArray(results, Rows, Cols);

    

    return 0;
}

