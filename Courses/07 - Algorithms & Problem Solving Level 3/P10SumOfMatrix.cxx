#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>
#include <iomanip>
#include <cstdio>

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


int SumOfMatrix(int Matrix1[100][100], short Rows, short Cols)
{
    int Sum = 0;

    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
        {
            Sum += Matrix1[i][j];
        }

    return Sum;
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[100][100];

    short Rows = 3, Cols = 3;
    Fill3xArrayWithRandomElements(Matrix1, Rows, Cols);
    Print3xArray(Matrix1, Rows, Cols);

    cout << "-------------\n";
    int Matrix2[100][100];
    Fill3xArrayWithRandomElements(Matrix2, Rows, Cols);
    Print3xArray(Matrix2, Rows, Cols);

    cout << "-------------\n";

    int MatrixResults[100][100];
    MultiplyMatrix(Matrix1, Matrix2, MatrixResults, Rows, Cols);
    Print3xArray(MatrixResults, Rows, Cols);

    

    return 0;
}

