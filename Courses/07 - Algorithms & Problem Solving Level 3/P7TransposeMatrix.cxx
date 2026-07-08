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

void Fill3xArrayWithOrderedElements(int array[100][100], short Rows, short Cols)
{
    short start = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            array[i][j] = ++start;
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

void Tranpose3xArrayWithOrderedElements(int array[100][100], int trans[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            //trans[j][i] = array[i][j];
            trans[i][j] = array[j][i];
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int array[100][100];

    short Rows = 3, Cols = 3;
    Fill3xArrayWithOrderedElements(array, Rows, Cols);
    Print3xArray(array, Rows, Cols);


    cout << "-------------\n";
    int trans[100][100];
    Tranpose3xArrayWithOrderedElements(array, trans, Rows, Cols);
    Print3xArray(trans, Rows, Cols);

    

    return 0;
}

